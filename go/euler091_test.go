package main

import "testing"

func TestEuler091(t *testing.T) {
	expected := 14234
	if result := rightTriangles(); result != expected {
		t.Errorf("rightTriangles() = %d; want %d", result, expected)
	}
}