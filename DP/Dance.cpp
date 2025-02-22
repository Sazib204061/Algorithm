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

const lli inf = 1LL<<62;
const lli N = 2e6;

lli aff[17][17];
lli n, ans = 0;

void f(string s, lli xr)
{
    lli next_single = -1;
    //find next not paired number
    for(lli i = 0; i<2*n; i++)
    {
        if(s[i]=='0')
        {
            next_single = i;
            break;
        }
    }

    //if next number not found or all number ar used
    if(next_single==-1)
    {
        ans = max(ans, xr);
        return;
    }

    //if next number found then we need paired
    //this another single number, so find next
    //single and make pair and update binary string

    for(lli i = next_single+1; i<2*n; i++)
    {
        if(s[i]=='0')
        {
            string t = s;
            t[next_single] = '1';
            t[i] = '1';
            f(t, xr^aff[next_single][i]);
        }
    }
}

void solve_the_problem(int T)
{
    cin>>n;
    string s = "";
    for(lli i = 0; i<2*n-1; i++)
    {
        for(lli j = i+1; j<2*n; j++)
        {
            cin>>aff[i][j];
        }
    }
    for(lli i = 0; i<2*n; i++)
    {
        s+='0';
    }

    f(s, 0);
    cout<<ans<<nl;
}
int main()
{
    int t = 1;
    //cin>>t;
    for(int i = 1; i<=t; i++)
        solve_the_problem(i);
}

