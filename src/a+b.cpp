#include<bits/stdc++.h>
using namespace std;
const int charToInt = '0';


vector<int> stringToLongInt (string s) {
    int len = s.length();
    vector<int> result;
    for(int i = 0; i<len; i++) {
        int num = s[i] - '0';                 // '1' - '0' = 1
        result.push_back(num);
    }
    return result;
}

vector<int> twoSum (vector<int> a, vector<int> b) {
    int n = max(a.size(),b.size())+1;
    int na = a.size();
    int nb = b.size();
    for(int i = na; i<n; i++) a.insert(a.begin(),0);
    for(int j = nb; j<n; j++) b.insert(b.begin(),0);
    //cout << "a-size: "<< a.size() << "    b-size: "<< b.size()<<endl;

    vector<int> sum;

    int dex = 0;     // decimal digit
    for(int i = n-1; i>=0; i--) {
        int cur = a[i]+b[i]+dex;
        dex = 0;
        if(cur>9) {dex = 1; cur -= 10;}
        sum.insert(sum.begin(), cur);
    }
    if(sum[0]==0) sum.erase(sum.begin());
    return sum;
}

vector<int> twoProduct(vector<int> &a, vector<int> &b) {
    
}

int main() {
    string a,b; cin >> a >> b;
    vector<int> va = stringToLongInt(a);
    vector<int> vb = stringToLongInt(b);

     for(int i:twoSum(va, vb)) cout << i;
    
    /*
  vector<int> va = {1,2,3};
  vector<int> vb = {2,3,4};
  vector<int> answer = twoSum(va,vb);
  for(int i:answer) cout << i;*/
}
