#include<bits/stdc++.h>
using namespace std;
ifstream fi("COOLMAC.inp");
ofstream fo("COOLMAC.out");
const int nmax=1e5+5;
const int vc=1e9+7;
int n,m,tmin,tmax,t[nmax];
struct II
{
    int l,r;
};
II C[nmax];
bool cmp(II A,II B)
{
    if(A.l<B.l||(A.l==B.l&&A.r<B.r)) return true;
    else return false;
}
stack<II>st;
int main()
{
    fi>>m;
    for(int i=1;i<=m;++i) fi>>C[i].l>>C[i].r;
    fi>>n;
    for(int i=1;i<=n;++i) fi>>t[i];
    tmin=vc;
    tmax=100000;
    for(int i=1;i<=n;++i)
    {
        tmin=min(tmin,t[i]);
    }
    sort(C+1,C+m+1,cmp);
    st.push(II({0,tmin}));
    for(int i=1;i<=m;++i)
    {
        if(st.top().l<=C[i].l&&C[i].r<=st.top().r) continue;
        if(C[i].l<=st.top().r) st.push(C[i]);
    }
    /*while(!st.empty())
    {
        fo<<st.top().l<<" "<<st.top().r<<"\n";
        st.pop();
    }*/
    if(st.top().r!=tmax) fo<<-1;
    else fo<<st.size()-1;
}
