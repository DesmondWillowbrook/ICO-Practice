#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> blocks;
uint N;

bool path_possible (int x, int y) {
	if (x == 1 && y == 1) return true;
	if (x < 1 || y < 1 || binary_search(blocks.begin(), blocks.end(), make_pair(x, y))) return false;

	if (path_possible(x-1, y) || path_possible(x, y-1)) return true;
	else return false;
}

int main () {
	uint t; cin >> t;
	while (t--) {
		blocks.clear();

		cin >> N; blocks.reserve(N);
		for (uint i = 0; i < N; i++) {
			pair<uint, uint> block_pos; cin >> block_pos.first >> block_pos.second;
			blocks.push_back(block_pos);
		}
		sort(blocks.begin(), blocks.end());

		if (path_possible(N, N)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}