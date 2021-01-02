/*
#include<bits/stdc++.h>

using namespace std;

#ifdef DEBUG
void visualize (vector<vector<uint>>& arrs) {
    printf("Number of arrays: %ld\n", arrs.size());
    for (auto arr: arrs) {
        for (auto ele: arr) {
            cout << ele << " ";
        }
        cout << endl;
    }
    printf("-------------\n");
}
#endif

int main () {
    // We assume size of array is given beforehand.
    uint n;
    cin >> n;

    uint ele;
    cin >> ele;

    // Initialize one array holding one element = ele    
    vector<vector<uint>> arrs { vector<uint> (1, ele) };
    uint smallest_element_for_particular_length_arr[n];
    fill_n(smallest_element_for_particular_length_arr, n, -1); //Init everything to max value

    vector<uint>::iterator insert_pos;

    while (cin >> ele) {
        size_t size = arrs.size();
        for (auto i = lower_bound(arrs.begin(), arrs.end(), ele); i < size; i++) {
            insert_pos = lower_bound(arrs[i].begin(), arrs[i].end(), ele); 

            if (insert_pos == arrs[i].end()) {
                arrs[i].push_back(ele);
            } else if (ele < smallest_element_for_particular_length_arr[arrs[i].size() - 1]) {
                smallest_element_for_particular_length_arr[arrs[i].size() - 1] = ele;
                arrs.push_back(vector<uint> (arrs[i].begin(), insert_pos));
                (*(arrs.rbegin())).push_back(ele);
            }
        }

        #ifdef DEBUG
        visualize(arrs);
        #endif
    }

    size_t ans = 0;
    for (auto arr: arrs) {
        ans = max(ans, arr.size());
    }

    cout << ans << endl;
}*/