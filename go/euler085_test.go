package main

import "testing"

func TestEuler085(t *testing.T) {
	expected := 2772
	if result := countingRectangles(); result != expected {
		t.Errorf("countingRectangles() = %d; want %d", result, expected)
	}
}