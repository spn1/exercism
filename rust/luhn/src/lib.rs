pub fn is_valid(code: &str) -> bool {
    let digits: Vec<u32> = code
        .chars()
        .filter(|c| !c.is_whitespace())
        .map(|c| c.to_digit(10))
        .collect::<Option<Vec<u32>>>()
        .unwrap_or_default();

    if digits.len() <= 1 {
        return false;
    }

    let checksum: u32 = digits
        .iter()
        .rev()
        .enumerate()
        .map(|(i, &digit)| {
            if i % 2 == 0 {
                digit
            } else {
                let doubled = digit * 2;
                if doubled > 9 { doubled - 9 } else { doubled }
            }
        })
        .sum();

    checksum % 10 == 0
}