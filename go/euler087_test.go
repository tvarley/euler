package main

import "testing"

func TestEuler087(t *testing.T) {
	expected := 1097343
	if result := primePowerTriples(); result != expected {
		t.Errorf("primePowerTriples() = %d; want %d", result, expected)
	}
}