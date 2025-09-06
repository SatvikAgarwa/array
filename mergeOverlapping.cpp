#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> bruteForce(vector<vector<int>> &arr) {
    vector<vector<int>> ans;
    if (arr.empty()) return ans;

    sort(arr.begin(), arr.end());
    int n = arr.size();
    int i = 0;
    while (i < n) {
        int start = arr[i][0];
        int end = arr[i][1];
        int j = i + 1;

        while (j < n && arr[j][0] <= end) {
            end = max(end, arr[j][1]);
            j++;
        }
        ans.push_back({start, end});
        i = j;
    }
    return ans;
}

int main() {
    vector<vector<int>> arr = {{1, 2}, {2, 6}, {8, 9}, {9, 11},
                               {8, 10}, {2, 4}, {15, 18}, {16, 20}};
    vector<vector<int>> ans = bruteForce(arr);
    for (auto &i : ans) {
        cout << "[" << i[0] << ", " << i[1] << "] ";
    }
    cout << endl;
    return 0;
}