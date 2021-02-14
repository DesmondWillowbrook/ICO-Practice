#include <bits/stdc++.h>

using namespace std;

int main () {
	size_t N, M; cin >> N >> M;
	vector<uint> adj_list[N];
	
	for (size_t i = 0; i < M; i++) {
		uint a, b; cin >> a >> b; a--; b--;
		adj_list[a].push_back(b); adj_list[b].push_back(a);
	}

	
}