const std = @import("std");

pub fn addInputsOption(b: *std.Build, exe: anytype, target: anytype, optimize: anytype) !void {
    var options = b.addOptions();

    var files = std.array_list.Managed([]const u8).init(b.allocator);
    defer files.deinit();

    var buf: [std.fs.max_path_bytes]u8 = undefined;
    const path = try std.fs.cwd().realpath("src/inputs", buf[0..]);

    var dir = try std.fs.openDirAbsolute(path, .{ .iterate = true });
    var it = dir.iterate();
    while (try it.next()) |file| {
        if (file.kind != .file) {
            continue;
        }
        try files.append(b.dupe(file.name));
    }
    options.addOption([]const []const u8, "files", files.items);
    exe.step.dependOn(&options.step);

    const inputs = b.addModule("inputs", .{
        .root_source_file = options.getOutput(),
        .target = target,
        .optimize = optimize,
    });

    exe.root_module.addImport("inputs", inputs);
}

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    // Library
    const mod = b.addModule("aoc2025", .{
        .root_source_file = b.path("src/root.zig"),
        .target = target,
    });

    // Executables
    const day1 = b.addExecutable(.{
        .name = "day1",
        .root_module = b.createModule(.{
            .root_source_file = b.path("src/day1.zig"),
            .target = target,
            .optimize = optimize,
            .imports = &.{
                .{ .name = "aoc2025", .module = mod }, // use aoc2025 as library
            },
        }),
    });
    addInputsOption(b, day1, target, optimize) catch |err| {
        std.log.err("Failed to add inputs option: {any}\n", .{err});
    };
    b.installArtifact(day1);

    // Tests definition
    const mod_tests = b.addTest(.{
        .root_module = mod,
    });
    const run_mod_tests = b.addRunArtifact(mod_tests);
    const day1_tests = b.addTest(.{
        .root_module = day1.root_module,
    });
    const run_day1_tests = b.addRunArtifact(day1_tests);
    const test_step = b.step("test", "Run tests");
    test_step.dependOn(&run_mod_tests.step);
    test_step.dependOn(&run_day1_tests.step);
}
