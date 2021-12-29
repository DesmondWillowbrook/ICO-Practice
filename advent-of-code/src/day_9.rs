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

pub fn part_1<T: std::io::BufRead> (mut lines: std::io::Lines<T>) -> u64 {
	lines.map(Result::unwrap);
	todo!()
}