use std::collections::HashMap;

pub struct Day4 {}

impl Day4 {
    pub fn parse_input(input: String) -> (Vec<u32>, Vec<Vec<Vec<u32>>>) {
        let input = input
            .split('\n')
            .collect::<Vec<&str>>()
            .into_iter()
            .map(|s| s.to_string())
            .collect::<Vec<String>>();

        let numbers = &input[0]
            .split(',')
            .collect::<Vec<&str>>()
            .into_iter()
            .map(|s| s.parse::<u32>().unwrap())
            .collect::<Vec<u32>>();

        let mut boards: Vec<Vec<Vec<u32>>> = Vec::new();

        let mut board: Vec<Vec<u32>> = Vec::new();

        for i in 2..input.len() {
            if input[i].is_empty() {
                boards.push(board.clone());
                board.clear();
                continue;
            }
            let row = input[i]
                .split_whitespace()
                .map(|num| num.parse::<u32>().unwrap())
                .collect();
            board.push(row);
        }
        boards.push(board);

        (numbers.clone(), boards)
    }

    fn board_search(value: u32, board: &Vec<Vec<u32>>) -> Option<(usize, usize)> {
        for i in 0..board.len() {
            let found = board[i].iter().position(|num| *num == value);
            if let Some(j) = found {
                return Some((i, j));
            }
        }
        None
    }

    fn check_bingo(board: &Vec<Vec<(u32, bool)>>) -> bool {
        for i in 0..board.len() {
            let mut row = 0;
            let mut col = 0;
            for j in 0..board[i].len() {
                if board[i][j].1 {
                    row += 1;
                }
                if board[j][i].1 {
                    col += 1;
                }
            }
            if row == board.len() || col == board.len() {
                return true;
            }
        }
        false
    }

    fn make_flipboards(boards: Vec<Vec<Vec<u32>>>) -> Vec<Vec<Vec<(u32, bool)>>> {
        boards
            .into_iter()
            .map(|board| {
                board
                    .into_iter()
                    .map(|row| {
                        row.into_iter()
                            .map(|num| (num, false))
                            .collect::<Vec<(u32, bool)>>()
                    })
                    .collect::<Vec<Vec<(u32, bool)>>>()
            })
            .collect::<Vec<Vec<Vec<(u32, bool)>>>>()
    }

    fn sum_unflipped(flipboard: Vec<Vec<(u32, bool)>>) -> u32 {
        flipboard.into_iter().fold(0, |acc, row| {
            acc + row
                .into_iter()
                .filter(|(_, flip)| !*flip)
                .fold(0, |acc, (num, _)| acc + num)
        })
    }

    pub fn giant_squid(numbers: Vec<u32>, boards: Vec<Vec<Vec<u32>>>) -> u32 {
        let mut flipboards = Day4::make_flipboards(boards.clone());
        let mut winner = (0, Vec::new());

        for num in numbers {
            for i in 0..boards.len() {
                let pos = Day4::board_search(num, &boards[i]);
                if let Some((j, k)) = pos {
                    flipboards[i][j][k].1 = true;
                }
                if Day4::check_bingo(&flipboards[i]) {
                    winner = (num, flipboards[i].clone());
                    break;
                }
            }
            if winner.0 != 0 {
                break;
            }
        }

        winner.0 * Day4::sum_unflipped(winner.1)
    }

    pub fn giant_squid_last(numbers: Vec<u32>, boards: Vec<Vec<Vec<u32>>>) -> u32 {
        let mut flipboards = Day4::make_flipboards(boards.clone());
        let mut winner = (0, Vec::new());
        let mut remaining = boards.len();
        let mut map: HashMap<usize, bool> = HashMap::new();

        for num in numbers {
            for i in 0..boards.len() {
                let pos = Day4::board_search(num, &boards[i]);
                if let Some((j, k)) = pos {
                    flipboards[i][j][k].1 = true;
                }
                if !map.contains_key(&i) && Day4::check_bingo(&flipboards[i]) {
                    remaining -= 1;
                    map.insert(i, true);
                }
                if remaining == 0 {
                    winner = (num, flipboards[i].clone());
                    break;
                }
            }
            if winner.0 != 0 {
                break;
            }
        }

        winner.0 * Day4::sum_unflipped(winner.1)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::utils::read_file;

    #[test]
    fn test_giant_squid_simple() {
        let input = read_file("input/day4_1.txt".to_string());
        let (numbers, boards) = Day4::parse_input(input);
        assert_eq!(Day4::giant_squid(numbers, boards), 4512);
    }

    #[test]
    fn test_giant_squid_hard() {
        let input = read_file("input/day4_2.txt".to_string());
        let (numbers, boards) = Day4::parse_input(input);
        assert_eq!(Day4::giant_squid(numbers, boards), 33462);
    }

    #[test]
    fn test_giant_squid_last_simple() {
        let input = read_file("input/day4_1.txt".to_string());
        let (numbers, boards) = Day4::parse_input(input);
        assert_eq!(Day4::giant_squid_last(numbers, boards), 1924);
    }

    #[test]
    fn test_giant_squid_last_hard() {
        let input = read_file("input/day4_2.txt".to_string());
        let (numbers, boards) = Day4::parse_input(input);
        assert_eq!(Day4::giant_squid_last(numbers, boards), 30070);
    }
}
