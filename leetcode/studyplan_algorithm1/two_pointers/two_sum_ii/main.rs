// TODO: Update Comment
// Time Complexity: O(n^2)
// Space Complexity: O(1)
fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
    let mut res: Vec<i32> = Vec::new();

    for i in 0..numbers.len() {
        if res.len() == 2 {
            break;
        }
        for j in i + 1..numbers.len() {
            if numbers[i] + numbers[j] == target {
                res.push(i as i32 + 1);
                res.push(j as i32 + 1);
            }
        }
    }

    res
}

fn main() {
    println!("{:?}", two_sum(vec![2, 7, 11, 15], 9));
}

#[cfg(test)]
mod tests {
    use crate::two_sum;

    #[test]
    fn test_positive_vector() {
        assert_eq!(two_sum(vec![2, 7, 11, 15], 9), vec![1, 2]);
        assert_eq!(two_sum(vec![2, 3, 4], 6), vec![1, 3]);
    }

    #[test]
    fn test_negative_vector() {
        assert_eq!(two_sum(vec![-1, 0], -1), vec![1, 2]);
    }
}
