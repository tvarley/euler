package main

import "testing"

func TestEuler095(t *testing.T) {
	expected := 14316
	if result := amicableChains(); result != expected {
		t.Errorf("amicableChains() = %d; want %d", result, expected)
	}
}