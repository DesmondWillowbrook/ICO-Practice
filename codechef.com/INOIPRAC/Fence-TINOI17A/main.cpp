#include<bits/stdc++.h>

using namespace std;

int main () {
	int r, c, n; cin >> r >> c >> n;

	vector<pair<int, int>> nodes; nodes.reserve(n);
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		nodes.push_back(make_pair(x, y));
	}
	sort(nodes.begin(), nodes.end());
	set<pair<int, int>> visited;
	long int ans = 0;

	// graph search problem, only that node connectivity (finding edges) is a bit more difficult
	for (pair<int, int> n : nodes) {
		if (visited.find(n) == visited.end()) {
			// not visited
			long int peri = 0;
			stack<pair<int, int>> st; st.push(n);
			visited.insert(n);

			while (!st.empty()) {
				pair<int, int> s = st.top(); st.pop();
				#ifdef DEBUG
				printf ("Exploring connected nodes of (%d, %d)\n", s.first, s.second);
				#endif
				int neighbours = 0;
				// we could probably further optimize neightbour checking
				// by mainting two sorted arrays with different sort comparators.

				//check sideways
				//by pair sorting criteria, these three points will be sorted as follows: 
				// (s.first) {s.second - 1, s.second, s.second + 1}
				// if s.second - 1 is out of bounds, then lower_bound will return {s.first, s.second}
				// to which we can add to find if s.second + 1 exists
				// otherwise if s.second - 1 DOES exist, we can add once more to find if 
				// s.second + 1 exists
				auto left = lower_bound(nodes.begin(), nodes.end(), make_pair(s.first, s.second-1));
				assert(left != nodes.end());

				if (*left == make_pair(s.first, s.second - 1)) {
					#ifdef DEBUG
					printf ("Found connected component (%d, %d)\n", (*left).first, (*left).second);
					#endif
					if (visited.find(*left) == visited.end()) {
						st.push(*left); visited.insert(*left);
					}
					neighbours++;
					left++; // now on {s.first, s.second}
				}
				auto right = left + 1;
				if (right != nodes.end() && *right == make_pair(s.first, s.second + 1)) {
					#ifdef DEBUG
					printf ("Found connected component (%d, %d)\n", (*right).first, (*right).second);
					#endif
					if (visited.find(*right) == visited.end()) {
						st.push(*right); visited.insert(*right);
					}
					neighbours++;
				}

				//check down
				auto down = lower_bound(nodes.begin(), nodes.end(), make_pair(s.first - 1, s.second));
				assert(down != nodes.end());

				if (*down == make_pair(s.first - 1, s.second)) {
					#ifdef DEBUG
					printf ("Found connected component (%d, %d)\n", (*down).first, (*down).second);
					#endif
					if (visited.find(*down) == visited.end()) {
						st.push(*down); visited.insert(*down);
					}
					neighbours++;
				}
				//check up
				auto up = lower_bound(nodes.begin(), nodes.end(), make_pair(s.first + 1, s.second));
				if (up != nodes.end() && *up == make_pair(s.first + 1, s.second)) {
					#ifdef DEBUG
					printf ("Found connected component (%d, %d)\n", (*up).first, (*up).second);
					#endif
					if (visited.find(*up) == visited.end()) {
						st.push(*up); visited.insert(*up);
					}
					neighbours++;
				}

				peri += 4 - neighbours;
			}
			#ifdef DEBUG
			printf ("Total perimeter of block is %ld\n", peri);
			#endif
			ans = max(ans, peri);
		}		
	}
	cout << ans << endl;
}