#include<bits/stdc++.h>
using namespace std;
#define left(i,lo,hi) for(int i=lo;i<hi;i++)
const int MOD = 998244353;

void square() {
    int n,m; cin >> n >> m;
    short a[1010][1010];
    for(int i =1; i<n+1; i++) for(int j = 1; j<m+1; j++) cin >> a[i][j];

    int r,c; cin >> r >> c;
    int b[60][60];
    for(int i =0; i<r; i++) for(int j = 0; j<c; j++) cin >> b[i][j];

    int q; cin >> q; // 询问
    int x1,y1,x2,y2;
    for(int i = 0; i<q; i++) {
        int sum = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        left(ir,x1,x2+1) left(ic,y1,y2+1) {
            int br = (ir-x1)%r;            // 对应b数组的第几行、第几列
            int bc = (ic-y1)%c;
            int thisNum = (a[ir][ic] * (b[br][bc] ^ 1)) % MOD;
            sum = (sum + thisNum)%MOD;
        }
        cout << sum << endl;
    }
}

int main(){
    //cout << (2103477777777328888888888777 + 930214444444444441444444444444) %3;
    std::ios::sync_with_stdio(0);

    square();
}