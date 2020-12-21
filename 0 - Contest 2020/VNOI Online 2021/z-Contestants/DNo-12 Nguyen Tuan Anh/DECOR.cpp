#include <bits/stdc++.h>
using namespace std;
const string filename="DECOR";
const int nmax=5e5+5;
struct canswa {int u,v;}b[nmax];
int n,m,k,a[nmax];

void sub1() {
    int L=-1,R,l,r,s=0;
    bool ok=false;
    for(int i=1;i<=n;++i) {
        if(a[i]==1) {
            if(!ok) {
                l=i;
                ok=true;
            }
            else r=i;
        }
        if(ok && a[i]==0) {
            ok=false;
            if((r-l+1)>s) {
                s=r-l+1;
                L=l;
                R=max(r,l);
            }
        }
    }
    if(L!=-1)   cout<<L<<" "<<R;
    else cout<<-1;
}

void sub2() {
    int l,r;
    bool ok=false;
    vector<canswa> li;
    canswa tam;
    tam.u=tam.v=0;
    li.push_back(tam);
    for(int i=1;i<=n;++i) {
        if(a[i]==1) {
            if(!ok) {
                l=i;
                ok=true;
            }
            else r=i;
        }
        if(ok && a[i]==0) {
            ok=false;
            canswa x;
            x.u=l;
            x.v=max(r,l);
            li.push_back(x);
        }
    }
    int f1[li.size()],f2[li.size()];
    if(li.size()==1) {
        cout<<-1;
        return;
    }
    f2[0]=0;
    f1[0]=li[0].v-li[0].u+1;
    for(int i=1;i<li.size();++i) {f1[i]=f1[i-1]+(li[i].v-li[i].u+1);}
    for(int i=1;i<li.size();++i) {f2[i]=f2[i-1]+(li[i].u-li[i-1].v-1);}
    int res=0;
    for(int i=0;i<li.size();++i) {
        res=max(res,li[i].v-li[i].u+1);
    }
    int rktake=0,L,R;
    for(int i=1;i<li.size();++i) {
        for(int j=i;j<li.size();++j) {
            int ktake=f2[j]-f2[i-1];
            if(i==j)    ktake=0;
            int light=f1[j]-f1[i-1];
            if(ktake<=k && res<ktake+light) {
                res=ktake+light;
                rktake=ktake;
                L=li[i].u;
                R=li[j].v;
            }
        }
    }
    k-=rktake;
    int s1=0,s2=0;
    int pos=L-1;
    while(pos>0 && a[pos]==0) {
        ++s1;
        --pos;
    }
    pos=R+1;
    while(pos<=n && a[pos]==0) {
        ++s2;
        ++pos;
    }
    if(s1>s2) {
        if(s1<=k) L-=s1;
        if(k<s1)    L-=s1;
    }
    if(s2>s1) {
        if(s1<=k) R+=s2;
        if(k<s1)    R+=s2;
    }
    cout<<L<<" "<<R;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen((filename+".INP").c_str(),"r",stdin);
    freopen((filename+".OUT").c_str(),"w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i) {
        char x;
        cin>>x;
        a[i]=x-48;
    }
    for(int i=1;i<=m;++i) {cin>>b[i].u>>b[i].v;}
    if(m==0 && k==0) {
        sub1();
        return 0;
    }
    if(m==0) {
        sub2();
        return 0;
    }
    return 0;
}
