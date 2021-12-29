use std::collections::VecDeque;
use itertools::Itertools;

fn vec_to_arr<T, const N: usize>(v: Vec<T>) -> [T; N] {
    v.try_into()
        .unwrap_or_else(|v: Vec<T>| panic!("Expected a Vec of length {} but it was {}", N, v.len()))
}

const FIELD_WIDTH: usize = 10;
const FIELD_HEIGHT: usize = 10;

pub fn part_1<T: std::io::BufRead> (lines: std::io::Lines<T>) -> usize {
	let mut oct = vec_to_arr::<_, FIELD_HEIGHT>(
		lines.map(Result::unwrap)
		.map(|s| 
			s.as_bytes().iter().map(|a| a - b'0').collect_vec()
		).map(vec_to_arr::<_, FIELD_WIDTH>).collect_vec());
	
	let mut ans = 0;
	for _ in 0..100 {
		for mut row in oct {
			for cell in row.iter_mut() {
				*cell += 1;
			}
		}

		let mut queue = 
			VecDeque::from_iter(
				oct.iter().flat_map(|r|
					r.iter().enumerate()
				).enumerate().map(|t| ((t.0, t.1.0), t.1.1))
				.filter(|t| *t.1 > 9)
				.map(|c| (c.0.0, c.0.1))
			);

		let mut flashed = [[false; FIELD_WIDTH]; FIELD_HEIGHT];

		while let Some((h, w)) = queue.pop_front() {
			if oct[h][w] > 9 {
				// flash, add neighbours to stack
				oct[h][w] = 0;
				flashed[h][w] = true;
				ans += 1;

				for n in [h - 1, h, h + 1] {
					for m in [w - 1, w, w + 1] {
						if n == 0 && m == 0 {continue;}
						if let Some(r) = oct.get(n) {
							if r.get(m).is_some() && !flashed[n][m] {
								oct[n][m] += 1;
								queue.push_back((h, w));
							}
						}
					}
				}
			}
		}
	}

	ans
}