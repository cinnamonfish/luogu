#include <bits/stdc++.h>
using namespace std;

bool isprime(int n)
{
if (n<=1) return false;
for (int i=3;i<=sqrt(n);i++)
{
if (n%i==0) return false;
}
return true;
}
bool huiwen(int n)
{
string st=to_string(n);
int l=0,r=st.size()-1;
while (l<=r)
{
if (st[l]!=st[r]) return false;
l++;
r--;
}
return true;
}

int main()
{
    int a, b;cin>>a>>b;
if (a%2==0) a++;
for (int i=a;i<=min(b,9989899);i+=2)
{
if (huiwen(i)==false) continue;
else if (isprime(i)) cout<<i<<endl;
}
return 0;
}
}