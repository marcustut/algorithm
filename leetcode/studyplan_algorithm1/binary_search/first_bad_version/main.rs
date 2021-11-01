struct Solution {
    n: i32,
    bad: i32,
}

impl Solution {
    fn is_bad_version(&self, version: i32) -> bool {
        if version >= self.bad {
            return true;
        }
        false
    }

    // simple linear search
    // O(n)
    fn first_bad_version_slow(&self) -> i32 {
        for i in 1..self.n + 1 {
            if self.is_bad_version(i) {
                return i;
            }
        }
        self.n
    }

    // binary search
    // note: this might not be safe, as it is downcasting i64 to i32 without checking
    // O(log n)
    fn first_bad_version_fast(&self) -> i32 {
        let mut start: i64 = 1;
        let mut end = i64::from(self.n);
        let mut result = start;

        while start <= end {
            let mid = (start + end) / 2;
            if self.is_bad_version(mid as i32) {
                end = mid - 1;
                result = mid;
            } else {
                start = mid + 1;
            }
        }

        result as i32
    }
}

fn main() {
    let sol1 = Solution { n: 5, bad: 4 };
    println!("{}", sol1.first_bad_version_slow());
    println!("{}", sol1.first_bad_version_fast());
}

#[cfg(test)]
mod tests {
    use crate::Solution;

    #[test]
    fn test_is_bad_version() {
        let sol = Solution { n: 5, bad: 4 };
        assert_eq!(sol.is_bad_version(1), false);
        assert_eq!(sol.is_bad_version(2), false);
        assert_eq!(sol.is_bad_version(3), false);
        assert_eq!(sol.is_bad_version(4), true);
        assert_eq!(sol.is_bad_version(5), true);
    }

    #[test]
    fn test_first_bad_version_slow() {
        let sol = Solution { n: 5, bad: 4 };
        assert_eq!(sol.first_bad_version_slow(), 4);
        let sol = Solution { n: 1, bad: 1 };
        assert_eq!(sol.first_bad_version_slow(), 1);
        let sol = Solution { n: 3, bad: 2 };
        assert_eq!(sol.first_bad_version_slow(), 2);
        // note: running this will be very slow as it is O(n)
        let sol = Solution {
            n: 1926205968,
            bad: 1167880583,
        };
        assert_eq!(sol.first_bad_version_slow(), 1167880583);
    }

    #[test]
    fn test_first_bad_version_fast() {
        let sol = Solution { n: 5, bad: 4 };
        assert_eq!(sol.first_bad_version_fast(), 4);
        let sol = Solution { n: 1, bad: 1 };
        assert_eq!(sol.first_bad_version_fast(), 1);
        let sol = Solution { n: 3, bad: 2 };
        assert_eq!(sol.first_bad_version_fast(), 2);
        let sol = Solution {
            n: 1926205968,
            bad: 1167880583,
        };
        assert_eq!(sol.first_bad_version_fast(), 1167880583);
    }
}
