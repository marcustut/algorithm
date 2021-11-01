// This method first sorts the vector, then it uses two pointer
// i and j to swap the zeroes to the back.
//
// Time Complexity: O(n^2)
// Space Complexity: O(1)
fn move_zeroes(nums: &mut Vec<i32>) {
    if !nums.contains(&0) {
        return;
    }

    for i in 0..nums.len() {
        if nums[i] == 0 {
            for j in i..nums.len() {
                if nums[j] != 0 {
                    nums.swap(i, j);
                    break;
                }
            }
        }
    }
}

fn main() {
    let mut nums: Vec<i32> = vec![0, 1, 0, 3, 12];
    move_zeroes(&mut nums);
    println!("{:?}", nums);
}

#[cfg(test)]
mod tests {
    use crate::move_zeroes;

    #[test]
    fn test_vector_no_zero() {
        let mut tc1: Vec<i32> = vec![2, 1];
        move_zeroes(&mut tc1);
        assert_eq!(tc1, vec![2, 1]);
    }

    #[test]
    fn test_vector_non_zero_sorted() {
        let mut tc1: Vec<i32> = vec![0, 1, 0, 3, 12];
        move_zeroes(&mut tc1);
        assert_eq!(tc1, vec![1, 3, 12, 0, 0]);

        let mut tc2: Vec<i32> = vec![-99, 0, -12, 0, 0, 3];
        move_zeroes(&mut tc2);
        assert_eq!(tc2, vec![-99, -12, 3, 0, 0, 0]);
    }

    #[test]
    fn test_vector_non_zero_unsorted() {
        let mut tc1: Vec<i32> = vec![0, 3, 0, 1, 12];
        move_zeroes(&mut tc1);
        assert_eq!(tc1, vec![3, 1, 12, 0, 0]);

        let mut tc2: Vec<i32> = vec![-12, 0, 3, 0, 0, -99];
        move_zeroes(&mut tc2);
        assert_eq!(tc2, vec![-12, 3, -99, 0, 0, 0]);

        let mut tc3: Vec<i32> = vec![4, 2, 4, 0, 0, 3, 0, 5, 1, 0];
        move_zeroes(&mut tc3);
        assert_eq!(tc3, vec![4, 2, 4, 3, 5, 1, 0, 0, 0, 0]);
    }
}
