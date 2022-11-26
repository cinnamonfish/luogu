#include <bits/stdc++.h>
using namespace std;
#define left(i,lo,hi) for(int i = lo;i<hi;i++)

void twoSum () {
    int na,nb; cin >> na >> nb;
    vector<int> a,b;
    int c; 
    int n = max(na,nb);
    left(i,0,na) cin >> c, a.push_back(c);
    if(na<n) left(i,na,n) a.insert(a.begin(),0);
    //cout << "aaends"<<endl;
    left(i,0,nb) cin >> c, b.push_back(c);
    if(nb<n) left(i,nb,n) b.insert(b.begin(),0);
    //cout <<"na:"<<na<<"nb:"<<nb<<"n:"<<n<<endl<<"a:";
    //for(int i:a) cout << i;
    //cout << endl;
    //for(int i:b) cout <<i;
    //cout << endl;
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