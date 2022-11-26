#include<bits/stdc++.h>
using namespace std;
#define left(i,lo,hi) for(int i = lo; i<hi;i++)


int stringHash() {
    int n; cin >> n;
    set<string> list;
    left(i,0,n) {
        string s; cin >> s;
        if(list.find(s)==list.end()) list.insert(s);
    }
    return list.size();
    
}

void student() {
    int n; cin >> n;
    map<string, string> students;
    left(i,0,n) {
        int ask; cin >> ask;
        
        if(ask==1) {
            string name; cin >> name;
            string score; cin >> score;
            students[name] = score;
            cout << "OK\n";
        }
        if(ask==2) {
            string name; cin >> name;
            if(students.find(name)==students.end()) cout << "Not found\n";
            else cout << students[name] << endl;
        }
        if(ask==3) {
            string name; cin >> name;
            if(students.find(name)==students.end()) cout << "Not found" << endl;
            else {
                students.erase(name);
                cout << "Deleted successfully" << endl;
            }
        }
        if(ask==4) {
            cout << students.size() << endl;
        }
    }
}

long long a_b() { // P1102
    // Binary search: O(logN)
    // Ordinary search: O(N)
    int n; long long c; cin >> n >> c;
    long long nums[100001];         // 200001: n < 2e5
    long long cur;
    left(i,0,n)  cin >> nums[i];
    sort(nums, nums+n);

    long long count = 0;
    left(i,0,n) count += (upper_bound(nums,nums+n,nums[i]+c) - lower_bound(nums,nums+n,nums[i]+c));
    return count;
}

int findRoot(int nums[],int pos) {
    while(nums[pos]!=pos) pos = nums[pos];
    return pos;
}

int height(int nums[],int pos) {
    int h = 0;
    while(nums[pos]!=pos) {
        pos = nums[pos];
        h++;
    }
    return h;
}

void relationship() {
    int n,m,p; cin >> n >> m >> p;
    int people[5005];
    left(i,1,n+1) people[i] = i; // person-id
    left(i,0,m) {
        int a,b; cin >> a >> b;
        if(a>b) {int c = a; a = b; b = c;}     // to make a <= b
        if(people[a]!=people[b]) {
           if(height(people,a)>height(people,b)) people[findRoot(people,b)] = findRoot(people,a);
           else people[findRoot(people,a)] = findRoot(people,b);
        }
    }
    left(i,0,p) {
        int a,b; cin >> a >> b;
        if(findRoot(people,a)==findRoot(people,b)) cout << "Yes\n";
        else cout << "No\n";
    }
}

void village() {
    while(true) {
        int n; cin >> n;
        if(n==0) break;
        int m; cin >> m;
        int node[n+3];
        left(i,1,n+1) node[i] = i; 
    }
}

void unionFind() {
    int n, m; cin >> n >> m;
    int z,x,y;
    int nums[10005];
    left(i,0,n) nums[i] = i;  // prioritize
    left(i,0,m) {
        cin >> z >> x >> y;
        if(z==1) {
            if(findRoot(nums,x)!=findRoot(nums,y)) {
                if(height(nums,x) > height(nums,y)) nums[findRoot(nums,y)] = findRoot(nums,x);
                else nums[findRoot(nums,x)] = findRoot(nums,y);
            }
        }
        if(z==2) {
            if(findRoot(nums,x)==findRoot(nums,y)) cout << "Y"<<endl;
            else cout << "N" << endl;
        }
    }
}

int main() {
    unionFind();
    // student();     // void type function does not need to "cout".
}