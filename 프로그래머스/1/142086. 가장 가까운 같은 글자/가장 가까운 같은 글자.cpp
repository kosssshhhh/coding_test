#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<int> ret;
    int arr[100];
    
    memset(arr, -1, 30 * 4);
    // fill (arr, arr + 30, -1);
    
    for (int i =0; i<s.length(); i++){
        if(arr[s[i] - 'a'] != -1){
            // 이미 있음
            ret.push_back(i - arr[s[i] - 'a']);
        } else{
            ret.push_back(-1);
        }
        arr[s[i] - 'a'] = i;
    }
    
    return ret;
}