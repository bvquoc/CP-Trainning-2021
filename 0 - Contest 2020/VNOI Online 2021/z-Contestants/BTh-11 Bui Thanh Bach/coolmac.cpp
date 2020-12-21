#include <iostream>
#include <bits/stdc++.h>
#define ft first
#define sc second
using namespace std;

int n, m;
pair<int,int> p[100003];
int kmin = 100000;
vector<int> vtri;

void cb(){

    //sort(vtri.begin(), vtri.end(), cmp);

    for(int i= 1 ; i < vtri.size() ; i++){
        for(int j= i + 1 ; j < vtri.size() ; j++){
        if( p[vtri[i]].ft >= p[vtri[j]].ft && p[vtri[j]].sc >= p[vtri[i]].sc  ) {
            vtri.erase( vtri.begin()+ i, vtri.begin() + i+ 1);
            //return 1;
        }

        else if(p[vtri[j]].ft >= p[vtri[i]].ft && p[vtri[i]].sc >= p[vtri[j]].sc )
            {
            vtri.erase( vtri.begin()+ j, vtri.begin() + j+ 1);
            //return 1;
        }
        //return ( p[j].sc < p[i].sc) ;
        }

    }
     for(int i= 1 ; i < vtri.size() -1; i++){
        for(int j= i + 1 ; j < vtri.size() ; j++){
            if( p[vtri[j]].sc < p[vtri[i]].sc  ) swap (vtri[i],vtri[j]);
        }
    }



    //for(int i= 1; i<vtri.size() ; i++) cout<< vtri[i]<<" ";
    //reverse(vtri.begin(), vtri.end());

}

void inp(){

    freopen("coolmac.inp","r",stdin);   freopen("coolmac.out","w",stdout);
    cin>>n;
    //cout<<n;
    vtri.push_back(0);
    for(int i=1; i<=n; i++){
           // cout<<"1"<<" ";
        cin>>p[i].ft>>p[i].sc;
        vtri.push_back(i);
        //vtri[i] = i;
    }
    //vtri.erase( vtri.begin()+ 1, vtri.begin() + 2);

    cin>>m;
    while(m--){
        int x;
        cin>>x;
        kmin = min(kmin, x);
    }

}

int chat(int l , int r, int val ){
    while( l < r){
        int mid = ((r+l)/2);
        if( p[vtri[mid] ].sc  >= val  ) r = mid;
        else l = mid + 1;
    }
    return r;
}

int main()
{
    inp();
    cb();
    bool ok = 0;int res = 1;
    int k = vtri.size() - 1;
    int val  = p[vtri[k]].ft  ;
    if(val <=  kmin) ok  = 1;
    if( p[vtri[k]].sc < 100000 ) ok = 0;
    else{

        int now =k  ;
    //cout<<k;

    while( val > kmin){
        if( now == k ) {
            if( p[vtri[now]].sc < 100000 ) break ;
        }
        int tmp = chat( 1, now , val);
        //cout<<tmp<<" ";
        if( tmp == now ) break;
        now = tmp ;
        val = p[vtri[now]].ft;
        if( val <= kmin ) ok = 1;
        res++;
    }
    }

    if(ok == 0) cout<< "-1";
    else cout<< res;
    return 0;
}
