#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long k,i,x,y,kq;
	cin>>k;
	  if (k==0) cout<<0;
	  else if (k==-1||k==1) cout<<"none";
	  else 
	  if (k>0)
	  {
	  	kq=1e18;
	  	for (i=1;i*i<=k;i++)
	  	   if (k%i==0)
	  	   {
	  	   	  x=i; y=k/i;
	  	   	if ((x+y)%2==0)  kq=min(kq,(x+y)/2);
		   }
		  if (kq==1e18) cout<<"none"; else   cout<<kq;
	  }
	  else
	  {
	  	k=-k; kq=1e18;
	  	 for (i=1;i*i<=k;i++)
	  	   if (k%i==0)
	  	   {
	  	   	  x=i; y=k/i;
	  	   	if ((x+y)%2==0)	 kq=min(kq,y-(x+y)/2);
		   }
		 if (kq==1e18) cout<<"none"; else    cout<<kq;
	  }
}
