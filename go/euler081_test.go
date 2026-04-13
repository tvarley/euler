package main

import "testing"

func TestEuler081(t *testing.T) {
	expected := 427337
	if result := pathSumTwoWays(); result != expected {
		t.Errorf("pathSumTwoWays() = %d; want %d", result, expected)
	}
}