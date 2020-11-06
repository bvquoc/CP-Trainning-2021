#include<bits/stdc++.h>
using namespace std;
long long kt[1000006],kk[1000006],me[1000006];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int i,z,j,x,t; long long dem1,dem2;
	  for (i=1;i<=1e6+5;i++) kt[i]=kk[i]=1; 
	for (i=2;i<=1e6+5;i++)
	 if (kt[i]==1)
	  {
	  	 for (j=i;j<=1e6+5;j+=i)
	  	  {
	  	  	  int z=j,dem=0;
	  	  	while (z%i==0)
	  	  	{
	  	  		dem++; z=z/i;
			}
			   if(i==2) me[j]=dem;
		    	kt[j]=kt[j]*(dem+1); kk[j]=kk[j]*(2*dem+1);
			}
	  }
	  cin>>t;
	  while (t--)
	  {
	  	cin>>x;
	  	 if (x%2!=0)
	  	 {
	  	dem1=kt[x]*kt[x+1]*kt[x+2]; 
	  	dem2=kk[x]*kk[x+1]*kk[x+2]; }
	  	else 
	  	{
	  	 	 dem1=kt[x]*kt[x+1]*kt[x+2]/((me[x]+1)*(me[x+2]+1))*(me[x]+me[x+2]+1); 
	  	      dem2=kk[x]*kk[x+1]*kk[x+2]/((2*me[x]+1)*(2*me[x+2]+1))*(2*me[x]+2*me[x+2]+1);
		  }
		  cout<<dem2/2-dem1+1<<"\n"; 
	  }
}
