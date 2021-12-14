use std::collections::HashMap;

pub struct Day3 {}

impl Day3 {
    fn bits_to_dec(arr: Vec<bool>) -> u32 {
        let mut ans: u32 = 0;
        for i in (0..arr.len()).rev() {
            if arr[i] {
                ans += (2 as u32).pow((arr.len() - 1 - i).try_into().unwrap());
            }
        }
        ans
    }

    pub fn binary_diagnostic(input: Vec<String>) -> u32 {
        let arr: Vec<Vec<bool>> = input
            .into_iter()
            .map(|x| {
                x.chars()
                    .map(|b| {
                        if b == '0' {
                            return false;
                        } else {
                            return true;
                        }
                    })
                    .collect()
            })
            .collect();

        let mut map = HashMap::new();

        for i in 0..arr.len() {
            for j in 0..arr[i].len() {
                if arr[i][j] {
                    if let Some(x) = map.get_mut(&j) {
                        *x = *x + 1;
                    } else {
                        map.insert(j, 1);
                    }
                }
            }
        }

        let mut sorted: Vec<(usize, i32)> = map.into_iter().collect();
        sorted.sort_by_key(|s| s.0);

        let gamma_bits: Vec<bool> = sorted
            .iter()
            .map(|(_, value)| {
                if (*value as usize) > arr.len() / 2 {
                    return true;
                } else {
                    return false;
                }
            })
            .collect();

        let epsilon_bits: Vec<bool> = gamma_bits.iter().map(|bit| !bit).collect();

        Day3::bits_to_dec(gamma_bits) * Day3::bits_to_dec(epsilon_bits)
    }

    // TODO: implement this solution in Rust
    pub fn binary_diagnostic_rating(input: Vec<String>) -> u32 {
        0
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::utils::read_file_lines;

    #[test]
    fn test_binary_diagnostic_simple() {
        let input = read_file_lines("input/day3_1.txt".to_string());
        assert_eq!(Day3::binary_diagnostic(input), 198);
    }

    #[test]
    fn test_binary_diagnostic_hard() {
        let input = read_file_lines("input/day3_2.txt".to_string());
        assert_eq!(Day3::binary_diagnostic(input), 2003336);
    }

    #[test]
    fn test_binary_diagnostic_rating_simple() {
        let input = read_file_lines("input/day3_1.txt".to_string());
        assert_eq!(Day3::binary_diagnostic_rating(input), 230);
    }

    #[test]
    fn test_binary_diagnostic_rating_hard() {
        let input = read_file_lines("input/day3_2.txt".to_string());
        assert_eq!(Day3::binary_diagnostic_rating(input), 1877139);
    }
}
