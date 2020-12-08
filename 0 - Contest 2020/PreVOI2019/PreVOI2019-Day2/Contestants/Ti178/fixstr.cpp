#include<bits/stdc++.h>
using namespace std;
map<string,int> dp;
string a[1000005];
char H[1000005];
bool check(string st)
{
   
        int sta=0;
   
          for(int i=0; i<st.size();i++)
              
               {
                        if(st[i]=='{'||st[i]=='(')
                              {
                                   sta++;
                                   H[sta]=st[i];
                                   continue;
                              }

                     if(st[i]=='}'||st[i]==')')
                                {

                                        if (((st[i]=='}'&&H[sta]=='('))||((st[i]==')'&&H[sta]=='{')) || (sta<=0)) return false;
                                     
                                       sta--;
                              }
               }
        if (sta>0) return false;
       
       return true;


}
int cal(string st)
{
     if(st=="") return 0;
 //     cout << st << endl;
     if(st=="("||st==")"||st=="{"||st =="}") return 1;
     if(st=="()"||st=="{}") return 0;
     int val = dp[st];
     if(val==-1) val++;
     else if(val==0) val--;
     if(val>=0) return val;
       if(check(st))
     {
         // return 0 ;
          dp[st] = -1;
          return 0;
     }
     int ans = 1e9+7 ;
     for(int i=0;i<st.size()-1;i++)
     {

        // cout << st << ' ' << "=" << st.substr(0,i+1) << " + " <<  st.substr(i+1,(st.size()-1)-(i+1)+1) << ' ' << cal(st.substr(0,i+1)) << ' ' << cal(st.substr(i+1,(st.size()-1)-(i+1)+1)) << endl;
                ans = min(cal(st.substr(0,i+1))+cal(st.substr(i+1,(st.size()-1)-(i+1)+1)),ans );
               // else    ans = min((cal(st.substr(0,j+1))),ans );
              //  cout << st.substr(0,j+1) << ' ' <<cal(st.substr(0,j+1)) << endl;
               //  cout <<  st.substr(j+1,i-(j+1)) << ' ' << cal(st.substr(j+1,i-(j+1))) << endl;

     }
     if(ans==0) ans--;
     dp[st] = ans;

     return ans;
}
void solve()
{
     string st;
     cin >> st;
     a[1] = st;
     int n;
     cin >> n;
     for(int i=1;i<=n;i++)
     {
          char type;
          cin >> type;
          if(type=='C')
          {
               int k ;
               cin >> k;
                if(st[k-1]=='(') st[k-1] = ')';
               else if(st[k-1]==')') st[k-1] = '(';
          }
          else if(type=='Q')
          {
               int l,r ;
               cin >> l >> r;
               cout << cal(st.substr(l-1,(r-1)-(l-1)+1)) << endl;
          }
          else
          {
               int k;
               cin >> k;
               st = a[k];
          }
         // cout << st << endl;;
          a[i+1] = st;
     }
}
int main()
{
     freopen("fixstr.inp","r",stdin);
     freopen("fixstr.out","w",stdout);
     ios_base::sync_with_stdio(false);cin.tie(nullptr);
     solve();
   //  string s;
    // cin >> s;
    //cout <<  cal(s);

}
