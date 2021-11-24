#include <bits/stdc++.h>

using namespace std;

const size_t MAX_N = 301;

bool visited[MAX_N];
vector<uint> adj_list[MAX_N];

void dfs (uint src) {
	visited[src] = true;
	for (auto neighbour: adj_list[src])
		if (!visited[neighbour]) dfs (neighbour);
}

int main () {
	size_t N, M; cin >> N >> M;

	for (size_t i = 0; i < M; i++) {
		uint a, b; cin >> a >> b; a--; b--;
		adj_list[a].push_back(b); adj_list[b].push_back(a);
	}

	vector<uint> crit_ints;

	for (size_t forbidden = 0; forbidden < N; forbidden++) {
		fill_n (visited, N, false); visited[forbidden] = true;
		dfs ((forbidden + 1) % N); // DFS from ANYWHERE other than forbidden
		for (size_t i = 0; i < N; i++) if (!visited[i]) {crit_ints.push_back(forbidden + 1); break;}
	}

	cout << crit_ints.size() << endl;
	for (size_t i = 0; i < crit_ints.size(); i++) cout << crit_ints[i] << endl;
}