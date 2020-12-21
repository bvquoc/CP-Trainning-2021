#include<bits/stdc++.h>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define pb push_back
#define f first
#define s second
#define nmax 100005
using namespace std;
int a[nmax], b[nmax], n;
void sub1()
{
    int res = 0;
    For(i, 1, n)
        For(j, i+1, n)
            if(a[j] != j)
            {
                int t = a[j];
                swap(a[j], a[t]);
                res++;
            }
        cout<<res;
}
int main()
{
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    freopen("PERMEOW.inp","r",stdin);
    freopen("PERMEOW.out","w", stdout);
    cin >> n;
    int tg = 0;
    For(i, 1, n)
        cin >> a[i];
    For(i, 1, n){
        cin >> b[i];
        if(b[i] == a[i])
            tg ++;
        }
    if(tg == n)
        sub1();
}
