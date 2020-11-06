#include<bits/stdc++.h>
using namespace std;
long long M[1000006],S[1000006],BS[1000006],s1,s2,x,t;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	for (long long c=2;c<=1e6+5;c++) M[c]=S[c]=1;
	for (long long i=2;i<=1e6+5;i++)
	 if (M[i]==1)
	  {
	  	 for (long long j=i;j<=1e6+5;j+=i)
	  	  {
	  	  	long long t=j,dem=0;
	  	  	while (t%i==0)
	  	  	{
	  	  		dem++; t/=i;
			}
			   if(i==2) BS[j]=dem;
		    	M[j]*=dem+1;S[j]*=(dem*2)+1;
			}
	  }
	  cin>>t;
	  while (t--)
	  {
	  	cin>>x;
          if (x%2!=0)
          {
        s1=M[x]*M[x+1]*M[x+2];
        s2=S[x]*S[x+1]*S[x+2];
          }
          else
          {
              s1=M[x]*M[x+1]*M[x+2]/((BS[x]+1)*(BS[x+2]+1))*(BS[x]+BS[x+2]+1);
	  	      s2=S[x]*S[x+1]*S[x+2]/((2*BS[x]+1)*(2*BS[x+2]+1))*(2*BS[x]+2*BS[x+2]+1);
          }
		  cout<<s2/2-s1+1 << "\n";
	  }
}
