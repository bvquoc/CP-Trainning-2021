#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long a,b,c,x,y,e,w,q,k;
	cin>>a>>b>>c;
      x=a/c+1; y=(b-1)/c;
      if (x*c>b) 
      cout<<(b-a)/2+(b-a)%2;
      else 
      {
      	  x=x*c-1; e=(x-a)/2+(x-a)%2;
	      y=y*c+1; w=(b-y)/2+(b-y)%2;
		  q=(c-2)/2+(c-2)%2; 
		  k=b/c-(a-1)/c;
		  cout<<e+w+(k-1)*q+k;
	  }
} 
