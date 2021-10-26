import { assertEquals } from "https://deno.land/std@0.113.0/testing/asserts.ts";
import { binarySearch } from "./main.ts";

Deno.test("test empty array", () => {
  assertEquals(binarySearch([], 0), -1);
});

Deno.test("test one element array", () => {
  assertEquals(binarySearch([5], 5), 0);
  assertEquals(binarySearch([5], -5), -1);
});

Deno.test("test two element array", () => {
  assertEquals(binarySearch([2, 5], 5), 1);
});

Deno.test("test when target present", () => {
  assertEquals(binarySearch([-1, 0, 3, 5, 9, 12], 9), 4);
});

Deno.test("test when target not present", () => {
  assertEquals(binarySearch([-1, 0, 3, 5, 9, 12], 2), -1);
});

Deno.test("test unsorted array", () => {
  assertEquals(binarySearch([5, 2], 2), -1);
});
