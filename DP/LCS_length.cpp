//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cctype>
#include<vector>
#include<bitset>
#include<map>
#include<cstring>
#include<set>
#include<stack>
#include <climits>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<numeric>
#include<cstdio>
#include<iomanip>
#include<string>
using namespace std;

#define nl          "\n"

/*data type -----------------------------------*/
#define ulli        unsigned long long int
#define lli         long long int
#define ll          long long
#define ld          long double
/*---------------------------------------------*/

/*container -----------------------------------*/
#define vint        vector<int>
#define vll         vector<long long>
#define vlli        vector<long long int>
#define vchAR       vector<chAR>
#define vstr        vector<string>
/*---------------------------------------------*/

/*container input and output-------------------*/
#define inv(v)      for(auto& i:v) cin>>i
#define outv(v)     for(auto& i:v) cout<<i<<" "
/*---------------------------------------------*/

#define gcd(x,y)    __gcd(x,y)
#define lcm(x,y)    ((x*y)/(gcd(x,y)))

/*---------------------------------------------*/

string s, t;
lli dp[3005][3005];

lli f(lli i, lli j)
{
    if(i==s.size() || j==t.size())return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    lli ans = 0;

    if(s[i]==t[j])
    {
        ans = 1+f(i+1, j+1);
    }
    else
    {
        ans = max(ans, f(i+1, j));
        ans = max(ans, f(i, j+1));
    }
    return dp[i][j] = ans;
}


void AC(int T)
{
    memset(dp, -1, sizeof(dp));
    cin>>s>>t;

    lli LCS_length = f(0,0);
    cout<<LCS_length<<nl;

    

}
int main()
{
    int T = 1;
    // cin>>T;
    for(int i = 1; i<=T; i++){
        AC(i);
    }
}