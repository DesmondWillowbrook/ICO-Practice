#include <bits/stdc++.h>

using namespace std;

const long int MAX_ROOM = 1e9;

int main () {
	uint n, m; cin >> n >> m;

	map<uint, priority_queue<uint, vector<uint>, greater<uint>>> frhn;
	for (uint i = 1; i <= n; i++) {
		uint r_num; cin >> r_num;
		frhn[r_num].push(i);
	}

	for (uint i = 1; i <= m; i++) {
		uint room_req; cin >> room_req;
		uint hotel = n + 1; auto frh_ptr = frhn.end();
		for (auto it = frhn.lower_bound(room_req); it != frhn.end(); it++) {
			auto q = (*it).second;
			if (!q.empty() && q.top() < hotel) {
				hotel = q.top();
				frh_ptr = it;
			}
		}
		if (hotel > n) {
			printf ("0\n");
			continue;
		}
		#ifdef DEBUG
		printf("Available smallest hotel %d has %d rooms empty\n", hotel, (*frh_ptr).first);
		#endif
		
		(*frh_ptr).second.pop(); // remove hotel from this queue, as it no longer has the same amount of room
		frhn[(*frh_ptr).first - room_req].push(hotel);
		printf ("%d\n", hotel);
	}
	cout << endl;
}