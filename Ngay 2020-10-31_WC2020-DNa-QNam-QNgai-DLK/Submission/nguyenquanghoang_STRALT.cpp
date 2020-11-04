#include<bits/stdc++.h>
using namespace std;
stack<string> st, st2;
string s;
stack<int> num;
stack<int> th;
int ans = 0;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s;
    string res, ok;
    int pos = 0, cs;
    for(int i = 0; i < s.size(); ++ i) {
        if(s[i] >= 'a' && s[i] <= 'z') res += s[i];
        if(s[i] >= '0' && s[i] <= '9') pos = pos * 10 + s[i] - 48;
        if(s[i] == '(') {
            if(res.size() > 0) st.push(res);
            st.push("(");
            res = "";
            num.push(pos);
            pos = 0;
        }
        if(s[i] == '[') {
            if(res.size() > 0) st.push(res);
            st.push("[");
            res = "";
        }
        if(s[i] == ')') {
            ++ ans;
            ok = "";
            while(st.top() != "(") {
                res = st.top() + res;
                st.pop();
            }
            //cout << res << ' ' << pos << '\n';
            pos = num.top();
            num.pop();
            for(int j = 1; j <= pos; ++ j) {
                ok += res;
            }
            //cout << ok << '\n';
            st.pop();
            st.push(ok);
            ok = "";
            pos = 0;
            res = "";
        }
        if(s[i] == '*') {
            if(s[i + 1] == ']') cs = 3;
            else cs = 2;
            th.push(cs);
            cs = 0;
        }
        if(s[i] == ']') {
            ++ ans;
            while(st.top() != "[") {
                res = st.top() + res;
                st.pop();
            }
            //cout << res << '\n';
            cs = th.top();
            th.pop();
            string res2 = res;
            reverse(res2.begin(), res2.end());
            if(cs == 3) {
                res2.erase(0, 1);
            }
            res += res2;
            //cout << res << '\n';
            st.pop();
            st.push(res);
            res = "";
            cs = 0;
        }
    }
    if(res.size() > 0) st.push(res);
    cout << ans << '\n';
    while(!st.empty()) {
        st2.push(st.top());
        st.pop();
    }
    while(!st2.empty()) {
        cout << st2.top();
        st2.pop();
    }
    return 0;
}
///ab[c[*d]*]
