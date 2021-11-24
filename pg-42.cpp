#include <bits/stdc++.h>
#define REP(i, a, b) for (long int i = a; i < b; i++)
using namespace std;

int binsearch_1 (int* arr, uint n, int target) {
	int lo = 0, hi = n - 1, mid = (lo+hi)/2;
	while (lo <= hi) {
		mid = (lo+hi)/2;
		if (arr[mid] == target) return mid;
		if (arr[mid] < target) lo = mid+1;
		else hi=mid-1;
	}
	return mid;
}

int binsearch_2 (int* arr, int n, int target) {
	int k = 0;
	for (int b = n/2; b >= 1; b /= 2) {
		while (k+b < n && arr[k+b] <= target) k += b;
	}
	return k;
}

int main () {
	uint n; cin >> n; int a[n];
	REP (i, 0, n) {
		cin >> a[i];
	}

	cout << "Enter target num: \n";
	int num; cin >> num;
	cout << binsearch_1(a, n, num) << endl;
	cout << binsearch_2(a, n, num) << endl;
}