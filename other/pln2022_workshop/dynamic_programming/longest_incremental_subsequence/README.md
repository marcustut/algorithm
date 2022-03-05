# Longest Increasing Subsequence (LIS)

## Introduction

4, 6, 1, 2, 6, 2, 8, 5, 2, 6
      ^  ^           ^     ^

subsequence: 4, 6, 1, 2
increasing subsequence: 1, 2, 5, 6
longest increasing subsequence: 1, 2, 5, 6

## Solution

### Brute Force

Check for all possible combinations (or substeps), record the length and get the longest one.

### Recursive Backtracking

**Example**:
4, 6, 1, 2, 6, 2, 8, 5, 2, 6
      ^  ^           ^     ^

4, 6
4, 6
4, 8
4, 5
4, 6

assume we have a function LIS(i) that returns the longest increasing subsequence that ends with the element of index i.

Let the original sequence be a[0], a[1], ..., a[n], we can have a nice recurrece relation that brute force over all the subsequence.

`LIS(i) = 1 + max(0, LIS(k)) for a[k] < a[i] and k < i and i > 0`


