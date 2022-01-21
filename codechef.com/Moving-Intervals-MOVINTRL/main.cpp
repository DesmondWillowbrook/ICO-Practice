#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
void vector_print (vector<pair<uint, uint>>& cakes) {
	for (uint i = 0; i < cakes.size(); i++) {
		printf (" %d     ", i);
	}
	cout << endl;
	for (uint i = 0; i < cakes.size(); i++) {
		printf ("(%d, %d) ", cakes[i].first, cakes[i].second);
	}
	cout << endl;
}
#endif

bool adjust (uint c, vector<pair<uint, uint>>& cakes, uint to_adjust) {
	pair<uint, uint> ele = *(cakes.begin() + to_adjust);
	cakes.erase(cakes.begin() + to_adjust);

	#ifdef DEBUG
	printf ("Erased the cake at %d\n", to_adjust);
	vector_print (cakes);
	#endif
	
	uint max_gap = max(cakes.front().first - 1, c - cakes.back().second), gap_prev_range_ind = 1;

	for (uint i = 1; i < cakes.size(); i++) {
		if (max_gap < cakes[i].first - cakes[i - 1].second - 1) {
			#ifdef DEBUG
			printf ("Current max gap was %d, new larger gap found between (%d, %d) and (%d, %d)\n",
				max_gap, cakes[i - 1].first, cakes[i - 1].second, cakes[i].first, cakes[i].second);
			#endif

			max_gap = cakes[i].first - cakes[i - 1].second - 1;
			gap_prev_range_ind = i - 1;
		}
	}

	if (max_gap >= ele.second - ele.first + 1) {
		cakes.emplace(cakes.begin() + gap_prev_range_ind + 1,
			make_pair(cakes[gap_prev_range_ind].second + 1, cakes[gap_prev_range_ind].second + max_gap - 1));

		#ifdef DEBUG
		printf ("Largest gap found to settle (%d, %d) (length %d) in is %d long at (%d, %d)\n",
			ele.first, ele.second, ele.second - ele.first + 1,
			max_gap, cakes[gap_prev_range_ind].second + 1, cakes[gap_prev_range_ind].second + max_gap
		);
		
		printf ("Vec after shuffle\n");
		vector_print (cakes);
		#endif

		return true;
	} else {
		#ifdef DEBUG
		printf ("No suitable placement for (%d, %d) found, putting it back.\n", ele.first, ele.second);
		vector_print(cakes);
		#endif

		cakes.emplace(cakes.begin() + to_adjust, ele);
		return false;
	}
}

int main () {
	uint t; cin >> t;
	while (t--) {
		//check for fight
		uint c, n, k; cin >> c >> n >> k;
		vector<pair<uint, uint>> cakes; cakes.reserve(n);
		for (uint i = 0; i < n; i++) {
			uint tmp1, tmp2; cin >> tmp1 >> tmp2; cakes.push_back({tmp1, tmp2});
		}

		sort(cakes.begin(), cakes.end());
		bool broken = false;
		for (uint i = 1; i < cakes.size(); i++) {
			if (cakes[i - 1].second >= cakes[i].first) { //cake overlap
				#ifdef DEBUG
				printf ("Cake overlap found! (%d, %d) and (%d, %d)\n",
					cakes[i - 1].first, cakes[i - 1].second, cakes[i].first, cakes[i].second
				);
				#endif

				if (k == 1 && (adjust(c, cakes, i - 1) || adjust(c, cakes, i))) {
					k--;
				} else {
					cout << "Bad" << endl;
					broken = true;
					break;
				}
			}
		}
		if (!broken) {
			cout << "Good" << endl;
		}
	}
}