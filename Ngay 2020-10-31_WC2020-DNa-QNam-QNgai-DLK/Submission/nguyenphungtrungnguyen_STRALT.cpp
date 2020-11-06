#include <bits/stdc++.h>
using namespace std;
string s;
stack<char> st;
int main(){
    cin >> s;
    long res = 0;
    long type1 = 0,type2 = 0,type3 = 0;
    for(long i = 0; i < s.size(); i++){
        if( type2 && s[i] == ']' ){
            if( st.top() == '*' ){
                st.pop();
                string tmp = "";
                while( st.top() != '[' ){
                    tmp += st.top();
                    st.pop();
                }
                st.pop();
                for(long j = tmp.size() - 1; j >= 0; j--) st.push( tmp[j] );
                for(long j = 1; j < tmp.size(); j++) st.push( tmp[j] );
            }
            else{
                string tmp = "";
                while( st.top() != '*' ){
                    tmp += st.top();
                    st.pop();
                }
                st.pop();
                st.pop();
                for(long j = tmp.size() - 1; j >= 0; j--) st.push( tmp[j] );
                for(long j = 0; j < tmp.size(); j++) st.push( tmp[j] );
            }
            type2--;
            continue;
        }
        if( type1 && s[i] == ')' ){
            string tmp = "";
            while( st.top() != '(' ){
                    tmp += st.top();
                    st.pop();
            }
            reverse( tmp.begin(), tmp.end() );
            st.pop();
            string a;
            while( st.top() >= '0' && st.top() <= '9'){
                a += st.top();
                st.pop();
                if( st.size() == 0 ) break;
            }
            reverse(a.begin(),a.end());
            long res = 0;
            for(long j = 0; j < a.size(); j++){
                res = res * 10 + ( a[j] - '0' );
            }
            for(long j = 1; j <= res; j++){
                for(long k = 0; k < tmp.size(); k++){
                    st.push(tmp[k]);
                }
            }
            type1--;
            continue;
        }
        if( s[i] == '(' ){
            res++;
            st.push( s[i] );
            type1++;
            continue;
        }
        if( s[i] == '[' ){
            type2++;
            res++;
            st.push(s[i]);
            continue;
        }
        st.push( s[i] );
        //cout << 1 << " ";
    }
    string ans = "";
    while( st.size() ){
        ans += st.top();
        st.pop();
    }
    cout << res << '\n';
    reverse(ans.begin(),ans.end());
    cout << ans;
}
