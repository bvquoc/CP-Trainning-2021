#include <bits/stdc++.h>

using namespace std;
int n,a[2005],MOD=998244353,sum_odd_for_subtask2=0,sum_even_for_subtask2=0;
int sum_odd_for_subtask3=0,sum_even_for_subtask3=0,res_tmp=0,even=0;
map<string,int> r;
struct node
{
    string val; int sum_odd,sum_even;
}f[2005];
int check_subtask_func(string s)
{
    if(s.length()%2==0) return 1;
    if(s.length()%2==1) return 2;
}
int sum_nature_string(string s, int kind)
{
    // kind = 0 lẻ kind = 1 chẳn
    int sum=0;
    for(int i=kind; i<s.length(); i+=2)
        sum+=int(s[i]-48);
    return sum;
}
bool cal_sum()
{

    int sum_odd_tmp=0,sum_even_tmp=0;

    for(int i=1; i<=n; i++)
           {
            sum_odd_tmp+=sum_nature_string(f[i].val,(i%2==0));
            sum_even_tmp+=sum_nature_string(f[i].val,(i%2==1));
           }
    return (abs(sum_odd_tmp-sum_even_tmp)%11==0);

}
void swap_sub(int start,int notify)
{
    if(start>n-1-even) return;

           if(notify==1){
        swap(f[start].val,f[start-1].val);
           if(cal_sum())
            { res_tmp++; string s="";
            for(int i=1; i<=n; i++) { cout<<f[i].val; s+=f[i].val; }
            r[s]+=1; cout<<endl;  }
           if(even==1)
             {
              swap(f[n].val,f[n-1].val);
              if(cal_sum())
                { res_tmp++; string s="";
                 for(int i=1; i<=n; i++) { cout<<f[i].val; s+=f[i].val; }
                 r[s]+=1; cout<<endl;  }
              swap(f[n].val,f[n-1].val);
             }
           swap_sub(start+2,1);
           swap(f[start].val,f[start-1].val);
           }
           swap(f[start].val,f[start+1].val);
           if(cal_sum())
          { res_tmp++; string s="";
            for(int i=1; i<=n; i++) { cout<<f[i].val; s+=f[i].val; }
            r[s]+=1; cout<<endl;  }
           swap_sub(start+2,2);
           swap(f[start].val,f[start+1].val);

       return;
}
void subtask_1()
{
    for(int i=1; i<=n; i++)
    { cin>>f[i].val; a[i]=i;
      f[i].sum_odd=sum_nature_string(f[i].val,0);
      f[i].sum_even=sum_nature_string(f[i].val,1);
    }
    map<string,int>  r; int res=0;
   do{
        int res_odd=f[a[1]].sum_odd,res_even=f[a[1]].sum_even,length_sub=f[a[1]].val.length();
        for(int i=2; i<=n; i++)
        {
          if(length_sub%2==0)
          {
              res_odd+=f[a[i]].sum_odd;
              res_even+=f[a[i]].sum_even;
          } else
          {
              res_odd+=f[a[i]].sum_even;
              res_even+=f[a[i]].sum_odd;
          }
        length_sub+=f[a[i]].val.length();
        }
        if(abs(res_odd-res_even)%11==0)
            res++; res%=MOD;

    } while(next_permutation(a+1,a+1+n));
    cout<<res<<endl;
 return;
}
void subtask_2()
{
    if(abs(sum_odd_for_subtask2-sum_even_for_subtask2)%11!=0)
        cout<<0<<endl; else
    {
        int res=1;
      for(int i=2; i<=n; i++)
        res=(res*i)%MOD;
       cout<<res<<endl;
    }
       return;
}

void subtask_3()
{
    int sum=0;
    for(int i=1; i<=n; i++)
          cin>>f[i].val;
        even=0;
          if(n%2==0) even=1;
          for(int i=2; i<=n-1-even; i++)
           swap_sub(i,1);
     // n is even res_tmp*(n/2)!*(n/2)!
      //n is odd res_tmp*(n/2+1)!*(n/2)!
       cout<<res_tmp<<endl;
       cout<<r.size()<<endl;
     int res=1;
      for(int i=2; i<=n/2; i++)
        res=(res*i)%MOD; res=(res*res)%MOD; res=(res*res_tmp)%MOD;
        if(n%2==1) res=(res*(n/2+1))%MOD;
        cout<<res<<endl;
    return;
}

void subtask_4()
{
    cout<<"came to subtask 4"<<endl;
    return;
}
int main()
{
    freopen("GIFT1.INP","r",stdin);
    freopen("GIFT1.OUT","w",stdout);
    int T; cin>>T;
    while(T--)
    {
         cin>>n;
         if(n<=8) subtask_1(); else
         {
             int check_subtask=0;
         for(int i=1; i<=n; i++)
         {
            cin>>f[i].val;
            check_subtask+=check_subtask_func(f[i].val);
            f[i].sum_odd=sum_nature_string(f[i].val,0);
            f[i].sum_even=sum_nature_string(f[i].val,1);
            sum_odd_for_subtask2+=f[i].sum_odd;
            sum_even_for_subtask2+=f[i].sum_even;
         }
         if(check_subtask==n)   subtask_2(); else
         if(check_subtask==2*n) subtask_1(); else
                                subtask_1();
         }
    }
    return 0;
}
