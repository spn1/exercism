use std::str;
use std::fmt::Write;

const ASTERIX: u8 = 42;

const test: [&str; 3] = [
    ".*...*.",
    "..***..",
    "...*..*"
];

fn check_row(index: usize, row: &[u8]) -> u8 {
    let min = if index == 0 { 0 } else { index - 1 };
    let max = if index == row.len() - 1 { row.len() - 1 } else { index + 1 };
    // Check if any of the cells have mines
    let slice = row.get(min..max).unwrap();
    slice.iter().fold(
        0,
        |acc, cell|
            if *cell == ASTERIX { acc + 1 } else { acc } )
}

fn check_cell(cell_index: usize, row_index: usize, field: &Vec<&[u8]>) -> u8 {
    let mut count: u8 = 0;
    
    if field[row_index][cell_index] == ASTERIX {
        return ASTERIX
    }
    
    // Check left & right cells
    let mut left_right_count = 0;
    if cell_index != 0 && field[row_index][cell_index - 1] == ASTERIX {
        left_right_count += 1;
    }
    if cell_index != field[row_index].len() - 1 && field[row_index][cell_index + 1] == ASTERIX {
        left_right_count += 1;
    }
    count += left_right_count;

    // Check rows above and below
    let above = if row_index == 0 { 0 } else { row_index - 1 };
    let below = if row_index == field[row_index].len() - 1 { row_index } else { row_index + 1 };
    if above != row_index { count += check_row(cell_index, field[above]); }
    if below != row_index { count += check_row(cell_index, field[below]); }

    println!("Count: {}", count);

    count
}

pub fn annotate(minefield: &[&str]) -> Vec<String> {
    let bytes: Vec<_> = b"here's a byte string".to_vec();
    println!("Bytes: {:?}", bytes);
    let field: Vec<&[u8]> = minefield.iter().map(|row| row.as_bytes()).collect();
    let mut annotated_minefield: Vec<String> = Vec::new();
    
    println!("Minefield: {:?}", field);
    for (row_index, row) in field.iter().enumerate() {
        let mut annotated_row: String = String::new();

        for cell_index in 0..row.len() {
            let count = check_cell(cell_index, row_index, &field);
            write!(annotated_row, "{:}", count);
            println!("Row: {:?}", annotated_row);
        }
        annotated_minefield.push(annotated_row.replace('0', " "));
        println!("annotation: {:?}", annotated_minefield);
    }

    annotated_minefield
}
