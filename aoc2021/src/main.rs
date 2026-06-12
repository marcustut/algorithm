#![allow(dead_code)]

mod days;
mod utils;

use crate::days::day5::Day5;
use crate::utils::read_file_lines;

fn main() {
    // let input = read_file_lines("input/day1_1.txt".to_string());
    // Day1::sonar_sweep_window(input);

    let input = read_file_lines("input/day5_2.txt".to_string());
    println!(
        "first: {}",
        Day5::hydrothermal_venture(Day5::parse_input(input.clone()))
    );
    println!(
        "second: {}",
        Day5::hydrothermal_venture_diagonal(Day5::parse_input(input))
    );
}
