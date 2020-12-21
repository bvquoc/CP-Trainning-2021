 #include<bits/stdc++.h>
 #define int long long
 using namespace std;
 vector<int> a;
 typedef pair<int, int> ii;
 vector<ii> b;
 int n;
int dp[2009][2009][13];
const int MOD=998244353;
ii xuli(int x)
{
    int z=x;
    int tt=0;
    int sl=0;
    int kqq=0;
    while (z>0)
    {
        int u=z%10;
        z=z/10;
        if (tt==0)
        {
            kqq=kqq+u;
            tt=1;
        }
        else
        {
            kqq=kqq-u;
            tt=0;
        }
        sl++;
    }
    ii tmp;
    tmp.first=kqq;
    tmp.second=sl%2;
    return tmp;
}
  main()
 {
     freopen("GIFT11.inp","r",stdin);
    freopen("GIFT11.out","w",stdout);
    int t;
    cin>>t;
    while (t>0)
    {
        cin>>n;
        a.clear();
        b.clear();
        int ok=0;
        int ok1=0;
        for (int i=1;i<=n;i++)
        {
            int u;
            cin>>u;
            a.push_back(u);
            // first la gia tri
            // second le hay chan
            ii tmp=xuli(u);
            b.push_back(ii(tmp.first,tmp.second));
            // 0 la chan
            // 1 la le
            if (tmp.second==0)
            {
                ok1=1;
            }
            else
            {
                ok=1;
            }
        }
        if (ok1==0)
        {
            memset(dp,-1,sizeof(dp));
                dp[0][0][0]=1;
            for (int i=1;i<=n;i++)
            {
                for (int j=0;j<=i;j++)
                {
                    for (int o=0;o<=10;o++)
                    {
                        if (dp[i-1][j-1][o]!=-1) {
                        int o1=(o+b[i-1].first)%11;
                        dp[i][j][o1]=(dp[i][j][o1]+(dp[i-1][j-1][o]*j)%MOD)%MOD;}
                        if (dp[i-1][j][o]!=-1) {
                        int o2=(o-b[i-1].first+11*11)%11;
                        dp[i][j][o2]=(dp[i][j][o2]+(dp[i-1][j][o]*(i-j))%MOD)%MOD;
                        }
                    }
                }
            }
            int res=0;
            for (int j=0;j<=n;j++)
            {
                res=res+dp[n][j][0];
            }
            cout<<res<<endl;
        }
        else
        {
            if (ok==0)
            {
                int res=0;
                for (int i=1;i<=n;i++)
                {
                    res=(res+b[i-1].first)%MOD;
                }
                if (res%11==0)
                {
                    int tmp=1;
                    for (int i=1;i<=n;i++)
                    {
                        tmp=(tmp*i)%MOD;
                    }
                    cout<<tmp<<endl;
                }
                else
                {
                    cout<<0<<endl;
                }
            }
            else
            {

            }
        }
        t--;
    }
    return 0;
 }
