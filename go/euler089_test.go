package main

import "testing"

func TestEuler089(t *testing.T) {
	expected := 743
	if result := romanNumerals(); result != expected {
		t.Errorf("romanNumerals() = %d; want %d", result, expected)
	}
}