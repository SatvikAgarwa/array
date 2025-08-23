#include<bits/stdc++.h>
using namespace std;

void solution(vector <string> &arr, int d) {
    int n = arr.size();
    d = d % n; // Handle cases where d >= n
    int count = arr.size() - 1;
    for(int i = arr.size() - d; i < (arr.size() / 2) + d; i++)
        swap(arr[i], arr[count--]);

    count = (arr.size() - d - 1);
    for(int i = 0; i < (arr.size() - d) / 2; i++)
        swap(arr[i], arr[count--]);
    
    count = arr.size() - 1;
    for(int i = 0; i < arr.size() / 2; i++)
        swap(arr[i], arr[count--]);
}

int main() {
    vector <string> arr = {"A", "B", "C", "D", "E", "F", "G"};
    int c;
    cout << "Enter the number of rotations: ";
    cin >> c;
    solution(arr, c);
    for(string s: arr)
        cout << s << " ";
    return 0;
}