use std::io::Lines;

fn vec_to_arr<T, const N: usize>(v: Vec<T>) -> [T; N] {
    v.try_into()
        .unwrap_or_else(|v: Vec<T>| panic!("Expected a Vec of length {} but it was {}", N, v.len()))
}

fn byte_to_num (b: [u8; 12]) -> u16 {
	b.iter().enumerate().fold(0, |acc, (idx, val)| acc + ((*val as u16) << idx))
}

pub fn part_1<T: std::io::BufRead> (lines: Lines<T>) -> (u16, u16) {
	// first element contains count of total sequences processed
	// second element contains index-wise count of 1's that appeared
	// combining both, we can find index-wise count of 0's as well.
	let (total, bit_count) = lines.map(Result::unwrap).map(String::into_bytes)
		.fold((0u32, [0u32; 12]), |(total, one_count), ele| {
			assert_eq!(ele.len(), 12);

			(total + 1,
			ele.into_iter()
				.enumerate()
				// calling a byte a bit is a rather severe offence, but bear with me,
				// as the byte is SUPPOSED to represent the bit (in this problem).
				.fold(one_count, |mut one_count, (idx, bit)| {
					if bit == b'1' {one_count[idx] += 1};
					one_count
				})
			)
		});

	let (gamma, epsilon) = bit_count.into_iter().zip((0..=11).rev())
		.fold ((0, 0), |(mut gamma, mut epsilon), (one_count, idx)| {
			// equal count case not handled
			if one_count > total / 2 {gamma += 1 << idx}
			else {epsilon += 1 << idx}
			(gamma, epsilon)
		});

	(gamma, epsilon)
}
/* 
use std::ops::Neg

enum MajorityBit {
	One,
	Zero
}
enum MinorityBit {
	One,
	Zero
}

impl From<(u32, u32)> for MajorityBit {
	fn from((one_count, total): (u32, u32)) -> Self {
		if one_count > total / 2 {Self::One}
		else {Self::Zero}
	}
}

impl Neg for MajorityBit {
	type Output = MinorityBit;
	fn neg(self) -> Self::Output {
		match self {
			Self::One => MinorityBit::Zero,
			Self::Zero => MinorityBit::One,
		}
	}
}
*/

pub fn part_2<T: std::io::BufRead> (lines: Lines<T>) -> u16 {
	let diagnostic_report: [[u8; 12]; 1000] = vec_to_arr(lines.map(Result::unwrap).map(String::into_bytes).map(vec_to_arr).collect::<Vec<_>>());

	let (total, one_count) = diagnostic_report.iter()
		.fold((0u32, [0u32; 12]), |(total, one_count), ele| {
			assert_eq!(ele.len(), 12);

			(total + 1,
			ele.iter()
				.enumerate()
				// calling a byte a bit is a rather severe offence, but bear with me,
				// as the byte is SUPPOSED to represent the bit (in this problem).
				.fold(one_count, |mut one_count, (idx, bit)| {
					if *bit == b'1' {one_count[idx] += 1};
					one_count
				})
			)
		});

	let (mut oxygen_candidates, mut co2_candidates) = 
		diagnostic_report.iter()
		.partition::<Vec<&[u8; 12]>, _>(|e| if one_count[0] > total / 2 {e[0] == b'1'} else {e[0] == b'0'});

	for i in 1..12 {
		if oxygen_candidates.len() != 1 {oxygen_candidates.retain(|e| if one_count[i] >= total / 2 {e[i] == b'1'} else {e[i] == b'0'});}
		if co2_candidates.len() != 1 {co2_candidates.retain(|e| if one_count[i] >= total / 2 {e[i] != b'1'} else {e[i] != b'0'});}
	}

	assert! (oxygen_candidates.len() == 1);
	assert! (co2_candidates.len() == 1);

	byte_to_num(*oxygen_candidates[0]) * byte_to_num(*co2_candidates[0])
}