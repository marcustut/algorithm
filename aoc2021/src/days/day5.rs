use std::cmp::{max, min};
use std::collections::HashMap;

pub struct Day5 {}

#[derive(Copy, Clone, Debug, PartialEq, Eq, Hash)]
pub struct Coord {
    x: i32,
    y: i32,
}

impl Day5 {
    pub fn parse_input(input: Vec<String>) -> Vec<(Coord, Coord)> {
        input
            .into_iter()
            .map(|line| {
                let coords = line
                    .split(" -> ")
                    .into_iter()
                    .map(|str| {
                        let nums = str
                            .split(',')
                            .into_iter()
                            .map(|n| n.parse::<i32>().unwrap())
                            .collect::<Vec<i32>>();
                        Coord {
                            x: nums[0],
                            y: nums[1],
                        }
                    })
                    .collect::<Vec<Coord>>();
                (coords[0], coords[1])
            })
            .collect::<Vec<(Coord, Coord)>>()
    }

    fn insert_into_map(key: Coord, value: i32, map: &mut HashMap<Coord, i32>) {
        if let Some(x) = map.get_mut(&key) {
            *x = *x + value;
        } else {
            map.insert(key, value);
        }
    }

    fn handle_is_straight(first: Coord, second: Coord, map: &mut HashMap<Coord, i32>) {
        if first.x == second.x || first.y == second.y {
            if first.x < second.x {
                for i in first.x..second.x + 1 {
                    Day5::insert_into_map(Coord { x: i, y: second.y }, 1, map);
                }
            } else if first.x > second.x {
                for i in second.x..first.x + 1 {
                    Day5::insert_into_map(Coord { x: i, y: second.y }, 1, map);
                }
            } else if first.y < second.y {
                for j in first.y..second.y + 1 {
                    Day5::insert_into_map(Coord { x: first.x, y: j }, 1, map);
                }
            } else {
                for j in second.y..first.y + 1 {
                    Day5::insert_into_map(Coord { x: first.x, y: j }, 1, map);
                }
            }
        }
    }

    fn handle_is_45(first: Coord, second: Coord, map: &mut HashMap<Coord, i32>) {
        if (second.x - first.x).abs() == (second.y - first.y).abs() {
            println!("{},{} -> {},{}", first.x, first.y, second.x, second.y);
            if (first.x == first.y) && (second.x == second.y) {
                for i in min(first.x, second.x)..max(first.x, second.x) + 1 {
                    println!("{},{}", i, i);
                    Day5::insert_into_map(Coord { x: i, y: i }, 1, map);
                }
            } else if (first.x == second.y) && (second.x == first.y) {
                for i in min(first.x, second.x)..max(first.x, second.x) + 1 {
                    println!("{},{}", i, (max(first.y, second.y).abs() - i).abs());
                    Day5::insert_into_map(
                        Coord {
                            x: i,
                            y: (max(first.y, second.y).abs() - i).abs(),
                        },
                        1,
                        map,
                    );
                }
            } else if first.x == first.y {
                let mut j = 0;
                for i in min(first.x, second.x)..max(first.x, second.x) + 1 {
                    println!("{},{}", i, (max(first.y, second.y).abs() - j).abs());
                    Day5::insert_into_map(
                        Coord {
                            x: i,
                            y: (max(first.y, second.y).abs() - j).abs(),
                        },
                        1,
                        map,
                    );
                    j += 1;
                }
            } else {
                let mut j = min(first.y, second.y).abs();
                for i in min(first.x, second.x)..max(first.x, second.x) + 1 {
                    println!("{},{}", i, j);
                    Day5::insert_into_map(Coord { x: i, y: j }, 1, map);
                    j += 1;
                }
            }
        }
    }

    pub fn hydrothermal_venture(coords: Vec<(Coord, Coord)>) -> i32 {
        let mut map: HashMap<Coord, i32> = HashMap::new();

        for (first, second) in coords {
            Day5::handle_is_straight(first, second, &mut map);
        }

        map.into_iter()
            .fold(0, |acc, (_, val)| if val > 1 { acc + 1 } else { acc })
    }

    pub fn hydrothermal_venture_diagonal(coords: Vec<(Coord, Coord)>) -> i32 {
        let mut map: HashMap<Coord, i32> = HashMap::new();

        for (first, second) in coords {
            Day5::handle_is_straight(first, second, &mut map);
            Day5::handle_is_45(first, second, &mut map);
        }

        map.into_iter()
            .fold(0, |acc, (_, val)| if val > 1 { acc + 1 } else { acc })
    }
}

#[cfg(test)]
mod test {
    use super::*;
    use crate::utils::read_file_lines;

    #[test]
    fn test_hydrothermal_venture_simple() {
        let input = read_file_lines("input/day5_1.txt".to_string());
        let input = Day5::parse_input(input);
        assert_eq!(Day5::hydrothermal_venture(input), 5);
    }

    #[test]
    fn test_hydrothermal_venture_hard() {
        let input = read_file_lines("input/day5_2.txt".to_string());
        let input = Day5::parse_input(input);
        assert_eq!(Day5::hydrothermal_venture(input), 5167);
    }

    #[test]
    fn test_hydrothermal_venture_diagonal_simple() {
        let input = read_file_lines("input/day5_1.txt".to_string());
        let input = Day5::parse_input(input);
        assert_eq!(Day5::hydrothermal_venture_diagonal(input), 12);
    }

    #[test]
    fn test_hydrothermal_venture_diagonal_hard() {
        let input = read_file_lines("input/day5_2.txt".to_string());
        let input = Day5::parse_input(input);
        assert_eq!(Day5::hydrothermal_venture_diagonal(input), 23864);
    }
}
