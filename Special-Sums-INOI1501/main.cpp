#include <bits/stdc++.h>

using namespace std;

int main () {
	size_t N; cin >> N;
	long int a[N], b[N];
	for (size_t i = 0; i < N; i++) cin >> a[i];
	for (size_t i = 0; i < N; i++) cin >> b[i];

	/*
	Observation: Question is split into three cases:
	Case 1: i < j: Then, SSum (i, j) = a[i] + (b_sum_till[j - 1] - b_sum_till[i + 1]) + a[j]
	Case 2: i > j: SSum (i, j) = a[i] + ((b_sum_till[N] - b_sum_till[i]) + b_sum_till[j]) + a[j]
	Case 3: i = j: SSum (i, j) = a[i]
	*/
}