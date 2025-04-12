fn is_sublist_of(smaller_list: &[i32], larger_list: &[i32]) -> bool {
    if smaller_list.len() == 0 {
        return true;
    }

    larger_list
        .windows(smaller_list.len())
        .any(|sublist| sublist == smaller_list)
}

fn do_lists_match(first_list: &[i32], second_list: &[i32]) -> bool {
    let zipped = first_list.into_iter().zip(second_list);
    zipped.filter(|&(&left, &right)| left != right).count() == 0
}

#[derive(Debug, PartialEq, Eq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

pub fn sublist(first_list: &[i32], second_list: &[i32]) -> Comparison {
    let length_diff: i32 = first_list.len() as i32 - second_list.len() as i32;

    match length_diff {
        i32::MIN..=-1 => {
            // Is first_list a sublist of second_list
            match is_sublist_of(first_list, second_list) {
                true => return Comparison::Sublist,
                false => return Comparison::Unequal
            };
        },
        0 => {
            // Are both lists equal
            match do_lists_match(first_list, second_list) {
                true => return Comparison::Equal,
                false => return Comparison::Unequal
            };
        },
        1..=i32::MAX => {
            // Is second_list a sublist of first_list
            match is_sublist_of(second_list, first_list) {
                true => return Comparison::Superlist,
                false => return Comparison::Unequal
            };
        },
    }
}
