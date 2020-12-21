    #include<bits/stdc++.h>
    using namespace std;
    #define fi first
    #define se second
    typedef long long LL;
    const int MAXN=1+3e5;
    const int inf=1+1e9;
    const LL mod=998244353;
    int t;
    LL n,a[MAXN],sum;
    LL d[MAXN],id[MAXN],d1[MAXN];
    vector<LL> f;
    void add (int value, long long &ret)
    {
        vector < int > p;
        while (value)
        {
            int t = value % 10;
            p.push_back(t);
            value /= 10;
        }
        reverse(p.begin(), p.end());
        for (auto x : p) ret = ret * 10 + 1ll * x;
    }

    void sol1()
    {
        for (int i = 1; i <= n; i++) id[i] = i;

        int ans = 0;

        do
        {
            long long value = 0;
            for (int i = 1; i <= n; i++) add(a[id[i]], value);

            if (value % 11 == 0) ans++;
        }
        while (next_permutation (id+1, id + n +1));

        cout << ans << '\n';
    }
    LL ptich(LL x,LL i)
    {

        LL cnt=0,cnt1=0,cnt2=0;
        while(x!=0)
        {
            LL res=x%10;
            ++cnt;
            if(cnt%2==1) cnt2+=res;
            else cnt1+=res;
            x/=10;
        }
        d[i]=cnt1-cnt2;
        d1[i]=cnt2-cnt1;
        return cnt;
    }
    void sol2()
    {
        LL sum=0;
        for(int i=1; i<=n; ++i)
        {
            sum+=d[i];
        }
        if(sum%11==0)
        {
            LL cur=1;
            for(LL i=1; i<=n; ++i)
            {
                cur*=i;
                cur%=mod;
            }
            cout<<cur<<'\n';
        }
        else cout<<0<<'\n';
    }
    LL gth[MAXN];
    void precal()
    {
        gth[0]=1;
        for(LL i=1; i<=2000; ++i)
        {
            gth[i]=gth[i-1]*i;
            gth[i]%=mod;
        }
    }
    LL dp[11][2001][2001];
    void sol3(){
        memset(dp,0,sizeof dp);
        dp[0][0][0]=1;
        for(int i=1;i<=n;++i)
        {
            for(int j=0;j<=10;++j){
                for(int k=0;k<=i;++k){
                    int x=(d[i]+11)%11,x1=(d1[i]+11)%11;
                    if(i-k>=1){
                    dp[(x+j+11)%11][k][i-k]+=dp[j][k][i-k-1];
                    dp[(x+j+11)%11][k][i-k]%=mod;
                    }
                    if(k>=1){
                    dp[(x1+j+11)%11][k][i-k]+=dp[j][k-1][i-k];
                    dp[(x1+j+11)%11][k][i-k]%=mod;
                    }
                }
            }
        }
        if(n%2==0) cout<<(dp[0][n/2][n/2]*gth[n/2])%mod*gth[n/2]%mod<<'\n';
        else cout<<(dp[0][n/2][n/2+1]*gth[n/2+1]%mod)*gth[n/2]%mod<<'\n';
    }
    int main()
    {
    #define TASK "GIFT11"
        if(fopen(TASK ".inp","r"))
        {
            freopen(TASK ".inp","r",stdin);
            freopen(TASK ".out","w",stdout);
        }
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>t;
        precal();
        while(t--)
        {
            cin>>n;
            int kt=1;
            for(int i=1; i<=n; ++i)
            {
                cin>>a[i];
                if(ptich(a[i],i)%2!=0) kt=0;
            }
            if(n<=9)
            {
                sol1();
                continue;
            }
            if(kt==1)
            {
                sol2();
                continue;
            }
            sol3();

        }

        return 0;
    }
