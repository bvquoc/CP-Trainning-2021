#include<bits/stdc++.h>
using namespace std;

string cong(string a,string b)
{
    if (a.size() > b.size()) b.insert(0,a.size()-b.size(),'0');
    if (a.size() < b.size()) a.insert(0,b.size()-a.size(),'0');
    long tam,n=0;
    string s="";
    for (long i=a.size()-1;i>=0;i--)
    {
        tam=int(a[i])+int(b[i])-96+n;
        n=tam/10;
        s=char(tam%10+48) + s;
    }
    if (n > 0) s='1'+s;
    return s;
}

string a, b;
long test;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> test;
    while (test--)
    {
        cin >> a >> b;
        cout << cong(a, b) << '\n';
    }

    return 0;
}
