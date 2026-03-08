package euler

import "testing"

func TestSumMultiples(t *testing.T) {
	tests := []struct {
		limit int
		want  int
	}{
		{10, 23},
		{1000, 233168},
	}
	for _, tt := range tests {
		if got := SumMultiples(tt.limit); got != tt.want {
			t.Errorf("SumMultiples(%d) = %d; want %d", tt.limit, got, tt.want)
		}
	}
}