use std::io::Lines;
use std::str::FromStr;

fn convert_to_int<T: FromStr> (s: &str) -> T {
    match T::from_str(s) {
		Ok(n) => n,
		Err(_) => panic!("Error converting to string"),
	}
}
/*
// credit to: https://stackoverflow.com/a/29570662/10147642
fn vec_to_arr<T, const N: usize>(v: Vec<T>) -> [T; N] {
    v.try_into()
        .unwrap_or_else(|v: Vec<T>| panic!("Expected a Vec of length {} but it was {}", N, v.len()))
}
*/
pub fn part_1<T: std::io::BufRead> (lines: Lines<T>) -> u64 {
	let line = lines.map(Result::unwrap).take(1).next().unwrap();
	let inp = line.split(',').map(convert_to_int::<usize /*range is from 0 to 6*/>);

	let mut fishes: [u64; 9] = inp.fold([0u64; 9], |mut fishes, time| {fishes[time] += 1; fishes});

	for _time in 0..256 {
		let birthing_fish = fishes[0];
		for i in 1..=8 {
			fishes[i - 1] = fishes[i];
		}
		fishes[6] += birthing_fish;
		fishes[8] = birthing_fish;
	}

	fishes.iter().sum()
}