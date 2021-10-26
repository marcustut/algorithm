fn binary_search(nums: Vec<i32>, target: i32) -> i32 {
    if nums.len() == 0 {
        return -1;
    }

    let mut start = 0;
    let mut end = nums.len() - 1;

    while start <= end {
        let mid = (start + end) / 2;
        if target == nums[mid] {
            return mid as i32;
        } else if target > nums[mid] {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    -1
}

fn main() {
    println!("{}", binary_search(vec![-1, 0, 3, 5, 9, 12], 9))
}

#[cfg(test)]
mod tests {
    use crate::binary_search;

    #[test]
    fn test_empty_array() {
        assert_eq!(binary_search(vec![], 0), -1)
    }

    #[test]
    fn test_one_element_array() {
        assert_eq!(binary_search(vec![5], 5), 0)
    }

    #[test]
    fn test_two_element_array() {
        assert_eq!(binary_search(vec![2, 5], 5), 1)
    }

    #[test]
    fn test_when_target_present() {
        assert_eq!(binary_search(vec![-1, 0, 3, 5, 9, 12], 9), 4)
    }

    #[test]
    fn test_when_target_not_present() {
        assert_eq!(binary_search(vec![-1, 0, 3, 5, 9, 12], 2), -1)
    }

    #[test]
    #[should_panic]
    fn test_unsorted_array() {
        binary_search(vec![5, 2], 2);
    }
}
