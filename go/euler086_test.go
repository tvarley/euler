package main

import "testing"

func TestEuler086(t *testing.T) {
	expected := 1818
	if result := cuboidRoute(); result != expected {
		t.Errorf("cuboidRoute() = %d; want %d", result, expected)
	}
}