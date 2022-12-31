#[allow(dead_code)]

pub fn haha() {
    println!("haha");
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        haha();
    }
}
