#include <bits/stdc++.h>
using namespace std;
const string filename="SOCKS";
const int nmax=5e5+5;
int n,Q,posT;
bool red[nmax],cx1[nmax],cx2[nmax];
vector<vector<int> > d;

bool checksub1() {
    int way[3];
    for(int i=1;i<=3;++i)   way[i]=0;
    for(int i=1;i<=n;++i) {
        if(d[i].size()>2)   return false;
        ++way[d[i].size()];
    }
    if(way[1]==2 && way[2]==n-2) return true;
    return false;
}

void sub1() {
    int s=0;
    for(int i=1;i<=n;++i) {
        if(red[i])  ++s;
    }
    while(Q--) {
        int x;
        scanf("%d", &x);
        if(red[x])  {
            --s;
            red[x]=false;
        }
        else {
            if(!red[x])  {
                ++s;
                red[x]=true;
            }
        }
        if(s>1) printf("1\n");
        else printf("0\n");
    }
}

bool checksub2() {
    int way[4];
    for(int i=1;i<=4;++i)   way[i]=0;
    for(int i=1;i<=n;++i) {
        if(d[i].size()>3)   return false;
        ++way[d[i].size()];
        if(d[i].size()==3)  posT=i;
    }
    if(way[1]==3 && way[3]==1 && way[2]==n-4) {
        return true;
    }
    return false;
}

void track1(int u) {
    int v=d[u][0];
    if(cx1[v])   return;
    cx1[v]=true;
    track1(v);
}
void track2(int u) {
    int v=d[u][0];
    if(cx2[v])   return;
    cx2[v]=true;
    track2(v);
}

void sub2() {
    track1(posT);
    swap(d[posT][0],d[posT][1]);
    track2(posT);
    int s=0,s1=0,s2=0;
    for(int i=1;i<=n;++i) {
        if(red[i])  ++s;
        if(cx1[i] && red[i])   ++s1;
        if(cx2[i] && red[i])   ++s2;
    }
    while(Q--) {
        int x;
        scanf("%d", &x);
        if(red[x])  {
            --s;
            red[x]=false;
            if(cx1[x])   --s1;
            if(cx2[x])   --s2;
        }
        else {
            if(!red[x])  {
                ++s;
                red[x]=true;
                if(cx1[x])   ++s1;
                if(cx2[x])   ++s2;
            }
        }
        if(s>1 && s2>0 && s1>0) {
            printf("2\n");
            continue;
        }
        if(s>1 && s1>0 && s2==0) {
            printf("1\n");
            continue;
        }
        if(s>1 && s2>0 && s1==0) {
            printf("1\n");
            continue;
        }
        if(s>1) {
            printf("1\n");
            continue;
        }
        if(s==0) {
            printf("0\n");
        }
    }
}

int32_t main() {
    freopen((filename+".INP").c_str(),"r",stdin);
    freopen((filename+".OUT").c_str(),"w",stdout);
    scanf("%d%d", &n, &Q);
    d.resize(n+2);
    for(int i=1;i<=n;++i) {
        int x;
        scanf("%d", &x);
        if(x==1)    red[i]=true;
    }
    for(int i=1;i<n;++i) {
        int u,v;
        scanf("%d%d", &u, &v);
        d[u].push_back(v);
        d[v].push_back(u);
    }
    if(checksub1()) {
        sub1();
        return 0;
    }
    if(checksub2()) {
        sub2();
        return 0;
    }
    return 0;
}
