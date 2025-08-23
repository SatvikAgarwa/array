#include<bits/stdc++.h>
using namespace std;

void brute_force(vector <int> &arr) {
    vector<int> temp;
    for(int i: arr)
        if(i != 0)
            temp.push_back(i);
    for(int i = temp.size(); i < arr.size(); i++)
        temp.push_back(0);

    arr = temp;
}

void my_method(vector <int> &arr) {
    int n = arr.size();
    int count = 0;

    for(int i = 0; i < n; i++)
        if(arr[i] != 0)
            arr[count++] = arr[i];

    while(count < n)
        arr[count++] = 0;
}

void optimal_solution(vector <int> &arr) {
    int n = arr.size();
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            swap(arr[count++], arr[i]);
        }
    }
}
    // No need to fill remaining with zeros, as they will be at the end
int main() {
    vector <int> arr = {0, 1, 0, 3, 12};

    optimal_solution(arr);
    for(int i: arr)
        cout << i << " ";
    return 0;
}