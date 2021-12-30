#include <bits/stdc++.h>

using namespace std;

enum st_type {
	NE = 1,
	E = 2,
};

struct statement {
	enum st_type type;
	int target;
};

enum astro_type {
	UNSET = 0,
	RED,
	GREEN,
};

enum astro_type invert_type (enum astro_type t) {
	if (t == RED) {
		return GREEN;
	} else if (t == GREEN) {
		return RED;
	} else {
		printf ("Invert called on unset astro\n");
		return UNSET;
	}
}

struct astro {
	vector<struct statement> sts;
	enum astro_type type;
};

#ifdef DEBUG
const char* stringify_astro_type (enum astro_type t) {
	switch (t) {
		case RED: return "RED";
		case GREEN: return "GREEN";
		case UNSET: return "UNSET";
	}
	return "SOMETHING HAS GONE TERRIBLY WRONG";
}
#endif

int main () {
	int t; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		struct astro astros[n];
		for (int i = 0; i < n; i++) {
			astros[i].type = UNSET;
		}

		for (int i = 0; i < q; i++) {
			int type, origin, target;
			cin >> type >> origin >> target; origin--; target--;
			astros[origin].sts.push_back(statement {type: (st_type) type, target: target});
			astros[target].sts.push_back(statement {type: (st_type) type, target: origin});
		}

		bool broken = false; bool visited[n]; fill_n(visited, n, false);
		int ans = 0;

		for (int i = 0; i < n && broken == false; i++) {
			queue<int> d; d.push(i);
			if (astros[i].type == UNSET) {
					#ifdef DEBUG
					printf ("(INIT) A%d = UNSET;", i);
					#endif
					astros[i].type = RED;
				}
			int red_count = 0, green_count = 0;

			while (!d.empty() && broken == false) {
				auto astro = d.front(); d.pop();
				if (visited[astro] == true) {continue;}
				visited[astro] = true;

				#ifdef DEBUG
				printf ("\nA%d = %s\n", astro, stringify_astro_type(astros[astro].type));
				#endif

				if (astros[astro].type == RED) {red_count++;}
				else if (astros[astro].type == GREEN) {green_count++;}

				// verify coloring
				for (auto st : astros[astro].sts) {
					#ifdef DEBUG
					printf ("?: A%d (%s) ",
						astro, stringify_astro_type(astros[astro].type));
					#endif
					if (st.type == E) {
						#ifdef DEBUG
						printf ("== A%d (%s)\n", st.target, stringify_astro_type(astros[st.target].type));
						#endif
						if (astros[st.target].type == UNSET) {
							#ifdef DEBUG
							printf ("A%d = UNSET; A%d = %s\n",
								st.target, st.target, stringify_astro_type(astros[astro].type)
							);
							#endif
							astros[st.target].type = astros[astro].type;
							if (!visited[st.target]) {d.push(st.target);}
						} else if (!(astros[astro].type == astros[st.target].type)) { //contradiction
							#ifdef DEBUG
							printf ("FAIL: A%d (%s) != A%d (%s)\n",
								astro, stringify_astro_type(astros[astro].type),
								st.target, stringify_astro_type(astros[st.target].type)
							);
							#endif
							cout << "-1" << endl;
							broken = true;
							break;
						}
					} else if (st.type == NE) {
						#ifdef DEBUG
						printf ("!= A%d (%s)\n", st.target, stringify_astro_type(astros[st.target].type));
						#endif
						if (astros[st.target].type == UNSET) {
							#ifdef DEBUG
							printf ("A%d = UNSET; A%d = %s\n",
								st.target, st.target, stringify_astro_type(invert_type(astros[astro].type))
							);
							#endif
							astros[st.target].type = invert_type(astros[astro].type);
							if (!visited[st.target]) {d.push(st.target);}
						} else if (!(astros[astro].type != astros[st.target].type)) { // contradiction
							#ifdef DEBUG
							printf ("FAIL: A%d (%s) == A%d (%s)\n",
								astro, stringify_astro_type(astros[astro].type),
								st.target, stringify_astro_type(astros[st.target].type)
							);
							#endif
							cout << "-1" << endl;
							broken = true;
							break;
						}
					}
				}
			}
			ans += max(red_count, green_count);
		}
		if (!broken) {
			cout << ans << endl;
		}
		#ifdef DEBUG
		cout << endl;
		#endif
	}
}