#include<bits/stdc++.h>

using namespace std;

int* representative; int* size;
int n;

#ifdef DEBUG
bool* changed = NULL;
#endif

int find_rep (int a) {
	if (representative[a] == representative[representative[a]]) {return representative[a];}
	else {
		representative[a] = find_rep (representative[a]);
		#ifdef DEBUG
		changed[representative[a]] = true;
		#endif
		return representative[a];
	}
}

void union_set (int a, int b) {
	if (find_rep(a) == find_rep(b)) {return;}

	#ifdef DEBUG
	printf ("Union of %d, %d i.e. head nodes %d (size %d) and %d (size %d)\n", a, b, find_rep(a), size[find_rep(a)], find_rep(b), size[find_rep(b)]);
	#endif
	a = find_rep(a);
	b = find_rep(b);

	if (size[a] >= size[b]) {
		#ifdef DEBUG
		changed[representative[a]] = true;
		#endif
		representative[b] = a;
		size[a] += size[b];
	} else {
		#ifdef DEBUG
		changed[representative[b]] = true;
		#endif
		representative[a] = b;
		size[b] += size[a];
	}
}
/*
bool same (int a, int b) {
	if (a != b && (a != representative[a] || b != representative[b])) {
		a = representative[a];
		b = representative[b];
	}
	return a == b;
}
*/
#ifdef DEBUG
void preview_ufds () {
	if (changed == NULL) {
		changed = (bool*) malloc (sizeof(bool) * n);
		fill_n (changed, n, false);
	}

	cout <<         "[index]  ";
	for (int i = 0; i < n; i++) {
		printf ("%d ", i);
	}
	cout << endl << "[parent] ";
	for (int i = 0; i < n; i++) {
		if (changed[i]) {printf ("\033[1m%d\033[0m ", representative[i]);}
		else {printf ("%d ", representative[i]);}
	}
	cout << endl << "[size]   ";
	for (int i = 0; i < n; i++) {
		if (changed[i]) {printf ("\033[1m%d\033[0m ", size[i]);}
		else {printf ("%d ", size[i]);}
	}
	cout << endl;
}
#endif

int main () {
	int q; cin >> n >> q;
	pair<int, pair<int, int>> edges[q];
	bool selected[q]; fill_n (selected, q, false);

	for (int i = 0; i < q; i++) {
		int a, b, w; cin >> a >> b >> w; a--; b--;
		edges[i].first = w; edges[i].second.first = a; edges[i].second.second = b;
	}
	sort (edges, edges + q);
	#ifdef DEBUG
	for (int i = 0; i < q; i++) {
		printf ("[%d](%d, %d)\n", i, edges[i].second.first + 1, edges[i].second.second + 1);
	}
	#endif

	representative = (int*) malloc (sizeof(int) * n);
	for (int i = 0; i < n; i++) {representative[i] = i;}
	size = (int*) malloc (sizeof(int) * n);
	fill_n(size, n, 1);

	for (int i = 0; i < q; i++) {
		#ifdef DEBUG
		if (changed == NULL) {
			changed = (bool*) malloc (sizeof(bool) * n);
		}
		fill_n (changed, n, false);
		#endif

		if (find_rep(edges[i].second.first) != find_rep(edges[i].second.second)) {
			union_set (edges[i].second.first, edges[i].second.second);
			selected[i] = true;
			printf ("(%d, %d) in MST\n", edges[i].second.first, edges[i].second.second);
		} else {
			#ifdef DEBUG
			printf ("(%d, %d) not in MST\n", edges[i].second.first, edges[i].second.second);
			#endif
		}
		#ifdef DEBUG
		preview_ufds ();
		#endif
	}
}