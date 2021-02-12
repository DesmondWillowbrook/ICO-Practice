#include <bits/stdc++.h>

using namespace std;

auto grid = new vector<vector<uint>>, aux = new vector<vector<uint>>;

void clear_grid (vector<vector<uint>>& g) {
	for (size_t i = 0; i < 75; i++) for (size_t j = 0; j < 75; j++) g[i][j] = 0;
}

void init_grid (vector<vector<uint>>& g) {
	for (size_t i = 0; i < 75; i++) g[i] = vector<uint> (75, 0);
}

void matrix_mult () {
	clear_grid(*aux);
	for (size_t i = 0; i < 75; i++)
		for (size_t j = 0; j < 75; j++)
			for (size_t k = 0; k < 75; k++)
				(*aux)[i][j] = ((*aux)[i][j] + (*grid)[i][k] * (*grid)[k][j]) % 42373;
	swap (grid, aux);
}

int main () {
	size_t N, K; uint S, T;
	cin >> N;

	for (size_t i = 0; i < N; i++) for (size_t j = 0; j < N; j++) cin >> (*grid)[i][j];
	cin >> S >> T >> K;

	
}