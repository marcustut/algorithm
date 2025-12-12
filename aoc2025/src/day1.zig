const std = @import("std");
const aoc2025 = @import("aoc2025");

const Direction = enum {
    left,
    right,

    pub fn sign(self: Direction) i32 {
        return switch (self) {
            .left => -1,
            .right => 1,
        };
    }
};

fn parse_int(input: []const u8, len: u8) u16 {
    var num: u16 = 0;
    var dp: u16 = 1;
    var i = len;
    while (i > 0) {
        num += (input[i - 1] - '0') * dp;
        dp *= 10;
        i -= 1;
    }
    return num;
}

fn solve1(input: []const u8) u64 {
    var ans: u64 = 0;

    var loc: i32 = 50;
    var direction: Direction = undefined;
    var nums = [_]u8{0} ** 16;
    var nums_i: u8 = 0;
    for (input) |byte| {
        switch (byte) {
            '\n' => {
                // std.debug.print("{d} -> ", .{loc});
                loc = @mod(loc + direction.sign() * @as(i32, parse_int(&nums, nums_i)), 100);
                // std.debug.print("{c}{d} -> {d}\n", .{ @as(u8, if (direction == Direction.left) 'L' else 'R'), magnitude, loc });

                if (loc == 0) ans += 1;
                direction = undefined;
                nums_i = 0;
            },
            'L' => direction = Direction.left,
            'R' => direction = Direction.right,
            '0'...'9' => {
                nums[nums_i] = byte;
                nums_i += 1;
            },
            else => {
                std.log.err("Unexpected byte: {c}\n", .{byte});
            },
        }
    }

    return ans;
}

fn solve2(input: []const u8) u64 {
    var ans: u64 = 0;

    var loc: i32 = 50;
    var direction: Direction = undefined;
    var nums = [_]u8{0} ** 16;
    var nums_i: u8 = 0;
    for (input) |byte| {
        switch (byte) {
            '\n' => {
                // std.debug.print("{d} -> ", .{loc});
                loc = @mod(loc + direction.sign() * @as(i32, parse_int(&nums, nums_i)), 100);
                // std.debug.print("{c}{d} -> {d}\n", .{ @as(u8, if (direction == Direction.left) 'L' else 'R'), magnitude, loc });

                if (loc == 0) ans += 1;
                direction = undefined;
                nums_i = 0;
            },
            'L' => direction = Direction.left,
            'R' => direction = Direction.right,
            '0'...'9' => {
                nums[nums_i] = byte;
                nums_i += 1;
            },
            else => {
                std.log.err("Unexpected byte: {c}\n", .{byte});
            },
        }
    }

    return ans;
}

pub fn main() !void {
    const input = @embedFile("inputs/day1_1.txt");
    const ans = solve1(input);
    std.debug.print("answer is {d}", .{ans});
}

test "part one" {
    try std.testing.expectEqual(3, solve1(@embedFile("inputs/day1_1_sample.txt")));
    try std.testing.expectEqual(997, solve1(@embedFile("inputs/day1_1.txt")));
}

test "part two" {
    try std.testing.expectEqual(6, solve2(@embedFile("inputs/day1_2_sample.txt")));
    // try std.testing.expectEqual(solve1(@embedFile("inputs/day1_1.txt")), 997);
}
