#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    if (c==2) cout<<(b-a)/2;
    else{
        int res=0;
        while (a<b)
        {
            if ((a+2)%c!=0) {res++;a+=2;}
            else if ((a+1)%c!=0)
            {
                res++;
                a++;
            }
           // cout<<a<<endl;
        }
        cout<<res;
    }
}
