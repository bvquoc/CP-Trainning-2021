#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long

const string INP=".INP", OUT=".OUT";
const string FILENAME="PALINPATH";
const int N=50004;

int n, trace[N], len=0;
string c;
vector <int> ke[N], l_index;
string d[N];
vector <int> index[N];
set <int> cur;
int P[200005], res=0;
bool doSub2=true;

string convertStr(const string &s) { 
    string newString="@"; 
    for (int i=0; i<s.size(); i++) { 
        newString+="#"+s.substr(i, 1);
    } 
    newString+="#$";
    return newString;
} 
string getPalindrome(const string &s, vector <int> id) { 
    string Q=convertStr(s);
    int c=0, r=0;
    for (int i=1; i<Q.size()-1; i++) {
        int iMirror=c-(i-c);
        if(r>i) P[i]=min(r-i, P[iMirror]); 
        while (Q[i+1+P[i]]==Q[i-1-P[i]]) P[i]++; 
        if (i+P[i]>r) { 
            c=i;
            r=i+P[i]; 
        } 
    }
    int maxPalindrome=0;
    int centerIndex=0;
    for (int i=1; i<Q.size()-1; i++) { 
        if (P[i]>maxPalindrome) { 
            maxPalindrome=P[i]; centerIndex=i; 
        } 
    }
    int pos=(centerIndex-1-maxPalindrome)/2;
    cur.clear();
    for (int i=pos;i<pos+maxPalindrome;i++)
        cur.insert(id[i]);
    return s.substr((centerIndex-1-maxPalindrome)/2,maxPalindrome); 
}

void dfs(int u) {
    d[u]=d[trace[u]];
    d[u]+=c[u];
    index[u]=index[trace[u]];
    index[u].push_back(u);
    int cnt=0;
    for (int v:ke[u])
    if (d[v].empty()) {
        trace[v]=u;
        dfs(v);
        cnt++;
    }
    if (cnt==0) l_index.push_back(u);
}

void DFS(int u, int _v) {
    d[u]=d[trace[u]];
    d[u]+=c[u];
    index[u]=index[trace[u]];
    index[u].push_back(u);
    if (u==_v) return;
    for (int v:ke[u])
    if (d[v].empty()) {
        trace[v]=u;
        dfs(v);
    }
}

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    cin>>n>>c;
    for (int i=1;i<n;i++) {
        int u, v;
        cin>>u>>v;
        if (u>v) swap(u,v);
        if (u+1!=v) doSub2=false;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }

    if (doSub2) {
        for (int i=1;i<=n;i++)
            index[n+1].push_back(i);
        string s=getPalindrome(c,index[n+1]);
        cout<<cur.size();
        return 0;
    }
    
    c=' '+c;
    for (int i=1;i<=n;i++)
    if (d[i].empty()) dfs(i);
    for (int i:l_index) {
        string s=getPalindrome(d[i],index[i]);
        if (cur.size()>res && s.size()>=len) {
            len=s.size();
            res=cur.size();
        }
    }
    cout<<res;
    return 0;
}




