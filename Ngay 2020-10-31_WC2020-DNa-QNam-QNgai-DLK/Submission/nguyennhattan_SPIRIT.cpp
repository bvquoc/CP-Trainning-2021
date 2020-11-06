#include <bits/stdc++.h>

using namespace std;

long long a,b,c,first,last;
/*
void sub12()
{
    int i=a;
    while (i!=b)
    {
        if ((i+2)%c!=0 && i+1!=b) i+=2;
            else i+=1;
        dem++;
    }
    cout<<dem;
}

void sub3()
{
    cout<<(b-a)/2;
}
*/
int mod(int x, int y)
{
    if (x % y==0) return 0;
        else return 1;
}

int main()
{
    cin>>a>>b>>c;
    /*for (int i=a; i<=b; i++)
    {
        if (i % c==0)
        {
            first=i;
            break;
        }
    }
    for (int i=b; i>=a; i--)
    {
        if (i % c==0)
        {
            last=i;
            break;
        }
    }*/
    first=((a/c)+1)*c;
    last=(b/c)*c;
    int res=0;
    {
//        cout<<first<<' '<<last<<endl;
 /*   if (first-a>1) */res+=((first-a)/2)+1;
    res+=((b-last)/2)+1;
    res+=((last-first)/c)*((c/2)+(mod(c,2)))-1;
    cout<<res;
    }
    /*   if (b<=100000) sub12();
        else if (c==2) sub3();*/
  /*  if (c<a || c>b) cout<<(((b-a) / 2)+((b-a) % 2));
        else
        {
            res=res+((c-a)/2+1);
            res=res+(((b-c-1)/2)+((b-c-1)%2));
            cout<<res;
        }*/
}
