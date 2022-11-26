#include<bits/stdc++.h>
using namespace std;

struct gold{
    double mass;
    double value;
};

bool compareGold(gold a, gold b) {
    return a.value/a.mass > b.value/b.mass;
}

double P2240 () {   // partial-backpack 
    int N; double T;
    cin >> N >> T;
    /*gold piles[N+3];
    for(int i = 0; i<N; i++) {
        cin >> piles[i].mass;
        cin >> piles[i].value;
    }*/
    vector<gold> piles;
    for(int i = 0; i<N; i++) {
        gold current; cin >> current.mass >> current.value;
        piles.push_back(current);
    }
    stable_sort(piles.begin(), piles.end(), compareGold);
    double totVal;
    for(int i = 0; i<N; i++) {
        //cout << "T: "<<T<<endl;
        if(T>=piles[i].mass) {
            totVal += piles[i].value;
            T -= piles[i].mass;
        }
        else if(T>0) {
            totVal += T * piles[i].value/piles[i].mass;
            T = 0;
        }
        else break;
    }
    return totVal;

}

int P1090 () {  // priority queue

    // combining piles of fruit
    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> qq;
    int n, x, ans=0;
    cin >> n;
    for(int i = 0; i<n; i++) cin >> x, qq.push(x);
    while(qq.size()>=2) {
        int a = qq.top(); qq.pop();
        int b = qq.top(); qq.pop();
        ans += a+b;
        qq.push(a+b);
    }
    return ans;
}

int P4447() {    // divide into groups
    int n; cin >> n;
    return 0;
}

int P5019() {   // pave the road
    int n; cin >> n;
    vector<int> road;
    int a;
    for(int i = 0; i<n; i++) cin >> a, road.push_back(a);
    int days = 0; 
    for(int i = 1; i<n; i++) {
        if(road[i]>road[i-1]) days+=(road[i]-road[i-1]);
    }
    days+=road[0];
    return days;
}

int P4995() {
    int n; cin >> n;
    vector<int> stones;
    int a;
    for(int i = 0; i<n; i++) cin >> a, stones.push_back(a);
    int sum = 0;
    stable_sort(stones.begin(),stones.end());
    //for(int i:stones) cout << i<<" "<<endl;

    int current = 0;
    while(stones.size()>0) {
        //cout << "size: "<<stones.size()<<endl;
        sum += (current - stones[stones.size()-1]) * (current - stones[stones.size()-1]);
        current = stones[stones.size()-1];
        stones.erase(stones.begin()+stones.size()-1);

        if(stones.size()==0) break;
        //cout << "size: "<<stones.size()<<endl;

        sum += (current - stones[0])*(current - stones[0]);
        current = stones[0];
        stones.erase(stones.begin()+0);
    }
    return sum;
}

int main() {
    
    cout << P4995();
    // cout << setiosflags(ios::fixed) =6<setprecision(2)<< P2240();
}