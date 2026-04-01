package main

import "testing"

func TestEuler099(t *testing.T) {
	expected := 709
	if result := largestExponential(); result != expected {
		t.Errorf("largestExponential() = %d; want %d", result, expected)
	}
}