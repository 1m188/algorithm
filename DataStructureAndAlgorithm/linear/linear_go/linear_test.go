package lineargo

import "testing"

func testLinear(linear *ILinear[int], t *testing.T) {
	var li = *linear
	var err error

	for i := 0; i < 10; i++ {
		err = li.Append(&i)
		if err != nil {
			t.Fatal(err)
		}
	}
	if li.Length() != 10 {
		t.Fatal("length failed")
	}

	x := -1
	err = li.Insert(0, &x)
	if err != nil {
		t.Fatal(err)
	}
	if li.Length() != 11 {
		t.Fatal("length failed")
	}

	v, err := li.At(0)
	if err != nil {
		t.Fatal(err)
	}
	if *v != -1 {
		t.Fatal("at failed")
	}

	v, err = li.Remove(0)
	if err != nil {
		t.Fatal(err)
	}
	if *v != -1 {
		t.Fatal("remove failed")
	}
	if li.Length() != 10 {
		t.Fatal("length failed")
	}

	x = 9
	idx, err := li.IndexOf(&x)
	if err != nil {
		t.Fatal(err)
	}
	vv, err := li.At(idx)
	if err != nil {
		t.Fatal(err)
	}
	if *vv != x {
		t.Fatal("indexof failed")
	}

	x = 111
	err = li.Set(9, &x)
	if err != nil {
		t.Fatal(err)
	}
	idx, err = li.IndexOf(&x)
	if err != nil {
		t.Fatal(err)
	}
	vv, err = li.At(idx)
	if err != nil {
		t.Fatal(err)
	}
	if *vv != x {
		t.Fatal("indexof failed")
	}
}

func TestMain(t *testing.T) {
	var linearlist ILinear[int]
	linearlist = &LinearList[int]{}
	testLinear(&linearlist, t)
	linearlist = &LinearArray[int]{}
	testLinear(&linearlist, t)
}
