#include<bits/stdc++.h>
using namespace std;

int solution(vector <int> &arr, int k) {
    unordered_map <int, int> mp;
    mp[0] = 1;
    int preSum = 0, count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        preSum += arr[i];
        int remove = preSum - k;
        count += mp[remove];
        mp[preSum]++;
    }
    return count;
}

int main() {
    vector <int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int count = solution(arr, 3);
    cout << count << endl;
}