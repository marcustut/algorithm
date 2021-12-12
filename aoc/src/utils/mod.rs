use std::fs;

pub(crate) fn read_file(filename: String) -> String {
    fs::read_to_string(filename.clone())
        .expect(&format!("Unable to read {}", filename).to_owned())
        .to_owned()
}

pub(crate) fn read_file_lines(filename: String) -> Vec<String> {
    read_file(filename).lines().map(|line| line.to_string()).collect()
}
