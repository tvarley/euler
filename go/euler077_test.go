package main

import "testing"

func TestEuler077(t *testing.T) {
	expected := 71
	if result := primeSummations(); result != expected {
		t.Errorf("primeSummations() = %d; want %d", result, expected)
	}
}