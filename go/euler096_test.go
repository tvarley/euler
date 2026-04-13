package main

import "testing"

func TestEuler096(t *testing.T) {
	expected := 24702
	if result := suDoku(); result != expected {
		t.Errorf("suDoku() = %d; want %d", result, expected)
	}
}