#include <bits/stdc++.h>

using namespace std;

size_t N;

vector<vector<uint>> a (75, vector<uint> (75, 0));
vector<vector<uint>> b (75, vector<uint> (75, 0));
vector<vector<uint>> c (75, vector<uint> (75, 0));

#ifdef DEBUG
const uint space_len = 6;
template <typename T>
T uniform_spacing_print (T n) {
    for (int len = space_len - to_string(n).length(); len > 0; len--) cout << " ";
    return n;
}

void print_grid (vector<vector<uint>>& g) {
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < N; j++)
			printf ("%d ", uniform_spacing_print(g[i][j]));
		printf ("\n");
	}
}
#endif

void clear_grid (vector<vector<uint>>& g) {
	for (size_t i = 0; i < N; i++) for (size_t j = 0; j < N; j++) g[i][j] = 0;
}

// multiplies a by b, stores result in res
void matrix_mult (vector<vector<uint>>& a, vector<vector<uint>>& b, vector<vector<uint>>& res) {
	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < N; j++)
			for (size_t k = 0; k < N; k++)
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % 42373;
	
	#ifdef DEBUG
	printf ("Multiplying matrices. Res is:\n");
	print_grid (res);
	#endif
}

// exponentiates matrix by power N
void smart_mod_exp (uint n) {
	if (n == 1 || n == 0) return;

	#ifdef DEBUG
	printf ("Evaluating matrix ^ %d\n", n);
	#endif

	smart_mod_exp (n / 2);
	matrix_mult (a, a, b); swap (a, b); // squares a
	if (n % 2 == 1) {
		matrix_mult (a, b, c); swap (a, c);
	}
}

int main () {
	cin >> N;

	for (size_t i = 0; i < N; i++) for (size_t j = 0; j < N; j++) cin >> a[i][j];
	size_t K; uint S, T; cin >> S >> T >> K;

	smart_mod_exp (K);
	cout << a[S - 1][T - 1] << endl;
}