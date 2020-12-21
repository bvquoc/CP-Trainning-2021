#include <bits/stdc++.h>

using namespace std;
int m,n,res=0; vector<int> L,R; vector<int>::iterator it,low;
struct node
{
    int left, right;
}f[90000];
bool comp(node x, node y)
{
    return x.left<y.left;
}

int main()
{
     freopen("COOLMAC.INP","r",stdin);
     freopen("COOLMAC.OUT","w",stdout);
     cin>>m;
       for(int i=1; i<=m; i++) cin>>f[i].left>>f[i].right;
      int mini;
     cin>>n>>mini;
       for(int i=2; i<=n; i++) { int tmp; cin>>tmp; mini=min(mini,tmp); }

    sort(f+1,f+1+m,comp);
     L.push_back(0);  R.push_back(0);
      for(int i=1; i<=m; i++)
      {
        L.push_back(f[i].left); R.push_back(f[i].right);
      }
        int sub_left=1;

      for(;;)
      {
        low=upper_bound(L.begin()+sub_left,L.end(), mini);
        if(low==L.begin()+sub_left) { cout<<-1<<endl; return 0; }
        int sub_right=low-L.begin();
        it=max_element(R.begin()+sub_left,R.begin()+sub_right);
       mini=*it; sub_left=it-R.begin()+1;
       res++;
        if(mini==100000) { cout<<res<<endl; return 0; }
      }
return 0;
}

