#include<bits/stdc++.h>
using namespace std;

int subarrayCount(vector <int> &arr, int k) {
    map <int, int> hashmap;
    int cnt = 0, XOR = 0;
    hashmap[0]++;
    for (int i = 0; i < arr.size(); i++)
    {
        XOR ^=  arr[i];
        int x = XOR ^ k;
        cnt += hashmap[x];
        hashmap[XOR]++;
    }
    
    return cnt;
}

int main() {
    vector <int> arr = {4, 2, 2, 6, 4};
    cout << subarrayCount(arr, 6);
    return 0;
}