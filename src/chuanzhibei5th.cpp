#include<bits/stdc++.h>

using namespace std;

int compare(const void *a, const void *b)
{
    int *pa = (int*)a;
    int *pb = (int*)b;
    return (*pa )- (*pb);  // don't know how to write
}

int T292113(int n, int nums[], int w) {
    qsort(nums, n, sizeof(int), compare);
    int buy = -1;
    
    for(int i = n-1; i>=0; i--) {
        if(w>=nums[i]) {buy = nums[i];break;}          // if "buy" then {buy <- nums[i]} else {buy = -1}
    }
    int count = 0;
    for(int i = 0; i<n; i++) {
        if(buy>=nums[i]) {
            buy -= nums[i];
            count ++;
        }
    }
    count = max(count,1);
    if(buy ==-1) count = 0;
    return count;
}

/*// 嗷呜嗷呜
int T293037() {
    return 0;
}*/
/*int main() {
    int n;    cin >> n;
    int nums[n];    for(int i = 0; i<n; i++) cin >> nums[i];
    int w; cin >> w;             // money
    cout << T292113(n,nums,w);
}*/

/*
input: 
1
3
2
output : supposed to be 0
*/


/*********************
 * 
 *        F
 * *************************
 * */


#include<bits/stdc++.h>
#define up(l,r,i) for(int i = l; i<r; i++)  //l到r的for循环
#define down(r,l,i) //r到l的for循环
using namespace std;
typedef long long i64;
const int INF = 2147483647;
const int MAXN = 3e4 + 3, MAXV = 2e4 + 3, MAXM = 300 + 3, SI = 4;
int q, m, t, s, l, r, X[MAXN], Y[MAXN];
int W[MAXM][MAXV], M[MAXM][MAXV];
int qread(){
    // 快速读入
}
int main(){
    q = qread(), m = qread(); int lastans = 0;
    s = 1 + sqrt(q + 1) / 2, l = 0, r = 2 * s - 1;
    up(1, q, i){
        int op = qread(), x = qread() ^ lastans, y = qread() ^ lastans;
        if(op == 1){
            ++ t; X[t] = x, Y[t] = y;
            if(t - 1 == r){
                up(0, s - 1, j) up(0, m, k) W[j][k] = W[j + s][k];
                l += s, r += s;
            }
            int u = min(x - 1, m);
            up(0, u, j) W[t - l][j] = W[t - l - 1][j];
            up(x, m, j) W[t - l][j] = max(W[t - l - 1][j], W[t - l - 1][j - x] + y);
            if(t % s == 0) up(0, m, j) M[t / s][j] = W[t - l][j];
        } else if(op == 2){
            -- t;
            if(t + 1 == l){
                l -= s, r -= s;
                up(0, m, j) W[0][j] = M[l / s][j];
                up(1, s - 1, j){
                    int x = X[l + j], y = Y[l + j], u = min(x - 1, m);
                    up(0, u, k) W[j][k] = W[j - 1][k];
                    up(x, m, k) W[j][k] = max(W[j - 1][k], W[j - 1][k - x] + y);
                }
            }
        } else {
            printf("%d\n", lastans = W[t - l][x]);
        }
    }
    return 0;
}