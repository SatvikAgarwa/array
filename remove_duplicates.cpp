#include<bits/stdc++.h>
using namespace std;

void remove_duplicates(vector <int> &arr) {
    vector <int> temp;
    temp.push_back(arr[0]);
    int duplicate = arr[0];
    for(int i = 0; i < arr.size(); i++) {
        if(duplicate == arr[i]) {
            continue;
        }
        temp.push_back(arr[i]);
        duplicate = arr[i];
    }
    arr = temp;
}

void set_data(vector <int> &arr) {
    set <int> s;
    for(int i: arr)
        s.insert(i);
    
    for (int i: s)
        cout << i << " ";
    cout << endl;
}

void optimal_solution(vector <int> &arr) {
    int j = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[j] != arr[i]) {
            continue;
        } else {
            arr[j++] = arr[i];
        }
    }
}

int main() {
    vector <int> arr = {1, 1, 2, 2, 3, 4, 4, 5};
    optimal_solution(arr);
    for(int i: arr) {
        cout << i << " ";
    }
    return 0;
}