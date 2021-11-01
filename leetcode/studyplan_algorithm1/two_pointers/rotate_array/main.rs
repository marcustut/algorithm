// This method first create a clone of the original vector
// as a reference, then iterate through the array in two
// slice, and put values from the cloned vector.
//
// Time Complexity: O(n)
// Space Complexity: O(n)
fn rotate(nums: &mut Vec<i32>, k: i32) {
    // make a clone of original vector
    let nums2 = nums.clone();

    // mod k will make sure k never gets bigger than length
    let k = k as usize % nums.len();

    // mutate the first slice
    for i in 0..k {
        nums[i] = nums2[nums2.len() - k + i];
    }
    // mutate the second slice
    for i in k..nums.len() {
        nums[i] = nums2[i - k];
    }
}

fn main() {
    let mut nums: Vec<i32> = vec![1, 2, 3, 4, 5, 6, 7];
    rotate(&mut nums, 3);
    println!("{:?}", nums);
}

#[cfg(test)]
mod tests {
    use crate::rotate;

    #[test]
    fn test_one_step_to_the_right() {
        let mut tc1: Vec<i32> = vec![1, 2, 3, 4, 5, 6, 7];
        rotate(&mut tc1, 1);
        assert_eq!(tc1, vec![7, 1, 2, 3, 4, 5, 6]);

        let mut tc2: Vec<i32> = vec![-1, -100, 3, 99];
        rotate(&mut tc2, 1);
        assert_eq!(tc2, vec![99, -1, -100, 3]);
    }

    #[test]
    fn test_two_step_to_the_right() {
        let mut tc1: Vec<i32> = vec![1, 2, 3, 4, 5, 6, 7];
        rotate(&mut tc1, 2);
        assert_eq!(tc1, vec![6, 7, 1, 2, 3, 4, 5]);

        let mut tc2: Vec<i32> = vec![-1, -100, 3, 99];
        rotate(&mut tc2, 2);
        assert_eq!(tc2, vec![3, 99, -1, -100]);
    }

    #[test]
    fn test_three_step_to_the_right() {
        let mut tc1: Vec<i32> = vec![1, 2, 3, 4, 5, 6, 7];
        rotate(&mut tc1, 3);
        assert_eq!(tc1, vec![5, 6, 7, 1, 2, 3, 4]);

        let mut tc2: Vec<i32> = vec![-1, -100, 3, 99];
        rotate(&mut tc2, 3);
        assert_eq!(tc2, vec![-100, 3, 99, -1]);
    }

    #[test]
    fn test_one_element_vector() {
        let mut tc1: Vec<i32> = vec![-1];
        rotate(&mut tc1, 2);
        assert_eq!(tc1, vec![-1]);
    }

    #[test]
    fn test_k_bigger_than_length() {
        let mut tc1: Vec<i32> = vec![1, 2, 3, 4, 5, 6, 7];
        rotate(&mut tc1, 10);
        assert_eq!(tc1, vec![5, 6, 7, 1, 2, 3, 4]);

        let mut tc2: Vec<i32> = vec![-1, -100, 3, 99];
        rotate(&mut tc2, 7);
        assert_eq!(tc2, vec![-100, 3, 99, -1]);
    }
}
