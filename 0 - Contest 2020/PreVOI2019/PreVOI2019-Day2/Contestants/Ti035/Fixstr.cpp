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
const int N=1000006,N1=1003;
string save[N1],s;
int n,m,l[N],r[N];
int t[N<<2],lz[N<<2];
char ty[N];
bool haveU;
void Sub1(){
	save[0]=s;
	fo(i,1,m){
		save[i]=save[i-1];
//		cout<<save[i]<<'\n';
		switch(ty[i]){
			case'U':{
				save[i]=save[l[i]-1];
				break;
			}
			case'C':{
				if(save[i][l[i]]==')')save[i][l[i]]='(';
				else save[i][l[i]]=')';
				break;
			}
			case'Q':{
//				cout<<save[i]<<'\n';
				int cur=0,res=0;
				fo(j,l[i],r[i]){
					if(save[i][j]==')'){
						if(!cur) ++res;
						else --cur;
					}else ++cur;
				}
				cout<<res+cur<<'\n';
				break;
			}
		}
	}
}
inline void push(int pa,int chi){
	t[chi]+=lz[pa];
	lz[chi]+=lz[pa];
}
void update(int l,int r,int id,int u,int v,int w){
	if(l>v||r<u) return;
	if(l>=u&&r<=v){
		t[id]+=w;
		lz[id]+=w;
		return;
	}
	push(id,id<<1);
	push(id,(id<<1)+1);
	lz[id]=0;
	update(l,l+r>>1,id<<1,u,v,w);
	update((l+r>>1)+1,r,(id<<1)+1,u,v,w);
	t[id]=min(t[id<<1],t[(id<<1)+1]);
}
int get(int l,int r,int id,int u,int v){
	if(l>v||r<u) return 2e9;
	if(l>=u&&r<=v){
		return t[id];
	}
	push(id,id<<1);
	push(id,(id<<1)+1);
	lz[id]=0;
	return min(get(l,l+r>>1,id<<1,u,v),get((l+r>>1)+1,r,(id<<1)+1,u,v));
}
void Sub2(){
	fo(i,1,n){
		if(s[i]==')') update(1,n,1,i,n,-1);
		else update(1,n,1,i,n,1);
	}
	fo(i,1,m){
		switch(ty[i]){
			case'C':{
				if(s[l[i]]==')'){
					s[l[i]]='(';
					update(1,n,1,l[i],n,2);
				}
				else{
					s[l[i]]=')';
					update(1,n,1,l[i],n,-2);
				}
//				fo(i,1,n) cout<<get(1,n,1,i,i)<<' ';
//				cout<<'\n';
				break;
			}
			case'Q':{
				int tmp=get(1,n,1,l[i],r[i]);
				int ll=(l[i]!=1?get(1,n,1,l[i]-1,l[i]-1):0);
				int rr=get(1,n,1,r[i],r[i]);
				tmp-=ll;
				rr-=ll;
				if(tmp<0) rr-=tmp+tmp;
				cout<<rr<<'\n';
				break;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(NULL);
	cin. tie(NULL); cout. tie(NULL);
	freopen("Fixstr.inp" , "r", stdin);
	freopen("Fixstr.out", "w", stdout);
	cin>>s;cin>>m;n=s.size();
	s='?'+s;
	fo(i,1,m){
		cin>>ty[i];
		switch(ty[i]){
			case'U':{
				cin>>l[i];
				haveU=1;
				break;
			}
			case'C':{
				cin>>l[i];
				break;
			}
			case'Q':{
				cin>>l[i]>>r[i];
				break;
			}
		}
	}
	if(n<=1000&&m<=1000){
		Sub1();
		return 0;
	}
	if(!haveU){
		Sub2();
		return 0;
	}
	return 0;
}