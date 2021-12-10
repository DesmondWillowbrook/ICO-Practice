use std::collections::HashMap;

pub fn part_1<T: std::io::BufRead> (lines: std::io::Lines<T>) -> u64 {
	let mut stack = Vec::new();

	let mut score = 0;

	let opening = ['(', '[', '{', '<'];
	let closing = [')', ']', '}', '>'];
	let inv: HashMap<char, char> = opening.iter().copied().zip(closing).collect();
	let score_map = HashMap::from([(')', 3), (']', 57), ('}', 1197), ('>', 25137)]);

	for s in lines.map(Result::unwrap) {
		stack.clear();
		for c in s.chars() {
			if opening.contains(&c) {
				stack.push(c);
			} else if closing.contains(&c) {
				let end = c;
				if let Some(start) = stack.pop() {
					if inv[&start] != end {
						score += score_map[&c];
						break;
					}
				} else {
					panic!("too many closing brackets")
				}
			}
		}
	}
	score
}

pub fn part_2<T: std::io::BufRead> (lines: std::io::Lines<T>) -> u128 {
	let mut stack = Vec::new();
	let mut scores = Vec::new();

	let opening = ['(', '[', '{', '<'];
	let closing = [')', ']', '}', '>'];
	let inv: std::collections::HashMap<char, char> = opening.iter().copied().zip(closing).collect();
	let score_map = HashMap::from([('(', 1), ('[', 2), ('{', 3), ('<', 4)]);

	'line: for s in lines.map(Result::unwrap) {
		stack.clear();

		for c in s.chars() {
			if opening.contains(&c) {
				stack.push(c);
			} else if closing.contains(&c) {
				let end = c;
				if let Some(start) = stack.pop() {
					if inv[&start] != end {
						// line is corrupted
						continue 'line;
					}
				} else {
					panic!("too many closing brackets")
				}
			}
		}

		let mut score = 0;
		//leftover opener stack 
		for c in stack.iter().rev() {
			score = score*5 + score_map[c];
		}
		scores.push(score);
	}
	
	scores.sort_unstable();

	scores[scores.len()/2]
}