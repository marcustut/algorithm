package main

import "testing"

func TestIsPalindrome(t *testing.T) {
  tcs := []struct{
    input, trash string
    expected bool
  }{
    {
      input: "a@b!!b$a",
      trash: "!@$",
      expected: true,
    },
    {
      input: "?Aa#c",
      trash: "#?",
      expected: true,
    },
  }

  for _, tc := range tcs {
    res := isPalindrome(tc.input, tc.trash)
    if res != tc.expected {
      t.Fatalf("isPalindrome(): expect '%s' with trash symbols of '%s' to be %v, but it is %v", tc.input, tc.trash, tc.expected, res)
    }
  }
}
