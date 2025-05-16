use std::collections::HashSet;

fn vectors_match<T: PartialEq>(left: &Vec<T>, right: &Vec<T>) -> bool {
    left.into_iter().zip(right).filter(|&(a, b)| a != b).count() == 0
}

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &[&'a str]) -> HashSet<&'a str> {
    let mut anagrams = HashSet::new();
    let mut word_chars: Vec<char> = word.to_lowercase().chars().collect();
    word_chars.sort();

    println!("🚩 word: {}", word);
    println!("🚩 word_chars: {:?}", word_chars);

    for test in possible_anagrams.iter() {
        if word.to_lowercase() == test.to_lowercase() {
            continue;
        }

        if word.len() != test.len() {
            continue;
        }

        let mut test_chars: Vec<char> = test.to_lowercase().chars().collect();
        test_chars.sort();

        println!("🚩 test_chars: {:?}", test_chars);

        if vectors_match(&word_chars, &test_chars) {
            println!("Adding {:?} to HashSet", *test);
            anagrams.insert(*test);
        }
    }

    anagrams
}
