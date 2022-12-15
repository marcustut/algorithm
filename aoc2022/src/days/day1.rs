pub struct Day1 {}

impl Day1 {
    pub fn calorie_counting_p1(input: Vec<String>) -> i32 {
        let mut max = 0;
        let mut local_max = 0;

        input.iter().for_each(|cal| {
            match cal.parse::<i32>() {
                Ok(cal) => local_max += cal,
                Err(_) => {
                    if local_max > max {
                        max = local_max
                    }
                    local_max = 0;
                },
            }
        });

        max
    }

    pub fn calorie_counting_p2(mut input: Vec<String>) -> i32 {
        input.push("".to_string());

        let mut max = Vec::new();
        let mut local_max = 0;

        input.iter().for_each(|cal| {
            match cal.parse::<i32>() {
                Ok(cal) => local_max += cal,
                Err(_) => {
                    if max.len() == 0 {
                        max.push(local_max);
                    } else if local_max > max[max.len() - 1] {
                        max.push(local_max);
                    }

                    local_max = 0;
                }
            }
            max.sort();
            max.reverse();
        });

        max[0..3].iter().sum()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::utils::read_file_lines;

    #[test]
    fn test_first_simple() {
        let input = read_file_lines("input/day1_1.txt".to_string());
        assert_eq!(Day1::calorie_counting_p1(input), 24000);
    }

    #[test]
    fn test_first_hard() {
        let input = read_file_lines("input/day1_2.txt".to_string());
        assert_eq!(Day1::calorie_counting_p1(input), 71780);
    }

    #[test]
    fn test_second_simple() {
        let input = read_file_lines("input/day1_1.txt".to_string());
        assert_eq!(Day1::calorie_counting_p2(input), 45000);
    }

    #[test]
    fn test_second_hard() {
        let input = read_file_lines("input/day1_2.txt".to_string());
        assert_eq!(Day1::calorie_counting_p2(input), 212489);
    }
}
