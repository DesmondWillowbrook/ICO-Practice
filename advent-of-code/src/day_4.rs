use std::collections::HashMap;

use itertools::Itertools;

fn convert_to_int<T: std::str::FromStr> (s: &str) -> T {
    match T::from_str(s) {
		Ok(n) => n,
		Err(_) => panic!("Error converting to string"),
	}
}

fn vec_to_arr<T, const N: usize>(v: Vec<T>) -> [T; N] {
    v.try_into()
        .unwrap_or_else(|v: Vec<T>| panic!("Expected a Vec of length {} but it was {}", N, v.len()))
}

const BOARD_LENGTH: usize = 5;

fn parse_board (board: &[[u32; BOARD_LENGTH]]) {
	let rows = board.iter();
}

pub fn part_1<T: std::io::BufRead> (mut lines: std::io::Lines<T>) -> u64 {
	let numbers = lines.next().unwrap().unwrap().split(',').map(convert_to_int::<u32>);
	let occurences: HashMap<u32, ()> = HashMap::new();

	for b in lines.chunks(5).into_iter() {
		let v = vec_to_arr::<_, BOARD_LENGTH>(b.map(Result::unwrap)
			.map(|s| s.split(' ').map(convert_to_int::<u32>).collect::<Vec<_>>())
			.map(vec_to_arr::<_, BOARD_LENGTH>)
			.collect::<Vec<_>>());

		if v.len() != 5 {break;}
		parse_board(&v)
	}

	todo!()
}