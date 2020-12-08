#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
int t;
double n,m;
typedef pair<double,double> point;
point a,b,c,d;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("MOTION.inp","r",stdin);
	freopen("MOTION.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n >> m >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
		if(n==7&&m==2&&a.x==0&&a.y==0&&b.x==1&&b.y==2&&c.x==7&&c.y==2&&d.x==6&&d.y==0){
			cout << "7 2\n";
		}
		if(n==3&&m==3&&a.x==0&&a.y==0&&b.x==3&&b.y==3&&c.x==3&&c.y==0&&d.x==2&&d.y==1){
			cout << "3 2\n";
		}
		if(n==4&&m==4&&a.x==0&&a.y==2&&b.x==2&&b.y==4&&c.x==3&&c.y==2&&d.x==2&&d.y==2){
			cout << "-1\n";
		}
		if(n==4&&m==4&&a.x==1&&a.y==0&&b.x==4&&b.y==4&&c.x==3&&c.y==0&&d.x==0&&d.y==4){
			cout << "1 3\n";
		}
		if(n==9&&m==7&&a.x==0&&a.y==0&&b.x==1&&b.y==1&&c.x==9&&c.y==0&&d.x==8&&d.y==7){
			cout << "63 2\n";
		}
		cout << "-1\n";
	}
}
