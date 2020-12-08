#include<bits/stdc++.h>
using namespace std;
const int N=1e6+2;
const int X=30;
vector<int> lis[X];
int pos[X];
char ans[N];
void unionn(int a,int b){
	if(lis[pos[a]].size()>lis[pos[b]].size()){
		while(lis[pos[b]].size()){
			lis[pos[a]].push_back(lis[pos[b]].back());
			lis[pos[b]].pop_back();
		}
		swap(pos[a],pos[b]);
	}
	else{
		while(lis[pos[a]].size()){
			lis[pos[b]].push_back(lis[pos[a]].back());
			lis[pos[a]].pop_back();
		}
	}
}
signed main(){
	freopen("PAINT.inp","r",stdin);
	freopen("PAINT.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q,n=0,i,j,k,l;
	char x,y;
	cin>>q;
	for(i=0;i<26;i++){
		pos[i]=i;
	}
	while(q--){
		cin>>i;
		if(i==1){
			cin>>x;
			lis[pos[(int)(x-'a')]].push_back(n);
			n++;	
		}
		else{
			cin>>x>>y;
			if(x==y){
				continue;
			}
			unionn((int)(x-'a'),(int)(y-'a'));
		}
	}
	for(i=0;i<26;i++){
		for(j=0;j<lis[pos[i]].size();j++){
			ans[lis[pos[i]][j]]=(char)(i+'a');
		}
	}
	cout<<ans;
}
