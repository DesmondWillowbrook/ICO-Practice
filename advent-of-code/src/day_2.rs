use std::io::Lines;

fn convert_to_int (s: &str) -> isize {
    s.parse::<isize>().expect("Error converting to int")
}

pub fn part_1<T: std::io::BufRead> (lines: Lines<T>) -> isize {
	let mut depth: isize = 0; let mut hor: isize = 0;

	for line in lines.map(Result::unwrap) {
		let mut spl= line.split(' ');
		let command = spl.next().unwrap();
		let val = convert_to_int(spl.next().unwrap());

		if command == "forward" {
			hor += val;
		} else if command == "down" {
			depth += val;
		} else if command == "up" {
			depth -= val;
		}
	}

	depth * hor
}

pub fn part_2<T: std::io::BufRead> (lines: Lines<T>) -> isize {
	let mut depth: isize = 0; let mut hor: isize = 0; let mut aim = 0;

	for line in lines.map(Result::unwrap) {
		let mut spl= line.split(' ');
		let command = spl.next().unwrap();
		let val = convert_to_int(spl.next().unwrap());

		if command == "forward" {
			hor += val;
			depth += aim * val;
		} else if command == "down" {
			aim += val;
		} else if command == "up" {
			aim -= val;
		}
	}

	depth * hor
}