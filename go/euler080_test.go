package main

import "testing"

func TestEuler080(t *testing.T) {
	expected := 40886
	if result := squareRootDigitalExpansion(); result != expected {
		t.Errorf("squareRootDigitalExpansion() = %d; want %d", result, expected)
	}
}