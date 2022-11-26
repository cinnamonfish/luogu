#include<bits/stdc++.h>
using namespace std;
#define left(i,lo,hi) for(int i = lo; i < hi; i++)

void continueSum() {
    int n; cin >> n;
       /*
       *
        if(n%2==1) {                          // n is odd 
            left(i,sqrt(n/2),n) {
            if(n%i==0 && (n/i)%2==1){           // i in the middle
                int sideLen = (n-1)/(2*i);
                int lo = i - sideLen;
                int hi = i + sideLen;
                cout << lo << " " << hi << endl;
            }
        }
    }
       */
        left(i, 2, sqrt(n*2)+1) {
            if(2*n%i==0) {
                int j = 2*n/i;
                if((i+j)%2==1) {
                    int lo = (j-i+1)/2;
                    int hi = (j+i-1)/2;
                    cout << lo << " " << hi << endl;
                }
            }
        }


}

typedef struct{int x,y;} node;


bool cmpNode(node a,node b){
    return a.x < b.x;          // descending order sort
}
void chibi() {
    int n; cin >> n;
    node nodes[20005];
    left(i,0,n) {
        cin >> nodes[i].x >> nodes[i].y;
    }
    sort(nodes, nodes+n, cmpNode);
    int ans = 0;
    ans += nodes[0].y - nodes[0].x;
    int prev = nodes[0].y;

    left(i,1,n) {
    //   cout << "ans: "<<ans<<endl;
        if(nodes[i].x >= prev) ans += nodes[i].y-nodes[i].x;
        else if(nodes[i].y >= prev) ans += nodes[i].y - prev;
        prev = max(prev, nodes[i].y);
    }
    cout << ans;
}

int main() {
    continueSum();
    // chibi();
}