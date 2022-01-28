package main

import (
	"strings"
)

// '1','2','3','4' (at least 3)
//
// input: "a!@#b!@#@!#c@!#!a"
// trash: "!@#"
// result: false

// '1','2','3','4' (at least 3)
//
// input: "4411!@#332!@#22!@#233114#@!4"
// trash: "!@#"
// result: true

func isPalindrome(input, trash string) bool {
	left := 0
	right := len(input) - 1
        charCount := map[byte]int{
          '1': 0,
          '2': 0,
          '3': 0,
          '4': 0,
        }

	for left >= 0 && right < len(input) && left < right {
		for strings.Contains(trash, string(input[left])) {
			left++
		}
		for strings.Contains(trash, string(input[right])) {
			right--
		}
                if _, ok := charCount[input[left]]; ok {
                  charCount[input[left]] += 1
                }
                if _, ok := charCount[input[right]]; ok {
                  charCount[input[right]] += 1
                }
		if strings.ToLower(string(input[left])) != strings.ToLower(string(input[right])) {
			return false
		}
		left++
		right--
	}

	return charCount['1'] > 3 && charCount['2'] > 3 && charCount['3'] > 3 && charCount['4'] > 3
}

