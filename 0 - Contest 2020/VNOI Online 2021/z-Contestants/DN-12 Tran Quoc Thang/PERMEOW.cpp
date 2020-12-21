#pragma GCC optimize "Ofast"
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int n ,x ,kq;
vector<int> a ,b;

int fen[200005];

void upd( int p ,int gt )
{
    for( int i = p ; i <= n ;i+=i&-i )
    {
        fen[i] += gt;
    }
}

int get( int p )
{
    int res = 0;
    for( int i = p ; i ;i-=i&-i )
    {
        res += fen[i];
    }
    return res;
}

main()
{
    freopen("PERMEOW.inp" ,"r" ,stdin);
    freopen("PERMEOW.out" ,"w" ,stdout);
    cin >> n;
    for( int i = 1 ; i <= n ;i++ )
    {
        cin >> x;
        a.push_back(x);
    }
    for( int i = 1 ; i <= n ;i++ )
    {
        cin >> x;
        b.push_back(x);
    }
    while(1)
    {
        /*for( int i : a )
        {
            cout<<i<<' ';
        }
        cout<<'\n';*/
        for( int i = 1 ; i <= n ;i++ ) fen[i] = 0;
        for( int i : a )
        {
            kq += (i-get(i)-1);
            kq %= mod;
            upd(i ,1);
        }
        //cout<<kq-pr<<'\n';
        //re.push_back(kq-pr);
        if( a==b ) break;
        next_permutation(a.begin() ,a.end());
    }
    cout<<kq<<'\n';
    /*int temp = 0;
    for( int i = 0 ; i < re.size() ;i++ )
    {
        //cout<<re[i]<<'\n';
        temp += re[i];
        if( i == 0 )
        {
            cout<<re[i]<<'\n';
            cout<<temp<<'\n';
        }
        else if( i == re.size()-1 )
        {
            cout<<re[i]<<'\n';
            cout<<temp<<'\n';
        }
        else if( re[i] != re[i-1] && re[i] != re[i+1] )
        {
            cout<<re[i]<<'\n';
            cout<<temp<<'\n';
        }
    }
    cout<<"pp "<<kq<<'\n';
    int te = 72;
    int tt = 0;
    for( int i = 1 ; i <= 500 ;i++ )
    {
        tt += te;
        te+= 24;
        cout<<i <<' '<< tt<<'\n';
    }*/
}
