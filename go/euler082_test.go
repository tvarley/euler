package main

import "testing"

func TestEuler082(t *testing.T) {
	expected := 260324
	if result := pathSumThreeWays(); result != expected {
		t.Errorf("pathSumThreeWays() = %d; want %d", result, expected)
	}
}