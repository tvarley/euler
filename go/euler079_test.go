package main

import "testing"

func TestEuler079(t *testing.T) {
	expected := "73162890"
	if result := passcodeDerivation(); result != expected {
		t.Errorf("passcodeDerivation() = %s; want %s", result, expected)
	}
}