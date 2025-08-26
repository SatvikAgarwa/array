#include<bits/stdc++.h>
using namespace std;

vector <int> findLeaders(vector <int> &arr) {
    int leader = arr.back();
    vector <int> leaders = {leader};
    for (int i = arr.size() - 2; i >= 0; i--) {
        if (arr[i] > leader) {
            leader = arr[i];
            leaders.push_back(leader);
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    int n;
    vector <int> arr = {10, 22, 12, 0, 5, 6};
    vector <int> leaders = findLeaders(arr);
    for (int leader : leaders) {
        cout << leader << " ";
    }
    return 0;
}