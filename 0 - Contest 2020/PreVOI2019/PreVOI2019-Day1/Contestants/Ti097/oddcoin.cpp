#include <bits/stdc++.h>
using namespace std;
vector < int > mg;
int l[21];
int t , res , q , sl , x ;
set < int > vecT;
void dequy(int vt ,int tong ,int sl )
{
    if (tong < 0 ) return ;
    if ( tong==0 )
    {
        res = min(res , sl );
        return ;
    }
    if (vt==14)
    {
        int A = 50000;
        int B = mg[15];
        if (tong < A && tong < B) return ;
        if (A>B) swap(A,B);
        if (tong == A || tong == B)
        {
            res = min(res, sl+1);
            return ;
        }

        if (tong < B )
        {
            if ( tong % A != 0 ) return ;
            else {
                    res = min(res , tong /A + sl);
                    return ;
                 }
        }

        //tham
        //if (A!=50000) swap(A,B)

        if (tong % __gcd(A,B) != 0 ) return ;

        for (int j=0;j<=4;j++)
        {
            int tg = tong - j*B;
            if (tg>=0 && tg%A==0) res = min(res, sl + j + (tg/A) );
        }

        return ;
    }
    dequy(vt+1,tong,sl );
    dequy(vt+1,tong-mg[vt],sl+1);
    if (l[vt]==1) dequy(vt+1,tong-2*mg[vt],sl+2);
}
int main()
{
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();cout.tie();
    t = 1;
    for (int i=1;i<=5;i++)
    {
        mg.push_back(1*t);l[ mg.size() -1 ] = 1;
        mg.push_back(3*t);l[ mg.size() -1 ] = 2;
        mg.push_back(5*t);l[ mg.size() -1 ] = 2;
        t*=10;
        sl+=3;
    }

    mg.push_back(0);
    cin>>q;
    while (q--)
    {
        cin>>x>>t;
        mg[sl]=x;
        res = t;
        dequy(0,t,0);
        cout<<res<<"\n";
    }
    return 0;
}
