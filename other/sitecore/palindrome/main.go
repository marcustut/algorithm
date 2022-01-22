package main

import (
	"strings"
)

func isPalindrome(input, trash string) bool {
	left := 0
	right := len(input) - 1

	for left >= 0 && right < len(input) && left < right {
		for strings.Contains(trash, string(input[left])) {
			left++
		}
		for strings.Contains(trash, string(input[right])) {
			right--
		}
		if input[left] != input[right] {
			return false
		}
		left++
		right--
	}

	return true
}
