#![allow(dead_code)]

mod utils;
mod days;

use crate::utils::read_file_lines;
use crate::days::day1::Day1;

fn main() {
    let input = read_file_lines("input/day1_1.txt".to_string());
    Day1::sonar_sweep_window(input);
}
