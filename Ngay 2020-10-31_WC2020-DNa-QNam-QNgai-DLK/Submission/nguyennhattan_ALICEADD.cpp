#include <bits/stdc++.h>

using namespace std;

string sum(string x, string y)
{
    while (x.size()>y.size())
        y='0'+y;
    while (y.size()>x.size())
        x='0'+x;
    int c=0;
    string su;
    for (int i=x.size()-1; i>=0; i--)
    {
        int m=x[i]-'0';
        int n=y[i]-'0';
        int s=(m+n)%10+c;
        c=(m+n)/10;
        su=(char) (s+'0')+su;
    }
    if (c==1) su=(char) (c+'0')+su;
    return su;
}

int main()
{
    int t;
    cin>>t;
    string a[11],b[11];
    for (int i=1; i<=t; i++)
    {
        cin>>a[i]>>b[i];
    }
    for (int i=1; i<=t; i++)
        cout<<sum(a[i],b[i])<<endl;
}
