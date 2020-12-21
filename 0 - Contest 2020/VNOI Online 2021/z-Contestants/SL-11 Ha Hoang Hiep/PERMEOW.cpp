#include<bits/stdc++.h>
using namespace std;
#define job "PERMEOW"
int n,a[200000],b[200000],c[200000];
int ans=0;
void enter(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
}
void Sort(int a[])
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]),ans++;
}
bool check(){
    bool flag=0;
    for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
                flag=1;
        }
    return flag;
}
void solve(){

    if(!check()){
        Sort(a);
        cout<<ans;
    }
    else{
        do{
            memcpy(c,a,sizeof a);
            Sort(c);
            if(!check()) break;
        }while(next_permutation(a,a+n) );
        cout<<ans;
    }
}
int main()
{
    freopen(job".inp","r",stdin);
    freopen(job".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    enter();
    solve();
}
