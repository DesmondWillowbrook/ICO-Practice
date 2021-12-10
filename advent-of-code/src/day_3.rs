use std::io::Lines;
use itertools::{self, Itertools};

/*
Gives a different result compared to u32::from_str_radix
fn byte_to_num (b: [u8; 12]) -> u16 {
	b.iter().zip((0..=11).rev()).fold(0, |acc, (idx, val)| acc + (val << idx))
}
*/

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

pub fn part_2<T: std::io::BufRead> (lines: Lines<T>) -> u32 {
	let diagnostic_report =
			lines.map(Result::unwrap)
			.map(
				|s| u32::from_str_radix(&s, 2).unwrap()
			).collect_vec();

	let oxy = (0..12).rev()
		.fold(diagnostic_report.to_vec(), |mut oxy, idx| {
			if oxy.len() == 1 {return oxy};

			let common_bit = 
				if oxy.iter().filter(|e| (*e >> idx) & 1 == 1).count() >= (oxy.len() + 1) / 2 {1} else {0};

			oxy.retain(|e| ((*e >> idx) & 1) == common_bit);

			println!("Common bit in oxy on position {} is: {}", 12-idx-1, common_bit);
			for _ in 0..(12-idx-1) {print!(" ")}; println!("|");
			for ele in &oxy {println!("{:012b}", ele)};
			oxy
		});

	let co2 = (0..12).rev()
		.fold(diagnostic_report.to_vec(), |mut co2, idx| {
			if co2.len() == 1 {return co2};

			let common_bit = 
				if co2.iter().filter(|e| (*e >> idx) & 1 == 1).count() >= (co2.len() + 1) / 2 {1} else {0};

			co2.retain(|e| ((*e >> idx) & 1) != common_bit);
			co2
		});

	assert_eq!(oxy.len(), 1);
	assert_eq!(co2.len(), 1);

	println!("{:012b}\n{:012b}", oxy[0], co2[0]);

	oxy[0] * co2[0]
}