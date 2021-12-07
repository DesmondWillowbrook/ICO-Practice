use advent_of_code::*;
use std::fs::File;
use std::io::{BufRead, BufReader};

/*
refer to https://www.ecorax.net/macro-bunker-1/ for creating a macro
to hold functions in a table in similar fashion to:
let mut solutions[50][2]: Fn(_) -> _; (however one typed function types)
solutions[0][0] = day_1::part_1;

use structopt::StructOpt;

#[derive(structopt::StructOpt)]
struct Args {
	/// The day to run (0-50)
	day: u32,
	/// The part of said day to run (0 or 1)
	part: i32,
}
*/

fn main () {
	let file = File::open("input/day_7/in.txt").unwrap();
	let lines = BufReader::new(file).lines();
	println!("{:#?}", day_7::part_2(lines));
}