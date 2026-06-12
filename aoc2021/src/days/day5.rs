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

    fn handle_is_straight(
        Coord { x: x1, y: y1 }: Coord,
        Coord { x: x2, y: y2 }: Coord,
        map: &mut HashMap<Coord, i32>,
    ) {
        if x1 == x2 {
            for i in min(y1, y2)..max(y1, y2) + 1 {
                Day5::insert_into_map(Coord { x: x1, y: i }, 1, map);
            }
        } else if y1 == y2 {
            for i in min(x1, x2)..max(x1, x2) + 1 {
                Day5::insert_into_map(Coord { x: i, y: y1 }, 1, map);
            }
        }
    }

    fn handle_is_45(
        Coord { x: x1, y: y1 }: Coord,
        Coord { x: x2, y: y2 }: Coord,
        map: &mut HashMap<Coord, i32>,
    ) {
        // diagonal implies that they must have identical distance on both x and y axis.
        // -> distance(x) = distance(y)
        if (x2 - x1).abs() == (y2 - y1).abs() {
            let (mut x, mut y) = (x1, y1);
            Day5::insert_into_map(Coord { x, y }, 1, map);
            while x != x2 && y != y2 {
                x += if x2 - x1 > 0 { 1 } else { -1 };
                y += if y2 - y1 > 0 { 1 } else { -1 };
                Day5::insert_into_map(Coord { x, y }, 1, map);
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
