#include <bits/stdc++.h>
#define nmax 1000000
using namespace std;
struct query
{
    int t;
    char x,y;
}qr[nmax+10];
int n,lab[nmax+10],icon[30],color[nmax+10];
char s[nmax+10];
void in()
{
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>qr[i].t;
      if(qr[i].t==1) cin>>qr[i].x;
      else cin>>qr[i].x>>qr[i].y;
    }
}
void sub1()
{
    int cnt=0;
    for(int z=0;z<n;z++){
      if(qr[z].t==1)
        s[cnt++]=qr[z].x;
      else
        for(int i=0;i<cnt;i++)
          if(s[i]==qr[z].x) s[i]=qr[z].y;
    }
    for(int i=0;i<cnt;i++)
      cout<<s[i];
}
int groot(int u)
{
    return (lab[u]==u)?u:(lab[u]=groot(lab[u]));
}
void sub2()
{
    int cnt=0;
    for(int i=0;i<26;i++) icon[i]=-1;
    for(int i=0;i<n;i++){
      if(qr[i].t==1){
        if(icon[qr[i].x-'a']==-1){
          icon[qr[i].x-'a']=cnt;
          lab[cnt]=cnt;
          color[cnt++]=qr[i].x-'a';
        }
        else
          lab[cnt++]=icon[qr[i].x-'a'];
      }
      else if(qr[i].x!=qr[i].y){
          lab[icon[qr[i].x-'a']]=icon[qr[i].y-'a'];
          icon[qr[i].x-'a']=-1;
      }
    }
    for(int i=0;i<cnt;i++)
      cout<<char(color[groot(i)]+'a');
}
void run()
{
    in();
    if(n<=10000) sub1();else
    sub2();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("Paint.inp","r",stdin);
    freopen("Paint.out","w",stdout);
    run();
    return 0;
}
