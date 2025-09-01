#include<bits/stdc++.h>
using namespace std;

vector <int> MajorityElement(vector <int> &arr) {
    int count1 = 0, count2 = 0;
    int ele1 = 0, ele2 = 0;
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        
        if(count1 == 0 && ele2 != arr[i]) {
            count1 = 1;
            ele1 = arr[i];
        } else if(count2 == 0 && ele1 != arr[i]) {
            count2 = 1;
            ele2 = arr[i];
        } else if(ele1 == arr[i])
            count1++;
        else if(ele2 == arr[i])
            count2++;
        else {
            count1--;
            count2--;
        }
    }

    return{ele1, ele2};
}

int main() {
    vector <int> arr = {2, 2, 1, 1, 1, 2, 2, 3, 1};
    cout << "Majority Elements are: ";
    vector<int> result = MajorityElement(arr);
    for(int i : result) {
        cout << i << " ";
    }
    return 0;
}