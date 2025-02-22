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

lli n, s;
vlli a(105), b(105);
lli dp[105][10005];
lli mark[105][10005];


lli f(lli i, lli sum)
{
    if(i==n)
    {
        if(sum==s)return 1;
        else return 0;
    }
    if(sum>s)return 0;

    if(dp[i][sum]!=-1)return dp[i][sum];

    lli ans = 0;

    lli temp1 = f(i+1,sum+a[i]);
    lli temp2 = f(i+1,sum+b[i]);

    if(temp1==1)
    {
        mark[i][sum] = 1;
    }
    if(temp2==1)
    {
        mark[i][sum] = 2;
    }

    ans = temp1 | temp2;

    return dp[i][sum] = ans;
}


void print_way(lli i, lli sum)
{
    if(i==n)
    {
        return;
    }
    if(sum>s)return;

    if(mark[i][sum]==1)
    {
        cout<<"H";
        print_way(i+1,sum+a[i]);
    }
    else if(mark[i][sum]==2)
    {
        cout<<"T";
        print_way(i+1, sum+b[i]);
    }
}


void AC(int T)
{
    memset(dp, -1, sizeof(dp));
    cin>>n>>s;
    for(lli i = 0; i<n; i++)
    {
        cin>>a[i]>>b[i];
    }
    lli ans = f(0,0);

    if(ans)
    {
        cout<<"Yes"<<nl;
        print_way(0,0);
        cout<<nl;
    }
    else cout<<"No"<<nl;

}
int main()
{
    int T = 1;
    // cin>>T;
    for(int i = 1; i<=T; i++){
        AC(i);
    }
}