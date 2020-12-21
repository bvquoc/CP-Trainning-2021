#include <bits/stdc++.h>
using namespace std;

int n,q,num_col,sl=0,anc;

vector <int> mp[500002];
vector <int> par(500002);
vector <int> bac(500002,0);
vector <bool> col(500002,0);
vector <bool> pass (500002,0);
set <int> coled;
set <int> :: iterator it_coled;

void dfs (int u)
{
    int i,v;
    queue <int> s;
    vector <bool> vit (n,0);
    s.push(u);
    vit[u]=1;
    par[u]=0;
    while (!s.empty())
    {
        u=s.front();
        s.pop();
        for (i=0; i<mp[u].size(); i++)
        {
            v=mp[u][i];
            if (vit[v]==0)
            {
                vit[v]=1;
                s.push(v);
                par[v]=u;
            }
        }
    }
}

void add (int u, int pre)
{
    int i,v;
    if (pass[u]==0)
    {
        pass[u]=1;
        if (u!=anc) add(par[u],u);
    }
    else if (pass[u]==1)
    {
        for (i=0; i<mp[u].size(); i++)
        {
            v=mp[u][i];
            if (pass[v]==1 && v!=pre && v!=par[u]) break;
        }
        if (i==mp[u].size()) sl--;
    }
}

void del (int u)
{
    int i,v;
    if (col[u]==1)
    {
        for (i=0; i<mp[u].size(); i++)
        {
            v=mp[u][i];
            if (pass[v]==1 && v!=par[u]) break;
        }
        if (i!=mp[u].size()) sl--;

    }
    else
    {
        for (i=0; i<mp[u].size(); i++)
        {
            v=mp[u][i];
            if (pass[v]==1 && v!=par[u]) break;
        }
        if (i==mp[u].size())
        {
            pass[u]=0;
            del(par[u]);
        }
        else sl--;
    }
}

void cout_ans()
{
    //cout<<sl<<" ";
    cout<< ((num_col>1)? (sl+1)/2 : 0) <<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("SOCKS.INP","r",stdin);
    freopen("SOCKS.OUT","w",stdout);

    bool check;
    int i,u,v;
    cin>>n>>q;
    for (i=1; i<=n; i++)
    {
        cin>>check;
        if (check==1)
        {
            num_col++;
            coled.insert(i);
            col[i]=1;
        }
    }

    for (i=2; i<=n; i++)
    {
        cin>>u>>v;
        bac[u]++;
        bac[v]++;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    ///cout<<"\n";

    anc=max_element(bac.begin(),bac.end())-bac.begin();

    dfs(anc);

    //cout<<"anc:"<<anc<<"\n";

    for (it_coled=coled.begin(); it_coled!=coled.end(); it_coled++)
    {
        u=*it_coled;
        if (pass[u]==0)
        {
            sl++;
            pass[u]=1;
            if (u!=anc) add(par[u],u);
        }
    }
    cout_ans();
    ///cout<<"\n";

    for (int k=0; k<q; k++)
    {
        cin>>u;
        it_coled=coled.find(u);
        if (it_coled==coled.end())
        {
            num_col++;
            coled.insert(u);
            col[i]=1;
            if (pass[u]==0)
            {
                sl++;
                pass[u]=1;
                if (u!=anc) add(par[u],u);
            }
            cout_ans();

        }
        else
        {
            coled.erase(u);
            num_col--;
            col[i]=0;
            if (u!=anc)
            {
                for (i=0; i<mp[u].size(); i++)
                {
                    v=mp[u][i];
                    if (pass[v]==1 && v!=par[u]) break;
                }
                if (i==mp[u].size())
                {
                    pass[u]=0;
                    del(par[u]);
                }
            }
            cout_ans();
        }
        /*
        for (i=1; i<=n; i++)
            cout<<pass[i]<<" ";
        cout<<"\n";
        for (it_coled=coled.begin(); it_coled!=coled.end(); it_coled++)
            cout<<*it_coled<<" ";
        cout<<"\n";
        */
    }
}
