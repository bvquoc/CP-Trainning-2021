    #include <bits/stdc++.h>
    #define maxn 1000001
    using namespace std;
    int sl=0;
    int n;
    char ans[maxn];
    vector <int > mau[27];
    void sub1()
    {
        for (int i=1;i<=n;++i)
        {
            int key;
            char a,b;
            cin>>key;
            if (key==1)
            {
                ++sl;
                cin>>a;
                ans[sl]=a;
                mau[a-'a'].push_back(sl);
            }
            else
            {
                cin>>a>>b;
                for(int v:mau[a-'a'])
                {
                    mau[b-'a'].push_back(v);
                    ans[v]=b;
                }
                mau[a-'a'].clear();
            }
        }
            for (int i=1;i<=sl;++i) cout<<ans[i];
    }
    int main()
    {
        freopen("paint.inp","r",stdin);
        freopen("paint.out","w",stdout);
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        sub1();
    }
