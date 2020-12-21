#include <bits/stdc++.h>

using namespace std;

string a, b, c;

void sub1()
{
    if(a == c || b == c) {printf("TRETRAU"); return;}
    if(a == b) {cout << a; return;}
    else{
        string x = a + b;
        int siz = x.size();

        printf("%d\n", siz);
        cout << x;
    }
}

#define ha "XCKLT"

int main()
{
    //freopen("task.inp","r",stdin);
    freopen(ha".INP","r",stdin);
    freopen(ha".OUT","w",stdout);

    cin >> a;
    cin >> b;
    cin >> c;

    if((int)a.size() == 1 && (int)b.size() == 1 && (int)c.size() == 1) sub1();
    else printf("TRETRAU");
}
