// This is a brute force solution
// Time Complexity: O(2^n)
fn fib_brute_force(n: i32) -> i32 {
    if n == 0 {
        return 0;
    }
    if n == 1 {
        return 1;
    }
    return fib_brute_force(n - 1) + fib_brute_force(n - 2);
}

// This is a DP solution (bottom-up memoized)
// Time Complexity: O(n)
// Space Complexity: O(n)
fn fib_bottom_up(n: i32) -> i32 {
    let mut memo: Vec<i32> = vec![0; (n + 1) as usize];
    for i in 0..memo.len() {
        if i == 0 || i == 1 {
            memo[i] = i as i32;
            continue;
        }
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    memo[n as usize]
}

fn main() {
    println!("fib_brute_force: fib({}) = {}", 10, fib_brute_force(10));
    println!("fib_bottom_up: fib({}) = {}", 10, fib_bottom_up(10));
}

#[cfg(test)]
mod tests {}
