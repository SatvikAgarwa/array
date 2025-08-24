#include<bits/stdc++.h>
using namespace std;

int bruteForce(vector <int> &arr) {
    int maxSum = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

int optimalSolution(vector <int> &arr) {
    int maxSum = INT_MIN;
    int currSum = arr[0];
    for(int i = 0; i < arr.size(); i++) {
        if(currSum < 0) currSum = 0;
        currSum += arr[i];
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main() {
    vector <int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << bruteForce(arr) << endl;
    cout << optimalSolution(arr) << endl;
    return 0;
}