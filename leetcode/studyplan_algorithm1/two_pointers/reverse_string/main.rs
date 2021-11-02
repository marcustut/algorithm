// This solution uses a two pointer method, where there's a pointer
// iterating from the stat and another pointer iterating backwards.
// So at each iteration, both the pointers will swap places, and when
// both the pointer meets, then it is the time to exits the function.
//
// Time Complexity: O(n/2)
// Space Complexity: O(1)
fn reverse_string(s: &mut Vec<char>) {
    let mut start = 0;
    let mut end = s.len() - 1;

    while start <= end {
        if start == end {
            break;
        }
        s.swap(start, end);
        start += 1;
        end -= 1;
    }
}

fn main() {
    let mut s = vec!['m', 'a', 'r', 'c', 'i'];
    reverse_string(&mut s);
    println!("{:?}", s);
}

#[cfg(test)]
mod tests {
    use crate::reverse_string;

    #[test]
    fn test_even_length_vector() {
        let mut tc1 = vec!['H', 'a', 'n', 'n', 'a', 'h'];
        reverse_string(&mut tc1);
        assert_eq!(tc1, vec!['h', 'a', 'n', 'n', 'a', 'H']);
    }

    #[test]
    fn test_odd_length_vector() {
        let mut tc1 = vec!['h', 'e', 'l', 'l', 'o'];
        reverse_string(&mut tc1);
        assert_eq!(tc1, vec!['o', 'l', 'l', 'e', 'h']);
    }
}
