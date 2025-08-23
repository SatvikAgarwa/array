#include<bits/stdc++.h>
using namespace std;

void brute_force(vector <int> &arr) {
    int second = 0;

    stable_sort(arr.begin(), arr.end());
    int max = arr[arr.size() - 1];

    for (int i: arr)
        if (i > second) if (i == max) continue; else second = i;
    
    cout << "Second Largest Element is: " << second << endl;
}

void better_solution(vector <int> &arr) {
    int max = INT_MIN, second = INT_MIN;

    for(int i: arr) {
        if(i > max) {
            max = i;
        }
    }

    for(int i: arr) {
        if(i > second && i < max) {
            second = i;
        }
    }

    cout << "Second Largest Element is: " << second << endl;
}

void optimal_solution(vector <int>&arr) {
    int first = INT_MIN, second = INT_MIN;

    for (int i: arr) {
        if (i > first) {
            second = first;
            first = i;
        } else if (i > second && i < first) second = i;
    }

    if (second == INT_MIN) {
        cout << "No Second Largest Element Found" << endl;
    } else {
        cout << "Second Largest Element is: " << second << endl;
    }
}

int main() {
    vector <int> arr = {11, 11, 11, 11, 11};
    optimal_solution(arr);
    return 0;
}