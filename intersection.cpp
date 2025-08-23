#include<bits/stdc++.h>
using namespace std;

vector <int> brute_force(vector <int> &arr1, vector <int> &arr2) {
    vector <int> intersection_arr;
    for(int i: arr1) {
        for(int j: arr2) {
            if(i == j) {
                if( intersection_arr.empty() || intersection_arr.back() != i) {
                    intersection_arr.push_back(i);
                }
            }
        }
    }
    return intersection_arr;
}

vector <int> optimal_solution(vector <int> &arr1, vector <int> &arr2) {
    vector <int> intersection_arr;
    int i = 0, j = 0;

    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] < arr2[j])
            i++;
        else if(arr1[i] > arr2[j])
            j++;
        else {
            if(intersection_arr.empty() || intersection_arr.back() != arr1[i])
                intersection_arr.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return intersection_arr;
}

int main() {
    vector <int> arr1 = {1, 2, 2, 3, 4, 5};
    vector <int> arr2 = {2, 2, 3, 5};
    vector <int> result = optimal_solution(arr1, arr2);
    for(int i: result) {
        cout << i << " ";
    }
    return 0;
}