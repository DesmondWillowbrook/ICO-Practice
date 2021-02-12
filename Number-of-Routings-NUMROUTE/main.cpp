// built using matrix exponentiation!

#include <bits/stdc++.h>

using namespace std;

size_t N;

typedef vector<uint> row;
typedef vector<row> matrix;

matrix a (120, row (120, 0));
matrix b (120, row (120, 0));
matrix c (120, row (120, 0));

#ifdef DEBUG
const uint space_len = 6;
template <typename T>
T uniform_spacing_print (T n) {
    for (int len = space_len - to_string(n).length(); len > 0; len--) cout << " ";
    return n;
}

void print_grid (matrix& g) {
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < N; j++)
			printf ("%d ", uniform_spacing_print(g[i][j]));
		printf ("\n");
	}
}
#endif

void clear_grid (matrix& g) {
	for (size_t i = 0; i < N; i++) for (size_t j = 0; j < N; j++) g[i][j] = 0;
}

// multiplies a by b, stores result in res
void matrix_mult (matrix& a, matrix& b, matrix& res) {
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

	if (n % 2 == 1) {
		smart_mod_exp (n - 1);
		matrix_mult (a, b, c); swap (a, c); // produces a^3
	} else {
		smart_mod_exp (n / 2);
		matrix_mult (a, a, b); swap (a, b);
	}
}

int main () {
	cin >> N;

	for (size_t i = 0; i < N; i++) for (size_t j = 0; j < N; j++) cin >> a[i][j];
	size_t K; uint S, T; cin >> S >> T >> K;

	smart_mod_exp (K);
	cout << a[S - 1][T - 1] % 42373 << endl;
}