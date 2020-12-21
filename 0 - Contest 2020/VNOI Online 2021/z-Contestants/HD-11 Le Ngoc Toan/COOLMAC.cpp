#include <bits/stdc++.h>

using namespace std;

#define maxn 100005

typedef pair<int,int> II;

II e[maxn];

int m,n;

int l[maxn],r[maxn];

int t[maxn];

int tmin=2000000000;

set<int> q;

int main(){

freopen ("COOLMAC.inp","r",stdin);

freopen ("COOLMAC.out","w",stdout);

scanf("%d",&m);

for(int i=1;i<=m;++i){

scanf("%d %d",&l[i],&r[i]);

e[i]={l[i],r[i]};

}

scanf("%d",&n);

for(int i=1;i<=n;++i){

scanf("%d",&t[i]);

tmin=min(tmin,t[i]);

}

sort(e+1,e+m+1);

int j=1;

int ds=0;

while(e[j].first<=tmin && j<=m ){

q.insert(e[j].second);

++j;

}

int kt=1;

while(tmin<100000){

++ds;

if(q.empty()){

kt=0;

break;

}

int u=*q.rbegin();

tmin=u;

q.clear();

while(e[j].first<=tmin && j <= m){

q.insert(e[j].second);

++j;

}

}
if(kt==0) printf("-1");

else printf("%d",ds);

}







