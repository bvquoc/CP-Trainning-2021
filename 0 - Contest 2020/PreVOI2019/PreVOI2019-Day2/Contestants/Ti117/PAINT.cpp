#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n,type,len,ptr[30];
char c,d;
vector<int> pos[30];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("PAINT.inp","r",stdin);
	freopen("PAINT.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> type;
		if(type == 1){
			cin >> c;
			len++;
			pos[c - 96].push_back(len);
		}else{
			cin >> c >> d;
			int x = c - 96, y = d - 96;
			if(x == y) continue;
			if(pos[x].size() > pos[y].size()){
				swap(pos[x], pos[y]);
			}
			for(int j: pos[x]){
				pos[y].push_back(j);
			}
			pos[x].clear();
		} 
	}
	for(int i=1;i<=26;i++){
		sort(pos[i].begin(), pos[i].end());
		ptr[i] = 0;
	}
	for(int i=1;i<=len;i++){
		for(int j=1;j<=26;j++){
			if(ptr[j] < pos[j].size() && pos[j][ptr[j]] == i){
				cout << (char)(j + 96);
				ptr[j]++;
				break;
			}
		}
	}
}
