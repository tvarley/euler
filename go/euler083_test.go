package main

import "testing"

func TestEuler083(t *testing.T) {
	expected := 425185
	if result := pathSumFourWays(); result != expected {
		t.Errorf("pathSumFourWays() = %d; want %d", result, expected)
	}
}