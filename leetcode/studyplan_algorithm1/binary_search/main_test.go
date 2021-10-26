package studyplan_algorithm1

import (
	"testing"
)

type binarySearchTestCase struct {
	arr    []int
	target int
}

func TestBinarySearch(t *testing.T) {
	testcases := []struct {
		name     string
		input    binarySearchTestCase
		expected int
	}{
		{
			name:     "test empty array",
			input:    binarySearchTestCase{arr: []int{}, target: 0},
			expected: -1,
		},
		{
			name:     "test one element array valid",
			input:    binarySearchTestCase{arr: []int{5}, target: 5},
			expected: 0,
		},
		{
			name:     "test one element array invalid",
			input:    binarySearchTestCase{arr: []int{5}, target: -5},
			expected: -1,
		},
		{
			name:     "test two element array",
			input:    binarySearchTestCase{arr: []int{2, 5}, target: 5},
			expected: 1,
		},
		{
			name:     "test when target present",
			input:    binarySearchTestCase{arr: []int{-1, 0, 3, 5, 9, 12}, target: 9},
			expected: 4,
		},
		{
			name:     "test when target not present",
			input:    binarySearchTestCase{arr: []int{-1, 0, 3, 5, 9, 12}, target: 2},
			expected: -1,
		},
		{
			name:     "test unsorted array",
			input:    binarySearchTestCase{arr: []int{5, 2}, target: 2},
			expected: -1,
		},
	}

	for _, testcase := range testcases {
		res := binarySearch(testcase.input.arr, testcase.input.target)
		if res != testcase.expected {
			t.Errorf("%s:  expected %d, got %d ❌", testcase.name, testcase.expected, res)
		} else {
			t.Logf("%s: expected %d, got %d ✅", testcase.name, testcase.expected, res)
		}
	}
}
