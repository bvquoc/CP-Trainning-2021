#include <bits/stdc++.h>
using namespace std;
string s;
stack<char> st;
string mul( int k, string _S )
{
    string res = "";
    for( int i = 1; i <= k; ++i ) res += _S;
    return res;
}
string Palin( string _S )
{
    int pos;
    if( _S[0] == '*' ) pos = 0;
    else pos = 1;
    if( _S[0] == '*' ) _S.erase( 0, 1 );
    else _S.erase( _S.size() - 1, 1 );
    string res = _S;
    reverse( _S.begin(), _S.end() );
    _S.erase( 0, pos );
    res += _S;
    return res;
}
int main()
{
    cin >> s;
    long res = 0;
    long type1 = 0,type2 = 0,type3 = 0;
    for(long i = 0; i < s.size(); i++)
    {
        if( type2 && s[i] == ']' )
        {
            //st.pop();
            string tmp = "";
            while( st.top() != '[' )
            {
                tmp += st.top();
                st.pop();
            }
            st.pop();
            reverse( tmp.begin(), tmp.end() );
            tmp = Palin( tmp );
            for( int i = 0; i < tmp.size(); ++i ) st.push( tmp[i] );
            type2--;
            continue;
        }
        if( type1 && s[i] == ')' )
        {
            string tmp = "";
            while( st.top() != '(' )
            {
                tmp += st.top();
                st.pop();
            }
            reverse( tmp.begin(), tmp.end() );
            st.pop();
            string a;
            while( st.top() >= '0' && st.top() <= '9')
            {
                a += st.top();
                st.pop();
                if( st.size() == 0 ) break;
            }
            reverse(a.begin(),a.end());
            long res = 0;
            for(long j = 0; j < a.size(); j++)
            {
                res = res * 10 + ( a[j] - '0' );
            }
            tmp = mul( res, tmp );
            for( int i = 0; i < tmp.size(); ++i ) st.push( tmp[i] );
            type1--;
            continue;
        }
        if( s[i] == '(' )
        {
            res++;
            st.push( s[i] );
            type1++;
            continue;
        }
        if( s[i] == '[' )
        {
            type2++;
            res++;
            st.push(s[i]);
            continue;
        }
        st.push( s[i] );
        //cout << 1 << " ";
    }
    string ans = "";
    while( st.size() )
    {
        ans += st.top();
        st.pop();
    }
    cout << res << '\n';
    reverse(ans.begin(),ans.end());
    cout << ans;
}
