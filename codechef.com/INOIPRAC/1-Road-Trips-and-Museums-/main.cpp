#include<bits/stdc++.h>

using namespace std;

int main () {
	int t; cin >> t;
	while (t--) {
		int n, m, k; cin >> n >> m >> k;

		vector<int> edges[n];
		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v; u--; v--;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		int museums[n];
		for (int i = 0; i < n; i++) {
			cin >> museums[i];
		}

		vector<long int> cities; //<museum number, node>
		bool visited[n]; fill_n (visited, n, false);

		// calculate total museums reachable by a node
		// which hasn't been visited yet.
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				stack<int> st; st.push(i);
				visited[i] = true;

				long int museum_sum = 0;
				while (!st.empty()) {
					int s = st.top(); st.pop();
					#ifdef DEBUG
					printf ("Visited city %d which has %d museums\n", s + 1, museums[s]);
					#endif

					museum_sum += museums[s];

					for (int n : edges[s]) {
						if (!visited[n]) {
							visited[n] = true;
							st.push(n);
						}
					}
				}
				cities.push_back(museum_sum);
				#ifdef DEBUG
				printf ("%ld total museums reachable from city %d\n", museum_sum, i);
				#endif
			}
		}
		sort(cities.begin(), cities.end());

		bool curr_lav = true;
		long int museum_sum = 0;
		int lav_ind = cities.size() - 1, nikh_ind = 0;
		while (k--) {
			if (lav_ind < nikh_ind) {
				museum_sum = -1;
				break;
			}
			if (curr_lav) {
				museum_sum += cities[lav_ind];
				lav_ind--;
			} else {
				museum_sum += cities[nikh_ind];
				nikh_ind++;
			}
			curr_lav = !curr_lav;
		}
		cout << museum_sum << endl;
	}	
}