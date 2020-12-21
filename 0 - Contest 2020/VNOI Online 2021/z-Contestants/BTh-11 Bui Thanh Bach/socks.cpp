#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n,q;
bool a[500005];
vector<int> ke[500005];
int node ;
void inp(){
    freopen("socks.inp","r",stdin);
    freopen("socks.out","w",stdout);
    cin>>n>>q;
    for(int i=1; i<= n ; i++) cin>>a[i];
    for(int i=1; i< n ; i++) {
        int x, y;
        cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

void bd(){

    int i =node ;
    int d  = 0;
    int beg = -1 , en ;
    int res = 0;
    int la = 0;
    //cout<<node;
    int kk = n;
    while( kk-- ){
            //cout<<i<<" ";
            //cout<<i<<" ";
        if(a[i]==1){

            if (beg == -1) beg = i ;
        else la++;
            res +=  la;

            en = i;
            la = 0;
            //cout<<i<<" ";
        }
        else if( beg != -1  ) la ++;
        int tmp = ke[i][0];
        //i = ke[i][0];
        if( tmp == d ){
            d= i;
            i = ke[i][1];

        }
        else {

            d= i;
            i = tmp ;
        }
    }
    cout<<res<<"\n";


}

int main()
{
    inp();
    for(int i=1; i<=n; i++) if( ke[i].size() ==1 ) node = i;
    bd();
    while(q--)
    {

        int kkk;
        cin>>kkk;
        a[kkk] = (a[kkk]+ 1)%2;
        int i =node ;
        int d  = 0;
        int beg = -1 , en ;
            int res = 0;
        int la = 0;
        int kk = n;
        while( kk-- ){
                if(a[i]==1){
                    if (beg == -1) beg = i ;
                    else la++;
                    res +=  la;
                    en = i;
                    la = 0;
                }
                else if( beg != -1  ) la ++;
                int tmp = ke[i][0];
                //i = ke[i][0];
                if( tmp == d ){
                    d= i;
                    i = ke[i][1];

                }
                else {

                    d= i;
                    i = tmp ;
                }
    }
    cout<<res<<"\n";
    }

    return 0;
}
