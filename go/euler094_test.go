package main

import "testing"

func TestEuler094(t *testing.T) {
	expected := 518408346
	if result := almostEquilateral(); result != expected {
		t.Errorf("almostEquilateral() = %d; want %d", result, expected)
	}
}