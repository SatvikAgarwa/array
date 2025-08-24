#include<bits/stdc++.h>
using namespace std;

void bruteForce(vector <int> &arr) {
    int n = arr.size();
    vector <int> arr_p;
    vector <int> arr_n;
    for (int i = 0; i< n; i++) {
        if(arr[i] >= 0 )
            arr_p.push_back(arr[i]);
        else
            arr_n.push_back(arr[i]);
    }
    for(int i = 0; i < arr.size(); i++) {
        if(i % 2 == 0)
            arr[i] = arr_p[i/2];
        else
            arr[i] = arr_n[i/2];
    }
}

void second_variant(vector <int> arr) {
    int n = arr.size();
    vector <int> arr_p;
    vector <int> arr_n;
    for(int i = 0; i < n; i++) {
        if(arr[i] >= 0)
            arr_p.push_back(arr[i]);
        else
            arr_n.push_back(arr[i]);
    }

    for(int i = 0; i < arr_n.size(); i++) {
        arr[2*i] = arr_p[i];
        arr[2*i + 1] = arr_n[i];
    }

    for(int i = 2*arr_n.size(); i < arr.size(); i++) {
        arr[i] = arr_p[i - arr_n.size()];
    }
}

int main() {
    vector<int> arr = {3, 1, -2, -5, 2, 4};
    bruteForce(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
