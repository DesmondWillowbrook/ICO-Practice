use std::{io::Lines};

use itertools::Itertools;

fn convert_to_int<T: std::str::FromStr> (s: &str) -> T {
    match T::from_str(s) {
		Ok(n) => n,
		Err(_) => panic!("Error converting to string"),
	}
}

pub fn part_1<T: std::io::BufRead> (lines: Lines<T>) -> isize {
	let line = lines.map(Result::unwrap).take(1).next().unwrap();
	let mut inp = line.split(',').map(convert_to_int::<isize>).collect_vec();

	inp.sort_unstable();
	let median = inp[((inp.len() as f64) / (2f64)).floor() as usize];

	inp.iter().map(|x| *x - median).map(isize::abs).sum()
}

pub fn part_2<T: std::io::BufRead> (lines: Lines<T>) -> i64 {
	let line = lines.map(Result::unwrap).take(1).next().unwrap();
	//return part2(line);

	let mut inp = line.split(',').map(convert_to_int::<i64>).collect_vec();

	inp.sort_unstable();
	let average: i64 = (inp.iter().copied().sum::<i64>() as f64 / inp.len() as f64).floor() as i64;

	(average - 1..average + 1).map(|x|
		inp.iter().map(|n| (*n - x).abs()).map(|dist| (dist * (dist + 1)) / 2).sum()
	).min().unwrap()
}