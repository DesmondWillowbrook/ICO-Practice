#include<bits/stdc++.h>

using namespace std;

int main () {
	int n, q; cin >> n >> q;
	multiset<int> salaries;
	int employee_salaries[n];

	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		employee_salaries[i] = temp;
		salaries.insert(temp);
	}
	for (int i = 0; i < q; i++) {
		char type; cin >> type;
		if (type == '!') {
			int emp, new_salary; cin >> emp >> new_salary; emp--;
			int prev_salary = employee_salaries[emp];
			salaries.erase(salaries.find(prev_salary));
			salaries.insert(new_salary);
			employee_salaries[emp] = new_salary;
		}
		else if (type == '?') {
			int a, b; cin >> a >> b;
			auto it = salaries.lower_bound(a);
			auto it_end = salaries.lower_bound(b);
			int num = 0;

			while (it != salaries.lower_bound(b)) {it++; num++;}
			if (it_end != salaries.end() && *it_end == b) {num++;}
			cout << num << endl;
		}
	}
}