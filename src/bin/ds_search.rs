/*
基于 Rust 的常用查找算法实现
*/

// 线性查找
fn linear_search<T: PartialEq>(arr: &[T], target: &T) -> Option<usize> {
    for i in 0..arr.len() {
        if arr[i] == *target {
            return Some(i);
        }
    }
    None
}

// 二分查找
fn bin_search<T: Ord>(arr: &[T], target: &T) -> Option<usize> {
    if arr.is_empty() {
        return None;
    }
    let mut left: usize = 0;
    let mut right: usize = arr.len() - 1;
    while left <= right {
        let mid = (left + right) / 2;
        if arr[mid] == *target {
            return Some(mid);
        } else if arr[mid] < *target {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    None
}

fn main() {
    // linear search
    let mut arr = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let mut x = linear_search(&arr, &1);
    assert!(x.is_some() && x.unwrap() == 0);
    x = linear_search(&arr, &10);
    assert!(x.is_some() && x.unwrap() == 9);
    x = linear_search(&arr, &5);
    assert!(x.is_some() && x.unwrap() == 4);

    arr = vec![1, 10, 2, 9, 3, 8, 4, 7, 5, 6];
    x = linear_search(&arr, &1);
    assert!(x.is_some() && x.unwrap() == 0);
    x = linear_search(&arr, &6);
    assert!(x.is_some() && x.unwrap() == 9);
    x = linear_search(&arr, &10);
    assert!(x.is_some() && x.unwrap() == 1);

    arr = vec![1, 1, 1, 1, 1, 2, 3, 4, 4, 4, 4, 4];
    x = linear_search(&arr, &1);
    assert!(x.is_some() && x.unwrap() == 0);
    x = linear_search(&arr, &4);
    assert!(x.is_some() && x.unwrap() == 7);

    arr = vec![1];
    x = linear_search(&arr, &1);
    assert!(x.is_some() && x.unwrap() == 0);
    x = linear_search(&arr, &2);
    assert!(x.is_none());

    arr = vec![];
    x = linear_search(&arr, &1);
    assert!(x.is_none());

    // binary search
    arr = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    x = bin_search(&arr, &1);
    assert!(x.is_some() && x.unwrap() == 0);
    x = bin_search(&arr, &10);
    assert!(x.is_some() && x.unwrap() == 9);
    x = bin_search(&arr, &7);
    assert!(x.is_some() && x.unwrap() == 6);

    arr = vec![];
    x = bin_search(&arr, &1);
    assert!(x.is_none());

    println!("All tests passed!")
}
