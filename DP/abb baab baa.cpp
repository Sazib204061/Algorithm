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

lli cnt_string(lli cnt_a, lli cnt_b)
{  // calculate (n+m)!/(n!*m!) = (n+m)Cn
    lli n = cnt_a+cnt_b;
    lli r = cnt_a;
    lli cnt = 1;

    for(lli i = 0; i<r; i++)
    {
        cnt*=(n-i);
        cnt/=(i+1);
    }
    return cnt;
}
string ans = "";

void f(lli cnt_a, lli cnt_b, lli k)
{
    //cout<<cnt_a<<" "<<cnt_b<<nl;
    if(cnt_a==0 && cnt_b==0)return;

    lli left = (cnt_a==0)? 0 : cnt_string(cnt_a-1, cnt_b); //left side a koto gola string babano possible
    lli right = (cnt_b==0)? 0 : cnt_string(cnt_a, cnt_b-1);//right side a koto gola string babano possible

    if(left>=k)
    {
        ans+='a';
        f(cnt_a-1, cnt_b, k);
    }
    else{
        ans+='b';
        f(cnt_a, cnt_b-1, k-left);
    }
}

//TC : O(n*n)
void solve_the_problem(int T)
{
    lli a, b, k;
    cin>>a>>b>>k;
    f(a, b, k);
    cout<<ans<<nl;
    return;
}
int main()
{
    int t = 1;
    //cin>>t;
    for(int i = 1; i<=t; i++)
        solve_the_problem(i);
}
