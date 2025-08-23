#include<bits/stdc++.h>
using namespace std;

void brute_force(vector <string> &arr, int k) {
    k = k % arr.size();
    vector <string> temp;
    int count = 0;
    for(int i = 0; i < k; i++)
        temp.push_back(arr[i]);
    
    for(int i = k; i < arr.size(); i++)
        arr[count++] = arr[i];

    for(int i = 0; i < temp.size(); i++)
        arr[count++] = temp[i];
}

void optimal_solution(vector <string> &arr, int k) {
    k = k % arr.size();

    int count = k - 1;
    for (int i = 0; i < k / 2; i++)
        swap(arr[i], arr[count--]);

    count = arr.size() - 1;
    for (int i = k; i < (arr.size() / 2) + k; i++)
        swap(arr[i], arr[count--]);
    
    count = arr.size() - 1;
    for (int i = 0; i < arr.size() / 2; i++)
        swap(arr[i], arr[count--]);
}

int main() {
    vector <string> arr = {"A", "B", "C", "D", "E"};
    int n;
    cout << "Enter the number of spaces to to move: ";
    cin >> n;
    optimal_solution(arr, n);
    for(auto &name : arr)
        cout << name << " ";
    return 0;
}