#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > lis;
const int eps=1e-6;
bool cmp(pair<int,int> x,pair<int,int> y){
	return x.first*y.second<y.first*x.second;
}
int n,m,xa,ya,xb,yb,xc,yc,xd,yd;
bool check(pair<int,int> t){
	double ax1=xa+(double)(t.first)/t.second * (xb-xa),ay1=ya + (double)(t.first)/t.second * (yb-ya);
	if(ax1<0){
		ax1=-ax1;
	}
	if(ay1<0){
		ay1=-ay1;
	}
	double posax1=ax1-(int)(ax1/m)*m,posay1=ay1-(int)(ay1/n)*n;
	double cx1=xc+(double)(t.first)/t.second * (xd-xc),cy1=yc + (double)(t.first)/t.second * (yd-yc);
	if(cx1<0){
		cx1=-cx1;
	}
	if(cy1<0){
		cy1=-cy1;
	}
	double poscx1=cx1-(int)(cx1/m)*m,poscy1=cy1-(int)(cy1/n)*n;
	if((int)(ax1/m)&1){
		posax1=m-posax1;
	}
	if((int)(ay1/n)&1){
		posay1=n-posay1;	
	}
	if((int)(cx1/m)&1){
		poscx1=m-poscx1;
	}
	if((int)(cy1/n)&1){
		poscy1=n-poscy1;
	}
	if(abs(posax1-poscx1)<=eps&&abs(posay1-poscy1)<=eps){
		return true;
	}
	return false;
}
signed main(){
	freopen("MOTION.inp","r",stdin);
	freopen("MOTION.out","w",stdout);
//	freopen("cac.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i,j=0,t;
	cin>>t;
	for(j=1;j<=100;j++){
		for(i=1;i<=100;i++){
			if(__gcd(i,j)==1){
				lis.push_back({j,i});
			}
		}
	}	
	sort(lis.begin(),lis.end(),cmp);
	while(t--){
		cin>>m>>n>>xa>>ya>>xb>>yb>>xc>>yc>>xd>>yd;
		for(i=0;i<lis.size();i++){
			if(check(lis[i])){
				cout<<lis[i].first<<' '<<lis[i].second<<'\n';
				break;
			}
			if(i==lis.size()-1){
				cout<<"-1\n";
				break;
			}
		}
	}
}
/*
5
7 2 0 0 1 2 7 2 6 0
3 3 0 0 3 3 3 0 2 1 
4 4 0 2 2 4 3 2 2 2
4 4 1 0 4 4 3 0 0 4
9 7 0 0 1 1 9 0 8 7
*/
