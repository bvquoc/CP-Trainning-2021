#include <bits/stdc++.h>

using namespace std;

int n,k,a[1001],b[1000];

void nhap()
{
    cin >> n >> k;
    for(int i=1 ;i <= n; i++)
    {
        cin >> a[i];
    }
}
bool tong(int n,int k)
{
    long s=a[1];
    for(int i=2 ; i <= n ; i++)
    {
        if (b[i-1]==0)
        {
            s+=a[i];
        }
        else s-=a[i];
    }
    if(s%k==0) return true;
    else return false;
}
bool kq=false;
void xuat()
{
    if (kq)
    {
        cout << 1 << endl;
        for (int i=1 ; i<= n-1; i++)
        {
            if(b[i]==1)
            {
                cout << "-";
            }
            else cout << "+";
        }
    }
    else cout << 0;
}
void duyet(int i)
{
    for (int j=0 ; j<=1 ; j++)
    {
        b[i]=j;
        if(i==n-1)
        {
            if (tong(n,k))
            {
                kq=true;
                break;
            }
        }
        else duyet(i+1);
    }
}
int main()
{
    freopen("kmult.inp","r",stdin);
    freopen("kmult.out","w",stdout);
    nhap();
    duyet(1);
    xuat();
}
