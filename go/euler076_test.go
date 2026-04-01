package main

import "testing"

func TestEuler076(t *testing.T) {
	expected := 190569291
	if result := countingSummations(); result != expected {
		t.Errorf("countingSummations() = %d; want %d", result, expected)
	}
}