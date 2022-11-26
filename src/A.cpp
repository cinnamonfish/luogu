#include<bits/stdc++.h>
using namespace std;

int main(){
    long long a,b;
    std::cin >> a >> b;
    long long ans = 0;
    if(b>0) {ans = abs(a);}
    if(b<0) {ans = 0 - abs(a);}
    std::cout << ans;
}