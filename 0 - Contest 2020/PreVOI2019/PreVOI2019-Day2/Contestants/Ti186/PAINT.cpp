#include <bits/stdc++.h>

using namespace std;
const int nmax=1e6+5;
int top=0,n,id;
char a[nmax],x,y;
int main()
{
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int _=1;_<=n;_++){
        cin>>id;
        if(id-1){
            cin>>x>>y;
            for(int i=1;i<=top;i++){
                if(a[i]==x) a[i]=y;
            }
        } else {
            cin>>x;
            a[++top]=x;
        }
    }
    for(int i=1;i<=top;i++){
        cout<<a[i];
    }
//    cout<<1000000<<endl;
//    for(int i=1;i<=1000000;i++){
//        int tmp=rand()%2+1;
//        cout<<tmp<<" ";
//        if(tmp-1){
//
//            int Tmp=rand()%26;
//            cout<<char(Tmp+'a')<<" ";
//            Tmp=rand()%26;
//            cout<<char(Tmp+'a')<<endl;
//        } else {
//            int Tmp=rand()%26;
//            cout<<char(Tmp+'a')<<endl;
//
//        }
//    }
}
