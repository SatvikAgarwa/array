#include<bits/stdc++.h>
using namespace std;

int main() {
    vector <int> arr = {1, 1, 0, 1, 0, 1, 1, 0, 0, 1};
    int count = 0;
    for(int i: arr) {
        if(i == 1) {
            count++;
        } else {
            count = 0;
        }
    }
    cout << count << endl;
    return 0;
}