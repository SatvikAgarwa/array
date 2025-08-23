#include<bits/stdc++.h>
using namespace std;

void bruteForce(vector<int> &arr) {
    int count_zero = 0, count_one = 0, count_two = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == 0) count_zero++;
        else if(arr[i] == 1) count_one++;
        else count_two++;
    }
    
    for (int i = 0; i < count_zero; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < count_one; i++)
    {
        arr[count_zero + i] = 1;
    }
    for (int i = 0; i < count_two; i++)
    {
        arr[count_zero + count_one + i] = 2;
    }
}

//Dutch Flag Algorithm
void optimalSolution(vector <int> &arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    while(mid <= high) {
        if(arr[mid] == 0)
            swap(arr[low++], arr[mid++]);
        else if(arr[mid] == 1)
            mid++;
        else
            swap(arr[mid], arr[high--]);
    }
}

int main() {
    vector<int> arr = {0, 1, 2, 0, 1, 2};
    optimalSolution(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}