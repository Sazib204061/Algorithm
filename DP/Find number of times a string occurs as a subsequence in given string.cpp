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
//this 
string a, b;

lli dp[1000005][10];

int f(lli n, lli m)  
{
    if((n==0 && m==0)||m==0)  //base sequence found
    {
        return 1;
    }

    if(n==0)    //invalid sequence not found
    {
        return 0;
    }

    if(dp[n][m]!=-1)return dp[n][m];

    lli ans = 0;

    if(a[n-1]==b[m-1])
    {
        ans+=f(n-1, m-1);
    }
    ans+=f(n-1, m);
    return dp[n][m] = ans;
}


void AC(int T)
{
    memset(dp, -1, sizeof(dp));
    a = "GeeksforGeeks";
    b = "Gks";
    cout<<f(a.size(), b.size())<<nl;
}
int main()
{
    int T = 1;
    // cin>>T;
    for(int i = 1; i<=T; i++){
        AC(i);
    }
}