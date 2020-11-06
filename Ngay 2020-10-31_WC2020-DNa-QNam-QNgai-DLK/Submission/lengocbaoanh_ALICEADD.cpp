#include<bits/stdc++.h>
using namespace std;
string cong(string a,string b)
{
    string c="",tam;
    long long sum,x,y,i,carry=0;
    while(a.size()<b.size()) a="0"+a;
    while(b.size()<a.size()) b="0"+b;
    for(i=a.size()-1;i>=0;i--)
    {
        x=a[i]-48;
        y=b[i]-48;
        sum=x+y+carry;
        carry=sum/10;
        tam=sum%10+48;
        c=tam+c;
    }
    if(carry>0) c="1"+c;
    return c;
}
int main()
{
	long long t;
	string a, b;
	cin >> t;
	while(t--) {
	cin >> a >> b;
	cout << cong(a, b) << endl;
    }
}
