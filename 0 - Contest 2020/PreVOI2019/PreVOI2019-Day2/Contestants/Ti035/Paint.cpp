//Rochy'.'
#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define fl(i,a,b) for(int i=a;i<b;++i)
#define fa(i,a) for(auto (i):(a))
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define vi vector <int>
#define ii pair <int,int>
#define pb push_back
using namespace std;
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));
if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar()))x=x*10+c-48;if(nega)x=-x;}
template <typename T> inline void writep(T x){if(x>9)writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
template <typename R, typename D> inline void Min(R &a, D b){if(a>b) a=b;}
template <typename D, typename R> inline void Max(D &a, R b){if(a<b) a=b;}
const int N=0000;
int Q,room,id[30];
vector<char> last;
vi ve[30];
void weave(int u,int v){
	if(ve[id[u]].size()>ve[id[v]].size()) swap(id[u],id[v]);
	fa(cek,ve[id[u]])
		ve[id[v]].pb(cek);
	ve[id[u]].clear();
}
int main(){
	ios_base::sync_with_stdio(NULL);
	cin. tie(NULL); cout. tie(NULL);
	freopen("Paint.inp" , "r", stdin);
	freopen("Paint.out", "w", stdout);
	fo(i,1,26) id[i]=i;
	cin>>Q;while(Q--){
		int ty;cin>>ty;
		if(ty==1){
			char color;cin>>color;
			ve[id[color-'a'+1]].pb(room);
			++room;
			continue;
		}
		char u,v;cin>>u>>v;
		weave(u-'a'+1,v-'a'+1);
	}
	last.resize(room);
	fo(i,1,26){
		fa(cek,ve[id[i]]){
			last[cek]=(char)(i+'a'-1);
		}
	}
	fa(cek,last) cout<<cek;
	return 0;
}