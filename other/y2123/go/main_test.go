package main

import (
	"log"
	"strings"
	"testing"
)

func TestProcessStrings(t *testing.T) {
  tcs := []struct {
    input ProcessStringsInput
    output ProcessStringsOutput
  }{
    {
      input: ProcessStringsInput{First: String("anagram"), Second: String("nagaram")},
      output: ProcessStringsOutput{Anagram: true, Length: 14, First: "nagrm"},
    },
    {
      input: ProcessStringsInput{First: String("angel"), Second: String("leava")},
      output: ProcessStringsOutput{Anagram: false, Length: 10, First: "angel"},
    },
    {
      input: ProcessStringsInput{First: String("car"), Second: String("car")},
      output: ProcessStringsOutput{Anagram: true, Length: 6, First: "car"},
    },
  }

  for _, tc := range tcs {
    res, err := ProcessStrings(tc.input)
    if err != nil {
      log.Fatalf("[error processing string]: %v", err)
    }

    if res.Length != tc.output.Length {
      t.Fatalf("[ProcessStrings]: expect length of '%s' and '%s' to be %v, but it is %v", *tc.input.First, *tc.input.Second, tc.output.Length, res.Length)
    } else if res.Anagram != tc.output.Anagram {
      t.Fatalf("[ProcessStrings]: expect '%s' and '%s' to be %v anagram, but it is %v", *tc.input.First, *tc.input.Second, tc.output.Anagram, res.Anagram)
    }

    // test if every character only appears once
    for _, c := range tc.output.First {
      if strings.Count(res.First, string(c)) != 1 {
        t.Fatalf("[ProcessStrings]: expect '%s' and '%s' to be '%v', but it is '%v'", *tc.input.First, *tc.input.Second, tc.output.First, res.First)
      }
    }
  }
}
