#include<bits/stdc++.h>
using namespace std;



string parenthesis;

string validParenthesis(string prev) {
    stack<char> stack;
    string result;
    for(int i = 0; i<prev.length(); i++) {
        char c = prev[i];
        if(stack.empty()) {
            if(c=='('||c=='[') stack.push(c);
            if(c==')') result.append("()");
            if(c==']') result.append("[]");
        }
        else {
            if(c=='('||c=='[') stack.push(c);
            if(c!=')'&&stack.top()=='(')  {
                stack.pop();
                result.append("()");
                stack.push(c);
            }
            if(c!=']'&&stack.top()=='[')  {
                stack.pop();
                result.append("[]");
                stack.push(c);
            }
            else{
                if(c==')') result.append("()");
                if(c==']') result.append("[]");
                stack.pop(); stack.pop();
            }

        }
    }
    return result;
}

string P4387() {       // validate stack
    int n; cin >> n; 
    for (int i = 0; i<n; i++) {
        int q; cin >> q;
        stack<int> stacker;
        
        /*
        for(int j = 0; j<q; j++) {
            int num; cin >>num;
            stacker.push(num);
        }
        */
       return ;
        
    }
}

define



int josephus() {
    
    return 0;
}

int main() {
    string prev; cin >> prev;
    cout << validParenthesis(prev);
}