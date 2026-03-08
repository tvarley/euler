package euler

import "testing"

func TestSumEvenFib(t *testing.T) {
	if got := SumEvenFib(4000000); got != 4613732 {
		t.Errorf("SumEvenFib(4000000) = %d; want 4613732", got)
	}
}