package main

import "testing"

func TestEuler088(t *testing.T) {
	expected := 7587457
	if result := productSumNumbers(); result != expected {
		t.Errorf("productSumNumbers() = %d; want %d", result, expected)
	}
}