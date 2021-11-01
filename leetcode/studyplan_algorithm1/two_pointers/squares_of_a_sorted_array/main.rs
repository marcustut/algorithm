// This solution is not using two pointers, it simply iterates through the
// vector and map each element to its squares, and finally sort the whole
// array.
//
// NOTE: the rust std library is using timsort in this case. O(n log(n))
// @see https://doc.rust-lang.org/std/primitive.slice.html#method.sort
//
// Time Complexity: O(n log(n))
// Space Complexity: O(1)
fn sorted_squares_slow(nums: Vec<i32>) -> Vec<i32> {
    let mut nums: Vec<i32> = nums.iter().map(|&x| x * x).collect();
    nums.sort();
    nums
}

// The method has two pointers - 'start' and 'end', it iterates the vector
// from the back, determining whether start or end is bigger and it puts the
// bigger one at the back of the vector.
//
// Time Complexity: O(n)
// Space Complexity: O(n)
fn sorted_squares_fast(nums: Vec<i32>) -> Vec<i32> {
    let mut start = 0;
    let mut end = nums.len() - 1;
    let mut i = end;

    let mut res: Vec<i32> = vec![0; nums.len()];

    while start <= end {
        let x = nums[start] * nums[start];
        let y = nums[end] * nums[end];

        // if two pointers meet (equals)
        if start == end {
            res[i] = x;
            break;
        }

        // store the larger pointer and increase one step
        if x > y {
            res[i] = x;
            i -= 1;
            start += 1;
        } else {
            res[i] = y;
            i -= 1;
            end -= 1;
        }
    }

    res
}

fn main() {
    println!("{:?}", sorted_squares_slow(vec![-7, -3, 2, 3, 11]));
    println!("{:?}", sorted_squares_fast(vec![-7, -3, 2, 3, 11]));
}

#[cfg(test)]
mod tests {
    use crate::{sorted_squares_fast, sorted_squares_slow};

    #[test]
    fn test_sorted_squares_slow() {
        assert_eq!(
            sorted_squares_slow(vec![-4, -1, 0, 3, 10]),
            vec![0, 1, 9, 16, 100]
        );
        assert_eq!(
            sorted_squares_slow(vec![-7, -3, 2, 3, 11]),
            vec![4, 9, 9, 49, 121]
        );
    }

    #[test]
    fn test_sorted_squares_fast() {
        assert_eq!(
            sorted_squares_fast(vec![-4, -1, 0, 3, 10]),
            vec![0, 1, 9, 16, 100]
        );
        assert_eq!(
            sorted_squares_fast(vec![-7, -3, 2, 3, 11]),
            vec![4, 9, 9, 49, 121]
        );
    }
}
