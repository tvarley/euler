package main

import "testing"

func TestEuler092(t *testing.T) {
	expected := 8581146
	if result := squareDigitChains(); result != expected {
		t.Errorf("squareDigitChains() = %d; want %d", result, expected)
	}
}