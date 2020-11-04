#include<bits/stdc++.h>
using namespace std;
string S1,S2;
int F[50];
void solve()
{
	int n=S1.length(),m=S2.length();
	S1='0'+S1;
	S2='0'+S2;
	int i=n,j=m,k=max(n,m)+7;
	int q=k-1,du=0;
	while(1)
	{
		int temp=(int)(S1[i]-'0')+(int)(S2[j]-'0')+du;
		if(temp!=0) du=temp/10;
		else du=0;
//		cout<<i<<" "<<j<<" "<<temp<<" "<<du<<endl;
		k--;
		F[k]=temp%10;
		if(i==0 && j==0) break;
		if(i>0)i--; 
		if(j>0)j--;	
	}
	while(F[k]==0) k++;
	for(int i=k;i<=q;i++) cout<<F[i]; cout<<endl;
}
int main()
{
	int t;
//	freopen("ALICEADD.inp","r",stdin);
	cin>>t;
	while(t--)
	{
		cin>>S1>>S2;
		solve();
	}
	return 0;
}
