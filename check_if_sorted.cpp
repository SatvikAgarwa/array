#include<bits/stdc++.h>
using namespace std;

void check_if_sorted(vector <int> &arr) {
    for(int i = 0; i < arr.size() - 1; i++) {
        if(arr[i] > arr[i + 1])
        {
            cout << "Array is not sorted." << endl;
            return;
        }
    }
    cout << "Array is sorted." << endl;
}

int main() {
    vector <int> arr = {1, 2, 3, 4, 5};
    check_if_sorted(arr);
    return 0;
}