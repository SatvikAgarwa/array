#include<bits/stdc++.h>
using namespace std;

int bruteforce(vector <int> &arr, int k) {
    int result = 0;
    int n = arr.size(), j;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (j = i; j < n; j++)
            sum += arr[j];
        
        if(k == sum) result = max(result, j - i + 1);
    }
    return result;
}

int better_solution(vector <int> &arr, int k) {
    map <int, int> preSum;
    int maxLen = 0, sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(sum == k)
            maxLen = i + 1;
        
        int rem = sum - k;
        if(preSum.find(rem) != preSum.end()) {
            int len = i - preSum[rem];
            maxLen = max(maxLen, len);
        }

        if(preSum.find(sum) == preSum.end())
            preSum[sum] = i;
    }
    return maxLen;
}

int optimal_solution(vector <int> &arr, int k) {
    int i = 0, j = 0;
    int sum = 0, maxlen = 0;

    while (i < arr.size() && j < arr.size()) {
        sum += arr[j++];
        if(sum > k)
            while(sum > k&& i < j){
                sum -= arr[i++];
            }
        if(sum == k)
            maxlen = max(maxlen, j - i);
    }
    return maxlen;
}

int main() {
    vector <int> arr = {1, 2, 3, 7, 5};
    int k = 12;
    cout << "Length of longest subarray with sum " << k << " is: " << bruteforce(arr, k) << endl;
    cout << "Length of longest subarray with sum " << k << " is: " << better_solution(arr, k) << endl;
    cout << "Length of longest subarray with sum " << k << " is: " << optimal_solution(arr, k) << endl;
    return 0;
}