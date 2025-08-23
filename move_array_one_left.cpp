#include<bits/stdc++.h>
using namespace std;

void Brute_force(vector <string> &arr) {
    vector <string> temp;
    for(int i = 1; i < arr.size(); i++) 
        temp.push_back(arr[i]);
    temp.push_back(arr[0]);
    arr =temp;
}

void Optimal_solution(vector <string> &arr) {
    string temp = arr[0];
    for(int i = 1; i < arr.size(); i++)
        arr[i - 1] = arr[i];
    arr[arr.size() - 1] = temp;
}

int main() {
    vector <string> names = {"A", "B", "C", "D", "E"};
    Optimal_solution(names);
    for(string name: names) {
        cout << name << " ";
    }
    return 0;
}