#include <bits/stdc++.h>

using namespace std;

#define maxn 505

string a,b,c;

int dp[maxn][maxn];

void sub1(){

if(a==c || b==c){

printf("TRETRAU");

}
else{

if(a==b){

printf("1\n");

cout << a;

}
else{

string ds=a+b;

printf("2\n");

cout << ds;

}

}
}

void sub3(){

int slc=c.size();

int sla=a.size();

int slb=b.size();

int ca=0;

int cb=0;

for(int i=0;i<sla;++i){

if(a[i]==c[0]) ++ca;

}

for(int i=0;i<slb;++i){

if(b[i]==c[0]) ++cb;

}

int maxcheck=max(ca,cb);

if(maxcheck>=slc){

printf("TRETRAU");

}

else{

int mincheck=min(ca,cb);

int slres=sla+slb-mincheck;

printf("%d\n",slres);

string ds=a+b;

cout << ds;

}

}



int main(){

freopen("XCKLT.inp","r",stdin);
freopen("XCKLT.out","w",stdout);

cin >> a >> b >> c;

int sa=a.size();

int sb=b.size();

int sc=c.size();

if(sa==1 && sb==1 && sc==1){

sub1();

}

else{

int checksub3=1;

for(int i=1;i<sc;++i){

if(c[i]!=c[i-1]) checksub3=0;

}

if(checksub3==1){

sub3();

}

else{

printf("TRETRAU");

}

}
}




