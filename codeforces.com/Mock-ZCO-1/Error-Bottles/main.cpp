#include <bits/stdc++.h>

using namespace std;

int main () {
	int a_max, b_max;
	int k, l; cin >> a_max >> b_max >> k >> l;
	
	int min_error = l;

	map<pair<int, int>, bool> visited;
	queue<pair<int, pair<int, int>>> q;
	q.push({0, {0, 0}});

	while (!q.empty()) {		
		pair<int, int> curr = q.front().second;
		int step = q.front().first;
		q.pop();

		min_error = min (min_error, abs(l - (curr.first + curr.second)));

		if (step == k) continue;

		if (visited[{a_max, curr.second}] != true) {
			visited[{a_max, curr.second}] = true;
			q.push({step + 1, {a_max, curr.second}});
		}

		if (visited[{curr.first, b_max}] != true) {
			visited[{curr.first, b_max}] = true;
			q.push({step + 1, {curr.first, b_max}});
		}

		if (visited[{0, curr.second}] != true) {
			visited[{0, curr.second}] = true;
			q.push({step + 1, {0, curr.second}});
		}

		if (visited[{curr.first, 0}] != true) {
			visited[{curr.first, 0}] = true;
			q.push({step + 1, {curr.first, 0}});
		}

		if (visited[{min (a_max, curr.second), max (curr.second - a_max, 0)}] != true) {
			visited[{min (a_max, curr.second), max (curr.second - a_max, 0)}] = true;
			q.push({step + 1, {min (a_max, curr.second), max (curr.second - a_max, 0)}});
		}

		if (visited[{max (curr.first - b_max, 0), min (b_max, curr.first)}] != true) {
			visited[{max (curr.first - b_max, 0), min (b_max, curr.first)}] = true;
			q.push({step + 1, {max (curr.first - b_max, 0), min (b_max, curr.first)}});
		}
	}

	cout << min_error << endl;
}