package main

import "testing"

func TestEuler093(t *testing.T) {
	expected := 1258
	if result := arithmeticExpressions(); result != expected {
		t.Errorf("arithmeticExpressions() = %d; want %d", result, expected)
	}
}