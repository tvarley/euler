package main

import "testing"

func TestEuler098(t *testing.T) {
	expected := 18769
	if result := anagramicSquares(); result != expected {
		t.Errorf("anagramicSquares() = %d; want %d", result, expected)
	}
}