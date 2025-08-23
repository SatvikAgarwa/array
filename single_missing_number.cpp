#include<bits/stdc++.h>
using namespace std;

int normal_solution(vector <int> &arr) {
    int n = arr.back();
    int total_sum = (n * (n + 1)) / 2;
    int arr_sum = 0;
    for(int i: arr) {
        arr_sum += i;
    }
    return total_sum - arr_sum;
}

int XOR_solution(vector <int> &arr) {
    int n = arr.back() - 1;
    int xor1 = 0, xor2 = 0;
    for(int i = 0; i < n; i++) {
        xor1 ^= i + 1;
        xor2 ^= arr[i];
    }
    xor1 ^= n + 1;
    return xor1 ^ xor2;
}

int main() {
    vector <int> arr ={1, 2, 4, 5, 6};
    cout << normal_solution(arr) << endl;
    cout << XOR_solution(arr) << endl;
    return 0;
}