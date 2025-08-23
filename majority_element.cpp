#include<bits/stdc++.h>
using namespace std;

int bruteForce(vector <int> &arr) {
    int maxCount = -1;
    int majorityElement = -1;
    int n = arr.size() / 2;
    for(int i = 0; i < arr.size(); i++) {
        int count = 0;
        for (int j = 0; j < arr.size(); j++)
            if(arr[i] == arr[j]) count++;
        if(count > n) {
            if(maxCount < count) { 
                maxCount = count;
                // Update the majority element
                majorityElement = arr[i];
            }
        }
    }
    return majorityElement;
}

int betterSolution(vector <int> &arr) {
    map<int, int> numCount;
    for (int i: arr) {
        numCount[i]++;
    }
    for (auto &entry: numCount) {
        if (entry.second > arr.size() / 2) {
            return entry.first;
        }
    }
    return -1;
}

//Moores Voting algorithm
int optimalSolution(vector <int> &arr) {
    int majorityElement = 0, count = 0;
    for(int i: arr) {
        if(count == 0)
            majorityElement = i;
        count += (i == majorityElement) ? 1 : -1;
    }
    return majorityElement;
}

int main() {
    vector <int> arr = {2, 2, 3, 3, 1, 2, 2};
    cout << bruteForce(arr) << endl;
    cout << betterSolution(arr) << endl;
    return 0;
}