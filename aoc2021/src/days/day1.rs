pub struct Day1 {}

impl Day1 {
    pub fn sonar_sweep(input: Vec<String>) -> i32 {
        let mut local_max = input[0].parse::<i32>().expect("unable to parse input");
        let mut count = 0;

        for i in 1..input.len() {
            let num = input[i].parse::<i32>().expect("unable to parse input");
            if num > local_max {
                count += 1;
            }
            local_max = num;
        }

        count
    }

    pub fn sonar_sweep_window(input: Vec<String>) -> i32 {
        let mut local_max = 0;
        let mut count = 0;

        for i in 0..input.len() - 2 {
            let sum = vec![0, 1, 2].iter().fold(0, |acc, x| {
                acc + input[i + (*x as usize)]
                    .parse::<i32>()
                    .expect("unable to parse input")
            });
            if sum > local_max {
                count += 1;
            }
            local_max = sum;
        }

        count - 1
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::utils::read_file_lines;

    #[test]
    fn test_first_simple() {
        let input = read_file_lines("input/day1_1.txt".to_string());
        assert_eq!(Day1::sonar_sweep(input), 7);
    }

    #[test]
    fn test_first_hard() {
        let input = read_file_lines("input/day1_2.txt".to_string());
        assert_eq!(Day1::sonar_sweep(input), 1477);
    }

    #[test]
    fn test_second_simple() {
        let input = read_file_lines("input/day1_1.txt".to_string());
        assert_eq!(Day1::sonar_sweep_window(input), 5);
    }

    #[test]
    fn test_second_hard() {
        let input = read_file_lines("input/day1_2.txt".to_string());
        assert_eq!(Day1::sonar_sweep_window(input), 1523);
    }
}
