#include<bits/stdc++.h>

using namespace std;

int main () {
	pair<uint, uint> coordinates {1, 2};
	coordinates = {2, 3};

	tuple<uint, uint, uint> three_d {1, 2, 3};
	cout << get<1>(three_d) << endl;
}