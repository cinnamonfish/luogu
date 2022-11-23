#include<bits/stdc++.h>
using namespace std;
// const int charToInt = 

vector<int> APlusB (vector<int> a, vector<int> b) {
    
} 

vector<int> stringToLongInt (string s) {
    int len = s.length();
    vector<int> result;
    for(int i = 0; i<len; i++) {
        int num = s[len-1-i] - '0';                 // '1' - '0' = 1
        result.insert(0,num);
    }
    return result;
}