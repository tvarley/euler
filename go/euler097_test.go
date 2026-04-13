package main

import "testing"

func TestEuler097(t *testing.T) {
	expected := 8739992577
	if result := largeNonMersennePrime(); result != expected {
		t.Errorf("largeNonMersennePrime() = %d; want %d", result, expected)
	}
}