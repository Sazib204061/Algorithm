//problem link: https://cses.fi/problemset/task/1145/
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
 
lli length_of_LIS(vector<lli>&a)
{
    lli n = a.size();
    vector<lli>b;
    for(lli i = 0; i<n; i++)
    {
        //auto ind = upper_bound(b.begin(), b.end(), a[i]);
        auto ind = lower_bound(b.begin(), b.end(), a[i]);
        if(ind==b.end())b.push_back(a[i]);
        else
        {
            b[ind-b.begin()] = a[i];
        }
    }
    return b.size();
}
 
int main()
{
    
    lli n, num;
    cin>>n;
    vector<lli>ar(n);
    for(int i = 0; i<n; i++)
    {
        cin>>ar[i];
    }
    lli lis = length_of_LIS(ar);
    cout<<lis<<nl;
}
