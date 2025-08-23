#include<bits/stdc++.h>
using namespace std;

int brute_force(vector <int> arr) {
    int count = 0;
    for(int i = 1; i <= arr.back(); i++) {
        count = 0;
        for(int j: arr) {
            if(j == i) count++;
        }

        if (count == 1) return i;
    }
}

int optimal_solution(vector <int> arr) {
    int n = arr.back();
    int totalSum = (n * (n + 1)) / 2;
    totalSum *= 2;
    int sum = 0;
    for (int i: arr) {
        sum += i;
    }

    return totalSum - sum;
}

int xor_method(vector <int> arr) {
    int result = 0;
    for (int i: arr) {
        result ^= i;
    }
    return result;
}

int main() {
    vector <int> arr = {1, 1, 2, 3, 3, 4, 4, 5, 5};
    int number = brute_force(arr);
    cout << "The number that appears only once is: " << number << endl;

    number = optimal_solution(arr);
    cout << "The number that appears only once is: " << number << endl;

    number = xor_method(arr);
    cout << "The number that appears only once is: " << number << endl;

    return 0;
}