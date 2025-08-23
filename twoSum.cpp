#include<bits/stdc++.h>
using namespace std;

bool bruteForce(vector<int> &arr, int target) {
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[i] + arr[j] == target) {
                cout << "Pair found: (" << arr[i] << ", " << arr[j] << ")" << endl;
                return true;
            }
        }
    }
    return false;
}

bool betterSolution(vector<int> &arr, int target) {
    map<int, int> numMap;
    for(int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];
        if(numMap.find(complement) != numMap.end()) {
            cout << "Pair found: (" << arr[i] << ", " << complement << ")" << endl;
            return true;
        }
        numMap[arr[i]] = i;
    }
    return false;
}

bool optimalSolution(vector <int> &arr, int target) {
    int left = 0, right = arr.size() - 1;
    while(left < right) {
        int sum = arr[left] + arr[right];
        if(sum == target) {
            cout << "Pair found: (" << arr[left] << ", " << arr[right] << ")" << endl;
            return true;
        }
        else if(sum < target) left++;
        else right--;
    }
    return false;
}

int main() {
    vector <int> arr = {2, 6, 5, 8, 11};
    int target = 13;
    cout << "Brute force approach: " << bruteForce(arr, target) << endl;
    cout << "Better approach: " << betterSolution(arr, target) << endl;
    cout << "Optimal approach: " << optimalSolution(arr, target) << endl;
    return 0;
}