#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m , k;
string a ;

int res = 0;
int tmp ;
int dau , cuoi;

void sub1(){
    tmp = 0;
    for(int i=0 ;  i<n; i++){
        if(a[i] == '1') tmp ++;
        else {
            if( res < tmp ) {
                cuoi = i ;
                dau = i + 1 - tmp ;
                res = tmp;
            }
            tmp = 0;
        }
    }
    cout<<dau<<" "<<cuoi;
}


void sub2(){
    for(int i=0; i<=n; i++){
        //if(  )
        tmp = 0;
        int tmpp = k;
        for(int j=i ; j<= n; j++) {
            if( a[j] ==  0 ){
                if( tmpp == 0 )  break;
                tmpp--;
            }
            tmp ++;
        }
        if( res < tmp ) {
                cuoi = i + tmp - 1 ;
                dau =  i + 1 ;
                res = tmp;
        }
    }
    cout<<dau<<" "<<cuoi;
}

int main()
{
    //cout << "Hello world!" << endl;
    freopen("decor.inp","r",stdin); freopen("decor.out","w",stdout);

    cin>>n>>m>>k;
   // for(int i = 1; i<=n; i++)
        cin>>a;
    a = a+ '0' ;//a[n] = 0;
    cout<<a<<"\n";
    if( m==0 && k ==0 ) sub1();
    else if( m==0 ) sub2();
    return 0;
}
