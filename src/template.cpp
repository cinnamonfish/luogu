#include <bits/stdc++.h>
using namespace std;
#define left(i, lo, hi) for (int i = lo; i < hi; i++)
#define ll long long
#define MOD 1000000007
#define QWQ puts("QWQ")
void matrixPower()
{
    std::ios::sync_with_stdio(0);
    int n = 10;
    long long k; // cin >> n >> k;
    int mat[n][n];
    left(i, 0, n) left(j, 0, n); // cin >> mat[i][j];

    // cout << k;
}

void primeLoop()
{
    int n, k;  cin >> n >> k;
    vector<int> nums;
    nums.push_back(2);
    left(i, 3, n+1)
    {
        if (i % 2 == 0) continue;
        int count = 0;
        for (int j : nums) if (j <= sqrt(i) && i % j == 0) {count = 1; break;}
        
        if(count==0) nums.push_back(i);
    }
    left(i,0,k) {
        cout << nums[k-1];
    }
}

void primeEuler() {
    int n; cin >> n;
    int k; cin >> k;
    short nums[n+2];
    vector<int> prime;
    nums[0] = 1;
    nums[1] = 1; // not prime
    left(i,2,n+1) {
        if(nums[i]!=1) {
            //prime
            prime.push_back(i);
            for(int j = 2; j*i<=n; j++) nums[i*j] = 1; // not prime
        }
    }
    
    //for(int i:prime) cout << i << " ";

    left(i,0,k) {
        int cur; cin >> cur;
        cout << prime[cur-1] << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    primeEuler();
}