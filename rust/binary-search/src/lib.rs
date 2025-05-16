use core::cmp::Ordering;

fn binary_search<T: Ord + Debug>(array: &[T], start: usize, end: usize, target: T) -> Option<usize> {
  let length = end - start;
  let center = start + (length / 2);

  match target.cmp(array.get(center)?) {
    Ordering::Equal => Some(center),
    Ordering::Less => if length != 1 { binary_search(array, start, center, target) } else { return None },
    Ordering::Greater => if length != 1 { binary_search(array, center, end, target) } else { return None },
  }
}

pub fn find(array: &[i32], key: i32) -> Option<usize> {
  binary_search::<i32>(array, 0, array.len(), key)
}
