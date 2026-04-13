package main

import "testing"

func TestEuler090(t *testing.T) {
	expected := 1217
	if result := cubeDigitPairs(); result != expected {
		t.Errorf("cubeDigitPairs() = %d; want %d", result, expected)
	}
}