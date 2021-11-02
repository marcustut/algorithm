// TODO: Update Comment
//
// Time Complexity: O(n^2)
// Space Complexity: O(1)
fn reverse_words(s: String) -> String {
    let reverse_string = |s: &mut Vec<char>| {
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
    };

    let words: Vec<&str> = s.split(' ').collect();

    let mut reversed_words: Vec<String> = Vec::new();

    for i in 0..words.len() {
        let mut word: Vec<char> = words[i].chars().collect();
        reverse_string(&mut word);
        reversed_words.push(word.into_iter().collect());
    }

    reversed_words.join(" ")
}

fn main() {
    println!(
        "{}",
        reverse_words("Let's take LeetCode contest".to_string())
    );
}

#[cfg(test)]
mod tests {
    use crate::reverse_words;

    #[test]
    fn test_example_1() {
        assert_eq!(
            reverse_words("Let's take LeetCode contest".to_string()),
            "s'teL ekat edoCteeL tsetnoc".to_string()
        );
    }

    #[test]
    fn test_example_2() {
        assert_eq!(
            reverse_words("God Ding".to_string()),
            "doG gniD".to_string()
        );
    }
}
