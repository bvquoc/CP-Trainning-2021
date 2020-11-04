#include<bits/stdc++.h>
using namespace std;

string doSum(string a, string b)
{
    if(a.size() < b.size())
        swap(a, b);

    int j = a.size()-1;
    for(int i=b.size()-1; i>=0; i--, j--)
        a[j]+=(b[i]-'0');

    for(int i=a.size()-1; i>0; i--)
    {
        if(a[i] > '9')
        {
            int d = a[i]-'0';
            a[i-1] = ((a[i-1]-'0') + d/10) + '0';
            a[i] = (d%10)+'0';
        }
    }
    if(a[0] > '9')
    {
        string k;
        k+=a[0];
        a[0] = ((a[0]-'0')%10)+'0';
        k[0] = ((k[0]-'0')/10)+'0';
        a = k+a;
    }
    return a;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("ALICEADD.INP","r",stdin);
//	freopen("ALICEADD.OUT","w",stdout);
	string a,b;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		cout<<doSum(a,b)<<"\n";
	}
	return 0;
}
