#pragma GGC optimize "Ofast"
#include<bits/stdc++.h>
using namespace std;

int n ,m ,k ,x ,y;
int pr[500005];
int l[500005];
int dek[500005];
int kql ,kqr ,ma;
string s;
vector<int> a[500005];

void di( int u )
{
    for( int v : a[u] )
    {
        if( pr[v] ) continue;
        pr[v] = pr[u];
        l[pr[u]] += l[v];
        di(v);
    }
}

main()
{
    freopen("DECOR.inp" ,"r" ,stdin);
    freopen("DECOR.out" ,"w" ,stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> k;
    cin >> s;
    for( int i = 0 ; i < n ;i++ )
    {
        l[i+1] = (s[i]=='1');
    }
    for( int i = 1 ; i <= m ;i++ )
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for( int i = 1 ; i <= n ;i++ )
    {
        if( pr[i] == 0 )
        {
            pr[i] = i;
            di(i);
            //cout<<i<<' '<<l[i]<<'\n';
        }
    }
    int j = 1;
    for( int i = 1 ; i <= n ;i++ )
    {
        while( j <= i && l[pr[i]] == 0 && k == 0 )
        {
            if( dek[pr[j]] ) k++;
            else l[pr[j]]++;
            j++;
        }
        if(l[pr[i]]) l[pr[i]]--;
        else
        {
            k--;
            dek[pr[i]]++;
        }
        if( i-j+1 > ma )
        {
            ma = i-j+1;
            kql = j ;
            kqr = i;
        }
    }
    if( kql == 0 && kqr == 0 )
    {
        cout<<-1<<'\n';
        return 0;
    }
    cout<<kql<<' '<<kqr<<'\n';
}
