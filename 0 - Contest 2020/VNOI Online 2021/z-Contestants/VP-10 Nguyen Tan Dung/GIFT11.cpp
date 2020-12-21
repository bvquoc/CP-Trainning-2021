#ifndef LOCAL
#define NDEBUG 1
#endif // LOCAL
#include<bits/stdc++.h>

#define taskname "GIFT11"

void up();

int main()
{
        if (fopen(taskname".inp", "r")) {
                freopen(taskname".inp", "r", stdin);
                freopen(taskname".out", "w", stdout);
        }

        std::ios_base::sync_with_stdio(0); std::cin.tie(0);

        int n_test; std::cin>>n_test;
        while (n_test--) {
                up(); std::cout<<"\n";
        }

        return 0;
}

std::string to_string(int x) {
        std::string str;
        while (x>0) {
                str=(char)(x%10+'0')+str;
                x/=10;
        }

        return str;
}

const int mod=998244353;
const int maxn=2000;

int n;
int sum_digit[maxn+5][2];
int n_digit[maxn+5];

//check the modulo of a
void refmod(int& a, int mod) {
        if (a>=mod) a-=mod;
        if (a<0) a+=mod;
}

void up1();
void up2();
void up3();

void up() {
        std::cin>>n;

        memset(sum_digit, 0, sizeof(sum_digit));

        bool check02=true, check03=true;
        for (int i=1; i<=n; ++i) {
                int x; std::cin>>x;

                std::string str=to_string(x);
                for (int j=0; str[j]; ++j) {
                        sum_digit[i][j&1]+=str[j]-'0';
                }
                sum_digit[i][0]%=11;
                sum_digit[i][1]%=11;
                n_digit[i]=str.size();

                if (check02 and (n_digit[i]&1)) check02=false;
                if (check03 and !(n_digit[i]&1)) check03=false;
        }

        if (n<10) {
                up1(); return ;
        }
        else if (check02) {
                up2(); return ;
        }
        else if (check03) {
                up3(); return ;
        }
}

void up1() {
        int id[n+1];
        for (int i=1; i<=n; ++i) id[i]=i;

        int result=0;
        do {
                int r=0, p=0;
                for (int i=1; i<=n; ++i) {
                        if (p&1) r+=sum_digit[id[i]][1]-sum_digit[id[i]][0];
                        else r+=sum_digit[id[i]][0]-sum_digit[id[i]][1];
                        p=(p+n_digit[id[i]])&1;
                        refmod(r, 11);
                }

                if (r%11==0) ++result;
        } while (std::next_permutation(id+1, id+n+1));

        std::cout<<result;
}

void up2() {
        bool check=true;
        int r=0;
        for (int i=1; i<=n; ++i) {
                r+=sum_digit[i][0]-sum_digit[i][1];
                refmod(r, 11);
        }

        if (r==0) {
                int result=1;
                for (int i=2; i<=n; ++i) {
                        result=(int64_t)result*i%mod;
                }
                std::cout<<result;
        }
        else std::cout<<"0";
}

void up3() {

}
