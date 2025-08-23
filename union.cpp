#include<bits/stdc++.h>
using namespace std;

set<string> unionArrays(vector <string> &arr1, vector <string> &arr2) {
    set <string> uniqueElements;
    for(string i: arr1)
        uniqueElements.insert(i);
    
    for(string i: arr2)
        uniqueElements.insert(i);
    
    return uniqueElements;
}

vector <int> optimal_solution(vector <int> &arr1, vector <int> &arr2){
    vector<int> unionArr;
    int i = 0;
    int j = 0;
    
    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] <= arr2[j]) {
            if(unionArr.empty() || unionArr.back() != arr1[i]) {
                unionArr.push_back(arr1[i]);
            }
            i++;
        } else {
            if(unionArr.empty() || unionArr.back() != arr2[j]) {
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (j < arr2.size()) {
        if(unionArr.empty() || unionArr.back() != arr2[j])
            unionArr.push_back(arr2[j]);
        j++;
    }

    while (i < arr1.size()) {
        if(unionArr.empty() || unionArr.back() != arr1[i])
            unionArr.push_back(arr1[i]);
        i++;
    }

    return unionArr;
}

int main() {
    vector<int> arr1 = {1, 2, 2, 2, 4, 5, 6, 6};
    vector<int> arr2 = {2, 3, 3, 5, 5, 6, 7, 7, 8};
    vector<int> unionArr = optimal_solution(arr1, arr2);
    for (int i : unionArr) {
        cout << i << " ";
    }
    return 0;
}