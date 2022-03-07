package main

import "fmt"

// ProcessStringsInput is the input to the ProcessStrings function.
type ProcessStringsInput struct {
  First, Second *string
}

// ProcessStringsOutput is the output of the ProcessStrings function.
type ProcessStringsOutput struct {
  Anagram bool
  Length int
  First string
}

// ProcessStrings takes two string and process it.
func ProcessStrings(input ProcessStringsInput) (*ProcessStringsOutput, error) {
  // make sure input are valid
  if input.First == nil || input.Second == nil {
    return nil, fmt.Errorf("[required param is missing]: First, Second")
  }

  // the output of the function
  var output ProcessStringsOutput

  // hashmap for keep track of char frequency
  frequency := make(map[rune]int)

  // get the char frequency of first string
  for _, c := range *input.First {
    frequency[c] += 1
  }

  // form the first string without duplicated character
  for char, _ := range frequency {
    output.First += string(char)
  }

  // deduct the char frequency of second string
  for _, c := range *input.Second {
    frequency[c] -= 1
  }

  // check if char frequency of second string matches
  output.Anagram = true
  for _, freq := range frequency {
    if freq != 0 {
      output.Anagram = false
    }
  }

  // add the length both string
  output.Length = len(*input.First + *input.Second)

  return &output, nil
}

// String returns a reference to a given string.
func String(str string) *string {
  return &str
}

