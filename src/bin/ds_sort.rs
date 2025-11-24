/*
基于 Rust 的排序算法实现
*/

fn insert_sort<T: Ord>(vec: &mut [T]) {
    for i in 1..vec.len() {
        let mut j = i;
        while j > 0 && vec[j] < vec[j - 1] {
            vec.swap(j, j - 1);
            j -= 1;
        }
    }
}
fn shell_sort<T: Ord>(vec: &mut [T]) {
    let mut gap = vec.len() / 2;
    while gap > 0 {
        for i in (gap..vec.len()).step_by(gap) {
            let mut j = i;
            while j > 0 && vec[j] < vec[j - gap] {
                vec.swap(j, j - gap);
                j -= gap;
            }
        }
        gap /= 2;
    }
}
fn select_sort<T: Ord>(vec: &mut [T]) {
    for i in 0..vec.len() {
        let mut min_index = i;
        for j in i + 1..vec.len() {
            if vec[j] < vec[min_index] {
                min_index = j;
            }
        }
        vec.swap(i, min_index);
    }
}
fn bubble_sort<T: Ord>(vec: &mut [T]) {
    for i in (0..vec.len()).rev() {
        let mut f = false;
        for j in 0..i {
            if vec[j] > vec[j + 1] {
                vec.swap(j, j + 1);
                f = true;
            }
        }
        if !f {
            break;
        }
    }
}
fn quick_sort<T: Ord>(vec: &mut [T]) {
    mod local {
        pub fn quick_sort<T: Ord>(vec: &mut [T], start: usize, end: usize) {
            if start >= end {
                return;
            }
            let mut pivot_index = start;
            let mut left = start;
            let mut right = end;
            while left < right {
                while left < right && vec[right] >= vec[pivot_index] {
                    right -= 1;
                }
                if left < right {
                    vec.swap(pivot_index, right);
                    pivot_index = right;
                }
                while left < right && vec[left] <= vec[pivot_index] {
                    left += 1;
                }
                if left < right {
                    vec.swap(pivot_index, left);
                    pivot_index = left;
                }
            }
            if pivot_index > start {
                quick_sort(vec, start, pivot_index - 1);
            }
            if pivot_index < end {
                quick_sort(vec, pivot_index + 1, end);
            }
        }
    }

    if vec.is_empty() {
        return;
    }
    local::quick_sort(vec, 0, vec.len() - 1);
}
fn merge_sort<T: Ord + Default + Clone>(vec: &mut [T]) {
    mod local {
        pub fn merge<T: Ord + Default + Clone>(
            vec: &mut [T],
            start: usize,
            mid: usize,
            end: usize,
        ) {
            if start >= end {
                return;
            }
            let mut temp = (0..end - start + 1)
                .map(|_| T::default())
                .collect::<Vec<T>>();
            let mut i = start;
            let mut j = mid + 1;
            let mut k = 0;
            while i <= mid && j <= end {
                if vec[i] <= vec[j] {
                    temp[k] = vec[i].clone();
                    i += 1;
                } else {
                    temp[k] = vec[j].clone();
                    j += 1;
                }
                k += 1;
            }
            while i <= mid {
                temp[k] = vec[i].clone();
                i += 1;
                k += 1;
            }
            while j <= end {
                temp[k] = vec[j].clone();
                j += 1;
                k += 1;
            }
            for i in 0..k {
                vec[start + i] = temp[i].clone();
            }
        }
        pub fn merge_sort<T: Ord + Default + Clone>(vec: &mut [T], start: usize, end: usize) {
            if start >= end {
                return;
            }
            let mid = (start + end) / 2;
            merge_sort(vec, start, mid);
            merge_sort(vec, mid + 1, end);
            merge(vec, start, mid, end);
        }
    }

    if vec.is_empty() {
        return;
    }
    local::merge_sort(vec, 0, vec.len() - 1);
}
fn heap_sort<T: Ord>(vec: &mut [T]) {
    mod local {
        pub fn adjust<T: Ord>(vec: &mut [T], index: usize, end: usize) {
            let mut index = index;
            loop {
                let mut idx = index;
                if index * 2 + 1 <= end && vec[index * 2 + 1] > vec[idx] {
                    idx = index * 2 + 1;
                }
                if index * 2 + 2 <= end && vec[index * 2 + 2] > vec[idx] {
                    idx = index * 2 + 2;
                }
                if idx == index {
                    break;
                }
                vec.swap(index, idx);
                index = idx;
            }
        }
        pub fn build_heap<T: Ord>(vec: &mut [T]) {
            for i in (0..=(vec.len() - 1 - 1) / 2).rev() {
                adjust(vec, i, vec.len() - 1);
            }
        }
    }

    if vec.is_empty() || vec.len() == 1 {
        return;
    }
    local::build_heap(vec);
    for i in (1..vec.len()).rev() {
        vec.swap(0, i);
        local::adjust(vec, 0, i - 1);
    }
}
fn counting_sort(vec: &mut [i32]) {
    if vec.is_empty() {
        return;
    }
    let min_val = vec.iter().min().unwrap().clone();
    let max_val = vec.iter().max().unwrap().clone();
    let offset = min_val;
    let length = (max_val - min_val + 1) as usize;

    let mut cnts = vec![0; length];
    for &num in vec.iter() {
        cnts[(num - offset) as usize] += 1;
    }

    let mut index = 0;
    for i in 0..vec.len() {
        while cnts[index] <= 0 {
            index += 1;
        }
        vec[i] = index as i32 + offset;
        cnts[index] -= 1;
    }
}

fn test(sort_func: fn(&mut [i32]), func_name: &str) {
    let mut vec = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    sort_func(&mut vec);
    assert_eq!(vec, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], "{}", func_name);

    vec = vec![10, 9, 8, 7, 6, 5, 4, 3, 2, 1];
    sort_func(&mut vec);
    assert_eq!(vec, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], "{}", func_name);

    vec = vec![5, 3, 8, 4, 2, 7, 1, 10, 6, 9];
    sort_func(&mut vec);
    assert_eq!(vec, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], "{}", func_name);

    vec = vec![1, 1, 1, 1, 1, 1, 1, 1, 1, 1];
    sort_func(&mut vec);
    assert_eq!(vec, [1, 1, 1, 1, 1, 1, 1, 1, 1, 1], "{}", func_name);

    vec = vec![10, 10, 10, 10, 10, 1, 1, 1, 1, 1];
    sort_func(&mut vec);
    assert_eq!(vec, [1, 1, 1, 1, 1, 10, 10, 10, 10, 10], "{}", func_name);

    vec = vec![1];
    sort_func(&mut vec);
    assert_eq!(vec, [1], "{}", func_name);

    vec = vec![];
    sort_func(&mut vec);
    assert_eq!(vec, [], "{}", func_name);
}

fn main() {
    test(insert_sort, "insert_sort");
    test(shell_sort, "shell_sort");
    test(select_sort, "select_sort");
    test(bubble_sort, "bubble_sort");
    test(quick_sort, "quick_sort");
    test(merge_sort, "merge_sort");
    test(heap_sort, "heap_sort");
    test(counting_sort, "counting_sort");
    println!("All tests passed.");
}
