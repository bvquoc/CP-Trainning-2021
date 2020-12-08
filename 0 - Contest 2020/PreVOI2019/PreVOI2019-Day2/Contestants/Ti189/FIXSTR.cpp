#include<bits/stdc++.h>
#define up(i,d,c) for(int i=d;i<=c;i++)


using namespace std;
int n,m;
string s,st;
string str[1000];
struct
{
    int lo[4000005];
    int hi[4000005];
    int sum[4000005];
    int leaf[4000005];
    void build(int i,int l,int r)
    {
        lo[i]=l;
        hi[i]=r;
        if(l==r)
        {
            leaf[l]=i;
            sum[i]=0;
        }
        else
        {
            int mi=(l+r)/2;
            build(i*2,l,mi);
            build(i*2+1,mi+1,r);
            sum[i]=sum[i*2]+sum[i*2+1];
        }
    }
        void upd(int i,int k)
        {
            int x=leaf[i];
            sum[x]=k;
            for(x/=2;x;x/=2)
            sum[x]=sum[x*2]+sum[x*2+1];
        }
        int qi,qj;
       int req(int i)
       {
           if(lo[i]>qj||qi>hi[i])return 0;
           if(qi<=lo[i]&&hi[i]<=qj)return sum[i];
           return req(i*2)+req(i*2+1);
       }
       int quest(int l,int r)
       {
           if(l>r)return 0;
            qi=l;qj=r;
            return req(1);
       }

} T;
int main()
{
	#define NAME "FIXSTR"
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen(NAME".inp","r",stdin);
	freopen(NAME".out","w",stdout);

   cin>>s;

   s=" "+s;
   st=s;

   cin>>m;
if(m<=1000&&s.size()<=1010)
 {

  up(i,1,m)
   {

       char type;
       cin>>type;
       if(type=='C')
       {
           int x;
           cin>>x;
        st=s;
        if(s[x]=='(')
            s[x]=')';
        else s[x]='(';
       }
       if(type=='Q')
       {
           int l,r;
           cin>>l>>r;

           int k=0;
           int res=0;
           up(j,l,r)
           {
               if(s[j]==')')
               {
                   if(k==0) res++;
                   else k--;
               }
               else
                k++;
           }
           res+=k;
           cout<<res<<'\n';
       }
       if(type=='U')
       {
           int k;
           cin>>k;
           st=s;
           s=str[k];
       } str[i]=st;
       //cout<<st<<" "<<s<<'\n';

   }    return 0;
}
   T.build(1,1,s.size());
   up(i,1,s.size())
   {
       if(s[i]=='(')T.upd(i,1);
       else T.upd(i,-1);
   }
while(m--)
{
    char type;
    cin>>type;
    if(type=='C')
    {
        int x;
        cin>>x;
        if(s[x]=='(')
        {
            s[x]=')';
            T.upd(x,-1);
        }
        else
        {
            s[x]='(';
            T.upd(x,1);
        }
    }
    if(type=='Q')
    {
        int l,r;
        int i,j;
        int res=0;
        cin>>l>>r;
        i=l;j=r;
        while(i<=r&&s[i]==')')
        {
            i++;res++;
        }

        while(j>=l&&s[j]=='(')
        {
            j--;res++;
        }
      //  cout<<s<<" ";
        res+=abs(T.quest(i,j));
        cout<<res<<'\n';
    }
    if(type=='U')
    {
        int k;
        cin>>k;
        continue;
    }
}


}
