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
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<numeric>
#include<cstdio>
#include<iomanip>
#include<string>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

/*sort form------------------------------------*/
#define pi          acos(-1.0)
#define PI          (2*acos(0.0))
#define nl          "\n"
#define yes         cout<<"YES"<<nl;
#define no          cout<<"NO"<<nl;
/*---------------------------------------------*/

/*data type -----------------------------------*/
#define ulli        unsigned long long int
#define lli         long long int
#define ll          long long
#define ld          long double
#define i_in(p)     scanf("%d", &p)
/*---------------------------------------------*/

/*container -----------------------------------*/
#define vint        vector<int>
#define vll         vector<long long>
#define vlli        vector<long long int>
#define vchar       vector<char>
/*---------------------------------------------*/

/*container input and output-------------------*/
#define inv(v)      for(auto& i:v) cin>>i
#define outv(v)     for(auto& i:v) cout<<i<<" "
/*---------------------------------------------*/
/*Policy based Data Structure-------------------*/
/*template <typename T>  using orderedSet =
   tree<T, null_type, less<T>,
   rb_tree_tag, tree_order_statistics_node_update>;*/
/*---------------------------------------------*/

/*container function --------------------------*/
#define all(v)      v.begin(),v.end()
#define rall(v)     v.rbegin(),v.rend()
#define sum(a)      ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)     (*min_element((a).begin(), (a).end()))
#define maxe(a)     (*max_element((a).begin(), (a).end()))
#define mini(a)     ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)     ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x)  ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x)  ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define Sort(a)     ( sort((a).begin(), (a).end()))
#define Sort_d(a)   ( sort(a.begin(), a.end(), greater<int>()))
/*---------------------------------------------*/

#define precision(n) fixed<<setprecision(n)
#define fast ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);

/*my function ---------------------------------*/
#define max2(x,y)   ((x>y)?x:y)
#define min2(x,y)   ((x<y)?x:y)
#define gcd(x,y)    __gcd(x,y)
#define lcm(x,y)    ((x*y)/(gcd(x,y)))
#define mod         1000000007
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })
/*---------------------------------------------*/

/*bit manipulation-----------------------------*/
const lli N = 1e6;
lli n;
lli h[2][N];
lli dp[N][3];

lli f(lli ind, lli last)
{
    if(ind==n)return 0;
    if(dp[ind][last]!=-1)return dp[ind][last];
    lli res = 0;
    if(last==0)
    {
        res = max(res,h[1][ind]+f(ind+1,1));
        res = max(res, f(ind+1, 2));
    }
    if(last==1)
    {
        res = max(res, h[0][ind]+f(ind+1, 0));
        res = max(res,f(ind+1,2));
    }
    if(last==2)
    {
        res = max(res,h[0][ind]+f(ind+1, 0));
        res = max(res,h[1][ind]+f(ind+1, 1));
        res = max(res,f(ind+1, 2));
    }
    return dp[ind][last] = res;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin>>n;
    for(lli i = 0; i<2; i++)
    {
        for(lli j = 0; j<n; j++)
        {
            cin>>h[i][j];
        }
    }
    cout<<f(0,2)<<endl;
}
