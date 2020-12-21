#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5+7;
int n, m, t, min_temp = maxN;
vector < pair<int, int> > clothes;
void Input(){
    freopen("COOLMAC.INP","r",stdin);
    freopen("COOLMAC.OUT","w+",stdout);
    bool check_limit = false;
    cin >> m;
    for(int i = 1; i <= m; ++i){
        int l, r;
        cin >> l >> r;
        if(r >= 100000) check_limit = true;
        clothes.push_back(make_pair(l, r));
    }
    if(!check_limit){
        cout << -1;
        exit(0);
    }
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> t;
        if(t < min_temp) min_temp = t;
    }
}
bool cmp1(const pair<int, int> &a , const pair<int, int> &b){
    return (a.second >= b.second && a.first <= b.first);
}
bool cmp2(const pair<int, int> &a , const pair<int, int> &b){
    return (a.second > b.second);
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Input();
    // Sort 1 first time
    sort(clothes.begin(), clothes.end(),cmp2);
    // Xoá phần bao nhau
    for(int i = 1; i < clothes.size(); ++i){
        if(clothes[i].first >= clothes[i-1].first && clothes[i].second <= clothes[i-1].second){
            clothes.erase(clothes.begin()+i);
            i--;
        }
        if(clothes[i].second < min_temp){
            clothes.erase(clothes.begin()+i);
            i--;
        }
    }
    // Xoá cặp l, r là giao của 2 đoạn l, r khác
    for(int i = 1; i < clothes.size()-1; ++i){
        if(clothes[i].second >= clothes[i-1].first && clothes[i-1].first <= clothes[i+1].second){
            clothes.erase(clothes.begin()+i);
            i--;
        }
    }
    // Sort second time
    sort(clothes.begin(), clothes.end(), cmp1);
    // Xoá bao nhau lần 2
    for(int i = 1; i < clothes.size(); ++i){
        if(clothes[i].first >= clothes[i-1].first && clothes[i].second <= clothes[i-1].second){
            clothes.erase(clothes.begin()+i);
            i--;
        }
    }
    // Kiểm tra tính liên tục
    bool check_continuous = true;
    for(int i = 0; i < clothes.size()-1; ++i){
        if(clothes[i].first - clothes[i+1].second > 1) check_continuous = false;
    }
    if(clothes[clothes.size()-1].first > min_temp) check_continuous = false;
    // Xuất kết quả
    if(!check_continuous)
        cout << -1;
    else
        cout << clothes.size();
    return 0;
}
