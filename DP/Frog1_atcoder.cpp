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

/*sort form------------------------------------*/
#define pi          acos(-1.0)
#define inf         (1<<30)
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
#define vstr       vector<string>
/*---------------------------------------------*/

/*container input and output-------------------*/
#define inv(v)      for(auto& i:v) cin>>i
#define outv(v)     for(auto& i:v) cout<<i<<" "
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
#define pow2(n)     (1<<n)
#define MAX         INT_MAX
#define MIN         INT_MIN
#define ishigh(num, position)       ((num&(1<<position))>0? 1:0)
#define ll_count_one(num)           (__builtin_popcountll(num))
#define int_count_one(num)          (__builtin_popcount(num))
#define ll_count_parity(num)        (__builtin_parityll(num))
#define int_count_parity(num)       (__builtin_parity(num))
#define ll_count_clz(num)           (__builtin_clzll(num))
#define int_count_clz(num)          (__builtin_clz(num))
#define ll_count_ctz(num)           (__builtin_ctzll(num))
#define int_count_ctz(num)          (__builtin_ctz(num))

#define toupper(char)               (char & '_')
//cout<<(char)toupper('a')<<nl; out:A
#define tolower(char)               (char | ' ')
//cout<<(char)tolower('B')<<nl; out:b
#define string_lower(s)             (transform(s.begin(), s.end(), s.begin(), ::tolower))
#define string_upper(s)             (transform(s.begin(), s.end(), s.begin(), ::toupper))
/*---------------------------------------------*/

/*sort calculation function--------------------*/
lli factorial(lli n)       //return n!
{
    return (n==1||n==0)? 1 : n * factorial(n-1);
}
/*---------------------------------------------*/



/*vector<pair<int,int>-----comparator-----------------------------------*/
bool first_dec(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.first > b.first);
}
bool second_inc(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second < b.second);
}
bool second_dec(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second > b.second);
}

bool first_inc_second_dec(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.first != b.first)
        return (a.first < b.first);
    else
       return (a.second > b.second);
}
bool first_dec_second_inc(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.first != b.first)
        return (a.first > b.first);
    else
       return (a.second < b.second);
}
/*----------------------------------------------------------------------*/



/*
STL:


Multiset:
a.insert (x) – Inserts the element x in the multiset –> O(log n)
a.erase(x) – Removes all the occurrences of x –> O(log n)
a.clear () – Removes all the elements from the multiset –> O(n)
a.erase() – Remove all instances of element from multiset having the same value
a.erase(a.find(element)) – Remove only one instance of element from multiset having same value
a.find(element) - returns an iterator pointing to the lower_bound of the element which is searched in the multiset container.->O(log n)
a.lower_bound(key) ->O(log n)


*/
const lli N = 1e5+5;
lli n;
lli h[N];
lli dp[N];
lli f(lli i)
{
    if(i==n)return 0;

    if(dp[i]!=-1)return dp[i];

    lli cost = inf;

    cost = min(cost, abs(h[i]-h[i+1])+f(i+1));
    if(i+2<=n)
    {
        cost = min(cost, abs(h[i]-h[i+2])+f(i+2));
    }

    return dp[i] = cost;
}

void solve_the_problem(int T)
{
    memset(dp, -1, sizeof(dp));
    cin>>n;
    for(lli i = 1; i<=n; i++)
    {
        cin>>h[i];
    }
    cout<<f(1)<<nl;
    
}
int main()
{
    fast;
    int t = 1;
    // cin>>t;
    for(int i = 1; i<=t; i++){
        solve_the_problem(i);
    }
    return 0;
}
