#include<bits/stdc++.h>
using namespace std;
#define precision(n) fixed<<setprecision(n)
#define fast ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);

/*sort form------------------------------------*/
#define pi          acos(-1.0)
#define PI          (2*acos(0.0))
#define nl          "\n"
#define yes         cout<<"YES"<<nl;
#define no          cout<<"NO"<<nl;
#define pb          push_back
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

/*container function --------------------------*/
#define all(v)      v.begin(),v.end()
#define rall(v)     v.rbegin(),v.rend()
//#define sum(a)      ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)     (*min_element((a).begin(), (a).end()))
#define maxe(a)     (*max_element((a).begin(), (a).end()))
#define mini(a)     ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)     ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x)  ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x)  ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define Sort(a)     ( sort((a).begin(), (a).end()))
#define Sort_d(a)   ( sort(a.begin(), a.end(), greater<int>()))
/*---------------------------------------------*/

/*my function ---------------------------------*/
#define max2(x,y)   ((x>y)?x:y)
#define min2(x,y)   ((x<y)?x:y)
#define gcd(x,y)    __gcd(x,y)
#define lcm(x,y)    ((x*y)/(gcd(x,y)))
#define mod         1000000007
/*---------------------------------------------*/

//solution here

/*Policy based Data Structure-------------------*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
///operation :
/*find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time.To find the first element k must be zero.
Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
*(s.find_by_order(2)) : 3rd element in the set i.e. 6
*(s.find_by_order(4)) : 5th element in the set i.e. 88

order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
s.order_of_key(6) : Count of elements strictly smaller than 6 is 2.
s.order_of_key(25) : Count of elements strictly smaller than 25 is 4.
 */
/*---------------------------------------------*/



//LCP-Longest Common Prefix

#define N 2000006

string s[N];
lli ans[N];

void f(vlli group, lli index)
{

    vlli g[26];  //vector type array 0:----, 1:-----, 2:---
    // maximum group 26 ta hote pare karon a-z 26 ta character

    for(lli i : group)
    {
        if(s[i].size()==index)
        {
            /*jodi string ar index na exist kore tahole tar jonno ans calculate
            and take ar group a add korbo na*/
            ans[i] = index;
            continue;
        }


        g[s[i][index]-'a'].push_back(i);
    }

    for(lli i = 0; i<26; i++)
    {
        if(g[i].size()==1)
        {
            /*jodi g[i]th group a 1 ta string thake tahle ans hobe
            index because ai index process korar somoy group size 1 hoice.*/
            ans[g[i][0]]=index;
            continue;
        }

        if(g[i].size()>1)
        {
            f(g[i], index+1);
        }
    }


}





void solve_the_problem(int T)
{
    lli n;
    cin>>n;
    for(lli i = 0; i<n; i++)
    {
        cin>>s[i];
    }

    vlli group;
    for(lli i = 0; i<n; i++)
    {
        group.push_back(i);
    }

    f(group,0);

    for(lli i = 0; i<n; i++)
    {
        cout<<ans[i]<<nl;
    }
}




int main()
{

    int t = 1;
    cin>>t;
    for(int i = 1; i<=t; i++){
        solve_the_problem(i);
    }
}
