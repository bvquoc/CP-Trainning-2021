#include <bits/stdc++.h>
using namespace std;
struct data
{
    int form ;
    char x , y ;
};
data a[1000001];
int n,X,Y;
int cha[30];
int find_cha(int u)
{
    if (cha[u]  < 0) return u;
    return cha[u] = find_cha( cha[u] );
}
stack < char > st;
int main()
{
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].form ;
        cin>>a[i].x;
        if ( a[i].form == 2) cin>>a[i].y;
    }
    for (int i=0;i<=26;i++) cha[i] = -1;

    for (int i=n;i>=1;i--)
    {
        if ( a[i].form == 1 )
        {
            X = find_cha( a[i].x - 'a' );
            st.push( X+'a' );
        }
        if ( a[i].form == 2 )
        {
            if ( a[i].x == a[i].y ) continue ;
           X =  find_cha (a[i].x - 'a' );
           Y =  find_cha (a[i].y - 'a' );
           if (X == Y) continue ;
           if ( X==Y && X == a[i].x && cha[X] < -1 ) continue ;
           cha[Y]+=cha[X];
           cha[X] = Y;
        }
    }

    while (!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    return 0;
}
