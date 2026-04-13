package main

import "testing"

func TestEuler078(t *testing.T) {
	expected := 55374
	if result := coinPartitions(); result != expected {
		t.Errorf("coinPartitions() = %d; want %d", result, expected)
	}
}