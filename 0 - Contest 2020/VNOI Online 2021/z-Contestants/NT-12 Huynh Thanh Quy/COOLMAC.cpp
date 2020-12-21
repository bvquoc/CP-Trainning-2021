#include<bits/stdc++.h>
#define name "COOLMAC"
#define ios  ios_base::sync_with_stdio(false); cin.tie(0);
#define pii pair<int , int >
using namespace std;
const int maxn=1e5+7;
pii a[maxn];
int b[maxn];
bool d[maxn];
int n, m;
void enter()
{
    cin>> m;
    for(int i=1; i<=m; i++)
        cin>> a[i].first>> a[i].second;
    cin>> n;
    for(int i=1; i<=n; i++)
        cin>> b[i];

}
bool compre(pii A, pii B)
{
    return A.second> B.second || A.second==B.second&&A.first<B.first;
}
int main()
{

    freopen(name".INP","r",stdin);
    freopen(name".OUT","w",stdout);
    enter();
    sort(a+1, a+m+1, compre);

    sort(b+1, b+n+1);
    if(a[1].second!=100000) {cout<<-1; return 0;}
    if(a[1].first<=b[1])
    {
        cout<<1 ;
        return 0;
    }

    int cnt=0,dem=1;
    int ck=b[1];
    while(1)
    {
         priority_queue<int> qu;
cnt=0;
        for(int i=2; i<=m; i++)
        {
            if(!d[i])
            {

                if(ck>=a[i].first&& ck<=a[i].second)
                {   cnt++;
                    qu.push(a[i].second);
                    d[i]=true;
                }
            }
        }
        if(cnt==0)
        {
            cout<<-1 ;
            return 0;
        }
        int k=qu.top();
        if(k>=a[1].first)
        {
            cout<<dem+1;
            return 0;
        }
        else
        {
            dem++;
            ck=k;
        }

    }


    return  0;
}
