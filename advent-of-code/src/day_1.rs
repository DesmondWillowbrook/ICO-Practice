use std::io::Lines;
use itertools::Itertools;

fn convert_to_int (s: String) -> u32 {
    s.parse::<u32>().expect("Error converting to int")
}

pub fn part_1<T: std::io::BufRead> (lines: Lines<T>) -> usize {
	lines
	.map(Result::unwrap)
	.map(convert_to_int)
	.tuple_windows::<(_, _)>()
	//.fold(0, |acc, curr| if curr.0 < curr.1 {acc + 1} else {acc});
	.filter(|c| c.1 > c.0)
	.count()
}

pub fn part_2<T: std::io::BufRead> (lines: Lines<T>) -> usize {
	lines
	.map(Result::unwrap)
	.map(convert_to_int)
	.tuple_windows::<(_, _, _)>()
	.map(|t| t.0 + t.1 + t.2)
	.tuple_windows::<(_, _)>()
	//.fold(0, |acc, curr| if curr.0 < curr.1 {acc + 1} else {acc});
	.filter(|c| c.1 > c.0)
	.count()
}