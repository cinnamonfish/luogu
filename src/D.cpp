#include<bits/stdc++.h>
using namespace std;

void change() {
    int n, m; cin >> n >> m;
    int thisNum, hi = 0, lo = 0;
    int a[100005];
    for(int i = 0; i<n; i++) {
        cin >> a[i];
        //hi = max(hi, a[i]);
        //lo = min(lo, a[i]);
    }
    lo = min_element(a,a+n) - a;
    hi = max_element(a,a+n) - a;      // 返回下标值
    
    
}

int main() {
    change();
}