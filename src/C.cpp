#include<bits/stdc++.h>
using namespace std;
#define left(i,lo,hi) for(int i = lo;i<hi;i++)

void lineNumber() {
    char thisline[2020];
    int i = 1;
    while(!cin.eof()) {
        cin.get(thisline,2020).get(); //cin.get(str,1024).get()
        if(thisline[0]==10) break; 
        cout << " " << i << " " << thisline<<endl;
        i++;
    }
}

int main(){
    std::ios::sync_with_stdio(0);
    lineNumber();
}