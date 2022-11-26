#include <bits/stdc++.h>
using namespace std;
#define left(i,lo,hi) for(int i = lo;i<hi;i++)

void twoSum () {
    int na,nb; cin >> na >> nb;
    int n = max(na,nb);
    int a[n], b[n];
    for(int i = 0; i<n; i++){a[i]=0;b[i]=0;}
    int c; 
    left(i,n-na,n) cin >> a[i];
    
    left(i,n-nb,n) cin >> b[i];

    vector<int> sum;
    int dex = 0; // 进位到高位的数值

    for(int i = n-1; i>=0; i--) {
        int base = n - i + 1;
        int current = a[i]+b[i]+dex;
        dex = 0;
        if(current > base - 1) {dex = 1; current -= base;}         //进位
        sum.insert(sum.begin(), current);
    }
    if(dex!=0) sum.insert(sum.begin(),dex);
    for(int i:sum) std::cout << i << " ";

}

int main() {
    std::ios::sync_with_stdio(false);
    twoSum();
    //cout
}