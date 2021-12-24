#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
void print_segtree(int* segtree, uint power_of_two) {
	for (uint i = 0, pow_two = 1; i < power_of_two; i++) {
		printf ("%02d ", i);
		if (i == pow_two - 1) {
			printf ("| ");
			pow_two *= 2;
		}
	}
	cout << endl;
	for (uint i = 0, pow_two = 1; i < power_of_two; i++) {
		printf ("%02d ", segtree[i]);
		if (i == pow_two - 1) {
			printf ("| ");
			pow_two *= 2;
		}
	}
	cout << endl;
}
#endif

int main () {
	uint n, m; cin >> n >> m;

	// number of free rooms to minimum hotel number mapping
	uint power_of_two = 1; while (power_of_two < n) {power_of_two *= 2;}
	int segtree[2 * power_of_two]; segtree[0] = -1; // not used
	for (uint i = power_of_two; i < power_of_two+n; i++) {
		uint r_num; cin >> r_num;
		segtree[i] = r_num;
	
	}
	// insert padding
	for (uint i = power_of_two+n; i < 2 * power_of_two; i++) {
		segtree[i] = -1;
	}

	//construct tree
	for (int i = 2*power_of_two - 2; i >= 1; i -= 2) {
		segtree[i/2] = max(segtree[i], segtree[i + 1]);
	}

	#ifdef DEBUG 
	print_segtree(segtree, 2*power_of_two);
	#endif


	for (uint i = 1; i <= m; i++) {
		int room_req; cin >> room_req;
		#ifdef DEBUG
		printf ("Required rooms: %d\n", room_req);
		#endif
		
		// check if there is no hotel with enough rooms
		if (segtree[1] < room_req) {
			printf ("0");
			#ifndef DEBUG
			cout << " ";
			#endif
			#ifdef DEBUG
			cout << endl;
			#endif
			continue;
		}

		uint idx = 1;
		while (idx < power_of_two) {
			#ifdef DEBUG
			printf ("Current idx: %02d, max val: %d\n", idx, segtree[idx]);
			#endif
			if (segtree[2 * idx] < room_req) { //if right side smaller than required
				idx = (idx*2) + 1; //then go to left side
			} else if (segtree[2 * idx + 1] < room_req) { //if left side smaller than required
				idx = idx*2; //then go to right side
			} else { //if both sides have more than required
				idx = idx*2; //then go to right side: it will have smaller hotel number
			}
		}

		int hotel = idx - power_of_two + 1;
		segtree[idx] -= room_req;

		#ifdef DEBUG
		printf ("Smallest hotel with req rooms: %d (index %d)\nUpdating segtree\n", hotel, idx);
		#endif

		//update tree
		idx /= 2;
		for (; idx >= 1; idx /= 2) {
			segtree[idx] = max(segtree[2*idx], segtree[2*idx + 1]);
		}

		#ifdef DEBUG 
		print_segtree(segtree, 2*power_of_two);
		#endif

		printf ("%d", hotel);

		#ifndef DEBUG
		cout << " ";
		#endif
		#ifdef DEBUG
		cout << endl;
		#endif
	}
	cout << endl;
}