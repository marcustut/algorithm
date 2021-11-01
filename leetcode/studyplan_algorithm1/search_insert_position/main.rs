fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
    let mut start = 0 as i64;
    let mut end = (nums.len() - 1) as i64;

    if target < nums[0] {
        return start as i32;
    } else if target > nums[end as usize] {
        return nums.len() as i32;
    }

    while start <= end {
        let mid = (start + end) / 2;
        if target == nums[mid as usize] {
            return mid as i32;
        } else if target > nums[mid as usize] {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    start as i32
}

fn main() {
    println!("{}", search_insert(vec![1, 3, 5, 6], 2))
}

#[cfg(test)]
mod tests {
    use crate::search_insert;

    #[test]
    fn test_found_target() {
        assert_eq!(search_insert(vec![1, 3, 5, 6], 5), 2);
    }

    #[test]
    fn test_insert_middle() {
        assert_eq!(search_insert(vec![1, 3, 5, 6], 2), 1);
    }

    #[test]
    fn test_insert_after() {
        assert_eq!(search_insert(vec![1, 3, 5, 6], 7), 4);
    }

    #[test]
    fn test_insert_before_first() {
        assert_eq!(search_insert(vec![1, 3, 5, 6], 0), 0);
    }

    #[test]
    fn test_one_element_array() {
        assert_eq!(search_insert(vec![1], 2), 1);
        assert_eq!(search_insert(vec![1], 0), 0);
    }

    #[test]
    fn test_two_element_array() {
        assert_eq!(search_insert(vec![1, 2], 4), 2);
        assert_eq!(search_insert(vec![1, 2], 0), 0);
        assert_eq!(search_insert(vec![1, 5], 3), 1);
    }
}
