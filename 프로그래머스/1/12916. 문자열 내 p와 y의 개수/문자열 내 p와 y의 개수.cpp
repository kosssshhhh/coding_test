#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    int p_cnt = 0, y_cnt = 0;
  
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'p' || s[i] == 'P') p_cnt++;
        else if(s[i] == 'y' || s[i] == 'Y') y_cnt++;
    }
    
    return p_cnt == y_cnt;

}