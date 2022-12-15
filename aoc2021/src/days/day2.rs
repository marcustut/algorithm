use std::collections::HashMap;

pub struct Day2 {}

impl Day2 {
    pub fn dive(input: Vec<String>) -> i32 {
        let mut map = HashMap::new();

        for i in 0..input.len() {
            let splits: Vec<&str> = input[i].split(" ").collect();
            if let Some(x) = map.get_mut(splits[0]) {
                *x = *x + splits[1].parse::<i32>().expect("unable to parse input");
            } else {
                map.insert(
                    splits[0],
                    splits[1].parse::<i32>().expect("unable to parse input"),
                );
            }
        }

        map["forward"] * (map["down"] - map["up"])
    }

    pub fn dive_with_aim(input: Vec<String>) -> i32 {
        let mut aim = 0;
        let mut distance = 0;
        let mut depth = 0;

        for i in 0..input.len() {
            let splits: Vec<&str> = input[i].split(" ").collect();
            let x = splits[1].parse::<i32>().expect("unable to parse input");
            match splits[0] {
                "forward" => {
                    distance += x;
                    depth += x * aim;
                },
                "up" => aim -= x,
                "down" => aim += x,
                _ => {},
            }
        }

        distance * depth
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::utils::read_file_lines;

    #[test]
    fn test_dive_simple() {
        let input = read_file_lines("input/day2_1.txt".to_string());
        assert_eq!(Day2::dive(input), 150);
    }

    #[test]
    fn test_dive_hard() {
        let input = read_file_lines("input/day2_2.txt".to_string());
        assert_eq!(Day2::dive(input), 2073315);
    }

    #[test]
    fn test_dive_with_aim_simple() {
        let input = read_file_lines("input/day2_1.txt".to_string());
        assert_eq!(Day2::dive_with_aim(input), 900);
    }

    #[test]
    fn test_dive_with_aim_hard() {
        let input = read_file_lines("input/day2_2.txt".to_string());
        assert_eq!(Day2::dive_with_aim(input), 1840311528);
    }
}
