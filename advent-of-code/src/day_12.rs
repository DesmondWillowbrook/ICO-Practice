use std::{ops::{Index, IndexMut}, cmp::max, collections::HashMap};
use itertools::Itertools;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum Node {
	Small(usize),
	Large(usize),
	Start,
	End
}

impl<T> Index<Node> for [T] {
	type Output = T;
	fn index(&self, index: Node) -> &Self::Output {
		&self[usize::from(index)]
	}
}

impl From<Node> for usize {
    fn from(n: Node) -> Self {
        match n {Node::Start => 0, Node::End => 1, Node::Small(n) | Node::Large(n) => n}
    }
}

impl<T> IndexMut<Node> for [T] {
	fn index_mut(&mut self, index: Node) -> &mut Self::Output {
		&mut self[usize::from(index)]
	}
}

fn trace (node: Node, out: &[Vec<Node>], small_caves_explored: &mut Vec<bool>) -> u64 {
	let mut ans = 0;

	println!("Current node is {}", usize::from(node));
	println!("Outbound nodes: {:?}", &out[node]);

	for o in &out[node] {
		ans += match o {
			Node::Small(_) => if !small_caves_explored[usize::from(*o)] {
				small_caves_explored[usize::from(*o)] = true;
				let ret = trace (*o, out, small_caves_explored);
				small_caves_explored[usize::from(*o)] = false;
				ret
			} else {0},
			Node::Large(_) => trace (*o, out, small_caves_explored),
			Node::End => 1,
			Node::Start => 0,
		};
	};

	ans
}

pub fn part_1<T: std::io::BufRead> (lines: std::io::Lines<T>) -> u64 {
	let mut hs = HashMap::from([("start", Node::Start), ("end", Node::End)]);

	let mut edges: Vec<Vec<Node>> = vec![vec![], vec![]];
	let lines = lines.map(Result::unwrap).collect_vec();
	
	for l in lines.iter().map(|s| s.as_str()) {
		let (e1, e2) = 
			l.split('-')
				.map(|s| {
					if hs.contains_key(s) {return hs[s]}

					hs.insert(s, if s.chars().next().unwrap().is_uppercase() {
						 Node::Large(hs.len())
					} else {
						Node::Small(hs.len())
					});
					hs[&s]
				})
				.collect_tuple().unwrap();

		if edges.len() <= max(e1.into(), e2.into()) {
			let required_len = max(<usize>::from(e1),  <usize>::from(e2)) + 1;

			edges.extend((0..(required_len - edges.len())).map(|_| Vec::new()))
		}		
		edges.as_mut_slice()[e1].push(e2);
		edges.as_mut_slice()[e2].push(e1);
	}

	println!("{:?}", &edges);

	//vec![false; edges.len()] is upper bound on number of small nodes. we could count small nodes separately
	//to preserve memory, but I don't want to riddle this already ugly code with more C++-like writing
	trace(Node::Start, &edges, &mut vec![false; edges.len()])
}