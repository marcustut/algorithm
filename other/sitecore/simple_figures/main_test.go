package main

import (
	"bytes"
	"log"
	"os"
	"strings"
	"testing"
)

func captureOutput(f func()) string {
	var buf bytes.Buffer
	log.SetOutput(&buf)
	f()
	log.SetOutput(os.Stderr)
	return buf.String()
}

func TestAggregation(t *testing.T) {
	a := Aggregation{
		[]Figure{&Point{}, &Line{}, &Circle{}},
	}

	output := captureOutput(func() {
		a.Move()
	})

	if strings.Count(output, "\n") != 3 {
		t.Fatalf(`Move() for Aggregation does not trigger for all its figures`)
	}
}
