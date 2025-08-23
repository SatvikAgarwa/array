#include<bits/stdc++.h>
using namespace std;

void brute_force(vector <int> &arr) {
    stable_sort(arr.begin(), arr.end(), greater<int>());
    cout << "Largest element is: " << arr[0] << endl;
}

void optimal_solution(vector <int> &arr) {
    int max_element = 0;
    for (int i = 0; i < arr.size(); i++) 
        if(arr[i] > max_element) max_element = arr[i];
    
    cout << "Largest Element: " << max_element << endl;
}

int main() {
    vector <int> arr = {12, 11, 56, 33, 45};
    optimal_solution(arr);
    return 0;
}