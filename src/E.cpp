#include<bits/stdc++.h>
using namespace std;
#define i64 long long
int main() {
    int q; cin >> q;
    i64 k;
    for(int i = 0; i<q; i++) {
        cin >> k;
        i64 n = floor((-3+sqrt(9-8*(1-k))/4));
        cout << n<<endl;
    }
}