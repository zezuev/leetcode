// A very interesting solution is to save the index of the last occurrence of a character
// If that character is encountered again, start can immediately jump over to that index plus one

pub fn length_of_longest_substring(s: String) -> i32 {
    let mut last_pos = [-1; 128];
    let mut start = 0;
    let mut max_len = 0;

    for (end, c) in s.chars().enumerate() {
        start = start.max(last_pos[c as usize] + 1);
        last_pos[c as usize] = end;
        max_len = max_len.max(end - start + 1);
    }

    max_len
}