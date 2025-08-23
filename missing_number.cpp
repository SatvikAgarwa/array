#include<bits/stdc++.h>
using namespace std;

vector <int> bruteForce(vector <int> &arr) {
    vector <int> missingNumbers;

    for(int i = 1; i <= arr.back(); i++) {
        int flag = 0;
        for(int j: arr) {
            if(i == j) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            missingNumbers.push_back(i);
        }
    }
    return missingNumbers;
}

vector <int> better_solution(vector <int> &arr) {
    vector <int> hash_arr(arr.back() + 1, 0);
    vector <int> missingNumber;
    for(int i: arr) {
        hash_arr[i]++;
    }

    for(int i = 1; i < hash_arr.size(); i++) {
        if(hash_arr[i] == 0){
            missingNumber.push_back(i);
        }
    }
    return missingNumber;
}

int main() {
    vector <int> arr = {1, 3, 4, 7, 8, 10};
    cout << arr.back() << endl;
    vector <int> missingNumbers = better_solution(arr);
    for(int i: missingNumbers) {
        cout << i << " ";
    }
}