package main

import "testing"

func TestEuler100(t *testing.T) {
	expected := 756872327473
	if result := arrangedProbability(); result != expected {
		t.Errorf("arrangedProbability() = %d; want %d", result, expected)
	}
}