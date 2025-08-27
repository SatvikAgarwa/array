#include<bits/stdc++.h>
using namespace std;

int bruteForce(vector <int> arr) {
    int maxLength = 1;
    for(int i = 0; i < arr.size(); i++) {
        int count = 1;
        int x = arr[i] + 1;
        while(find(arr.begin(), arr.end(), x) != arr.end()) {
            count++;
            x++;
        }
        maxLength = max(maxLength, count);
    }
    return maxLength;
}

int optimalSolution(vector <int> &arr) {
    unordered_set<int> numSet(arr.begin(), arr.end());
    int maxLength = 0;
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        if(numSet.find(arr[i] - 1) == numSet.end()) {
            int currentNum = arr[i];
            int currentLength = 1;
            while(numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                currentLength++;
            }
            maxLength = max(maxLength, currentLength);
        }
    }
    
    return maxLength;
}

int main() {
    vector <int> arr = {100, 4, 200, 1, 3, 2};
    cout << "Brute Force: " << bruteForce(arr) << endl;
    cout << "Optimal: " << optimalSolution(arr) << endl;
    return 0;
}