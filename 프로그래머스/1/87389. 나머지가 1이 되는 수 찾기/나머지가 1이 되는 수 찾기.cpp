#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    for(int i=2; i<n; i++){
        if(n % i == 1) return i;
    }
}