#include <bits/stdc++.h>

using namespace std;

int main()
{
	int m,l,r;
  vector<pair <int, int> > a;
  freopen("coolmac.inp","r",stdin);
  freopen("coolmac.out","w+",stdout);
	int minn=1000000;
	cin>>m;
	for(int i=0;i<m;++i)
	{
		cin>>l>>r;
		if(l<minn) minn=l;
		if(r<minn) minn=r;
		a.push_back(make_pair (l,r));
	}
	sort(a.begin(), a.end());
	int n;
	cin>>n;
	int d[n];
	for(int i=0;i<n;i++) cin>>d[i]; 
  sort(d, d+n);
	   for(int i=0;i<a.size();++i) 
          if(a[i].second<d[0]) 
            {
            	a[i].first=-1;
            	a[i].second=-1;
			}
  	 /*for(int i=0;i<m;++i){
	     cout<<a[i].first<<" "<<a[i].second;
	             cout<<"\n";}*/
	   int maxx=d[0];
	  int i=0,k=0;
	   while(i<a.size())
	   {   if(a[i].first<=maxx && a[i].second>=maxx)
	           {
	            k++;
			    maxx=a[i].second;} 
			     else
			     if(a[i].first>maxx) k--;
				  i++;
			     if(maxx==100000) break; 
				 }          
	 
	 
	    if(k==0) cout<<-1; else cout<<k;   

}


