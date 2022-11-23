#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fun(string s,int &i){
        int si=1,res=0;
        while(i<s.size() && s[i]!=')'){
            if(isdigit(s[i])){
                int dig=0;
                while(s[i]!=' ' && isdigit(s[i])){
                    dig=dig*10+(s[i++]-'0');
                }
                while(s[i]==' '){
                    i++;
                }
                res+=si*(dig);
            }
            else if(s[i]=='('){
                i++;
                int t=fun(s,i);
                i++;
                res+=si*t;
            }
            else if(s[i]==' '){
                i++;
            }
            else if(s[i]=='+'){
                si=1;
                i++;
            }
            else if(s[i]=='-'){
                si=-1;
                i++;
            }
        }
        return res;
    }
    int calculate(string s) {
        int i=0;
        return fun(s,i);
    }

    bool isExit(int m, int n, vector<int> &pos) {
        if((pos[0]==0||pos[0]==m-1)&&(pos[1]==0||pos[1]==n-1)) return true;
        return false;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        int count = 0;
        if(isExit(m,n,entrance)) return count;
        else {
            int r = entrance[0];
            int c = entrance[1];
            if(r>0 && maze[r-1][c]=='.') {count++; vector<int> pos = {r-1,c}; return nearestExit(maze,pos);}
        }
        return 0;
    }
        
    int main() {
        vector<vector<char>> maze = {{'+','+','.','+'}};
        vector<int> entrance = {0,2};
        cout << isExit(1,4,entrance);
        return 0;
    }
};

