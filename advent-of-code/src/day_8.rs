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

pub fn part_1<T: std::io::BufRead> (mut lines: std::io::Lines<T>) -> u64 {
	let inp = lines.map(Result::unwrap);
	
	let mut ans = 0;

	for line in inp {
		let (patterns, output) = line.split('|').map(str::trim)
			.tuples()
			.map(|(a, b)| (a.split(' ').map(str::trim).collect::<Vec<_>>(), b.split(' ')
			.collect::<Vec<_>>())).next().unwrap();
		
		dbg!(&output);
		for o in output {
			if [3, 2, 4, 7].contains(&o.len()) {
				ans+=1;
			}
		}
		dbg!(&ans);
	}

	ans
}

fn intersect (a: &[u8; 7], b: &[u8; 7], c: &[u8]) -> u8 {
	assert_eq!(c.len(), 7);

	let mut dissimilarity = 0;
	for i in 0..7 {
		if a[i] != c[i] || b[i] != c[i] {dissimilarity += 1}
	}
	dissimilarity
}

fn find_union<'a> (a: &'a [char], b: &'a [char]) -> Vec<&'a char> {
	a.iter().chain(b.iter()).unique().collect_vec()
}

fn find_intersection (a: &[char], b: &[char]) -> Vec<char> {
	//a.iter().chain(b.iter()).fold([0u8; 7], |arr, c| {arr[char_to_idx(c)] += 1; arr} )
	todo!()
}

fn char_to_idx (c: char) -> u8 {
	(c as u8) - b'a'
}

pub fn part_2<T: std::io::BufRead> (mut lines: std::io::Lines<T>) -> u64 {
	let inp = lines.map(Result::unwrap);
	
	let digit_to_wire: [[u8; 7]; 10] = [
	//         a  b  c  d  e  f  g
		/*0*/ [1, 1, 1, 0, 1, 1, 1],
		/*1*/ [0, 0, 1, 0, 0, 1, 0],
		/*2*/ [1, 0, 1, 1, 1, 0, 1],
		/*3*/ [1, 0, 1, 1, 0, 1, 1],
		/*4*/ [0, 1, 1, 1, 0, 1, 0],
		/*5*/ [1, 1, 0, 1, 0, 1, 1],
		/*6*/ [1, 0, 1, 1, 1, 1, 1],
		/*7*/ [1, 0, 1, 0, 0, 1, 0],
		/*8*/ [1, 1, 1, 1, 1, 1, 1],
		/*9*/ [1, 1, 1, 1, 0, 1, 1],
	];


	let mut ans = 0;

	for line in inp {
		let (patterns, output) = line.split('|').map(str::trim)
			.tuples()
			.map(|(a, b)| (a.split(' ').map(str::trim).collect::<Vec<_>>(), b.split(' ')
			.collect::<Vec<_>>())).next().unwrap();
		
		dbg!(&output);
		let mut digit_to_string = HashMap::new();

		for o in &output {
			if o.len() == 3 {
				digit_to_string.insert(7, o);
			} else if o.len() == 2 {
				digit_to_string.insert(1, o);
			} else if o.len() == 4 {
				digit_to_string.insert(4, o);
			}
		}

		for o in output {
			if intersect(&digit_to_wire[7], &digit_to_wire[4], o.as_bytes()) == 1{
				// found 9
			}
		}
	}

	ans
}