#include <bits/stdc++.h>
using namespace std;
string a;
string b;
string cong(string a, string b)
{
    if (a.size()>b.size())
    {
        string temp=a;
        a=b;
        b=temp;
    }
    while (a.size()<b.size()) a='0'+a;
    string res="";
    int nho=0;
    for(int i=a.size()-1; i>=0; i--)
    {
        int csa=((int)(a[i]-'0'));
        int csb=((int)(b[i]-'0'));
        int tong=csa+csb+nho;
        nho=tong/10;
        int tmp=tong%10;
        res+=(char)(tmp+'0');
    }
    if (nho!=0) cout<<nho;
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.ignore(0);
    cout.tie(0);
    int T;
    cin>>T;
    while (T--)
    {
        cin>>a>>b;
        cout<<cong(a,b)<<"\n";
    }
}
