package main

import "testing"

func TestEuler084(t *testing.T) {
	expected := "101524"
	if result := monopolyOdds(); result != expected {
		t.Errorf("monopolyOdds() = %s; want %s", result, expected)
	}
}