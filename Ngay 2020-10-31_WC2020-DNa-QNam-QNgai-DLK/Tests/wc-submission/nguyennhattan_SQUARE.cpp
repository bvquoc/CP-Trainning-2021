#include <bits/stdc++.h>

using namespace std;

long long k;

void suble()
{
    if (k<0) cout<<(abs(k)/2);
        else cout<<(k/2)+1;
}

int main()
{
    cin>>k;
    if (k==0) cout<<"0";
        else if (abs(k) % 2 ==1) suble();
            else
                {
                    long long res=k;
                    if ((sqrt(abs(res)))-(trunc(sqrt(abs(res))))==0 && res>0) cout<<trunc(sqrt(abs(res)));
                    else if ((sqrt(abs(res)))-(trunc(sqrt(abs(res))))==0 && res<0) cout<<"0";
                    else
                        {
                            for (int i=1; i<=1e6; i+=2)
                                {
                                    res+=i;
                                   // cout<<sqrt(res)<<" "<<trunc(sqrt(res))<<endl;
                                   if (res==0)
                                   {
                                       cout<<res;
                                       return 0;
                                   }
                                    if (res>0)
                                      if ((sqrt(abs(res)))-(trunc(sqrt(abs(res))))==0)
                                        {
                                            cout<<trunc(sqrt(abs(res)));
                                            return 0;
                                        }
                                }
                            cout<<"none";
                        }
                }
}
