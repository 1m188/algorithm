package queen8

import "testing"

func TestQueenN(t *testing.T) {
	if QueenN(8) != 92 {
		t.Fatal("QueenN(8)!=92")
	}
}
