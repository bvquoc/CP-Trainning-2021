#include<bits/stdc++.h>
#define file "COOLMAC"
#define oo 99999999
using namespace std;
int n,m;
pair<int,int> a[100003];
int ttl[100003];
bool ktt[100003];
int minn=oo;
int dem=0;
bool tmpp(pair<int,int> aa, pair<int,int> bb)
{
    if (aa.first < bb.first)
        return 1;
    if (aa.first == bb.first && aa.second > bb.second)
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(file".INP","r",stdin);
    freopen(file".OUT","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i].first >> a[i].second;

    cin>>m;
    for (int i=1; i<=m; i++)
    {
        int tmp;
        cin>>tmp;
        minn=min(minn,tmp);
    }

    sort(a+1,a+n+1,tmpp);
    stack<pair<int,int>> st;

    for (int i=1; i<=n; i++)
    {
        if (a[i].second<=minn)
            continue;
        if (st.size() && st.top().second >= a[i].second)
            continue;
        while (st.size() && st.top().first<=minn && a[i].first<=minn && a[i].second>st.top().second)
        {
            dem--;
            st.pop();
        }
        if (st.size()>=2)
        {
            pair<int,int> tmp=st.top();
            dem--;
            st.pop();
            if (st.top().second<a[i].first)
            {
                st.push(tmp);
                dem++;
            }

        }
        dem++;
        st.push(a[i]);
    }
    while (st.size())
    {
        ktt[st.top().first]=1;
        ttl[st.top().first]+=1;
        ttl[st.top().second+1]-=1;
        st.pop();
    }
    for (int i=1; i<=100000; i++)
        ttl[i]+=ttl[i-1];

    if (ttl[minn]==0)
    {
        cout<<-1;
        return 0;
    }

    for (int i=max(1,minn+1); i<=100000; i++)
    {
        if (ttl[i]==0  || (ktt[i]==1 && ttl[i]==1))
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<dem;
    return 0;

}
