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
using namespace std;
/*sort form------------------------------------*/
#define pi          acos(-1.0)
#define PI          (2*acos(0.0))
#define nl          "\n"
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

//basic
/*const int N = 1e7+5;
int mark[N];
void sieve()
{
    for(int i = 2; i<N; i++)
    {
        if(mark[i]==0)
        {
            for(int j = 2*i; j<N; j+=i)
            {
                mark[j] = 1;
            }
        }
    }
}*/


/*
Optimizations:
    1. only iterate over odd numbers
    2. iterate only upto sqrt(N)(first loop)
    3. jump only to odds numbers(second loop)
    4. Memory Efficient using bool type array(100MB) then again using bitset(3MB).

    optimized sieve
    complexity
    TC:O(log(log(N)))
*/

const int N = 1e7+5;
//bool mark[N+1];  //when N = 10e8 the size : 100MB(aprox)
bitset<N+1>mark;   //when N = 10e8 then size : 100/32 = 3MB(aprox)
void sieve()
{
    //mark all even number as not prime number
    mark[2] = 1;
    for(int i = 4; i<=N; i+=2)mark[i] = 1;
    for(int i = 3; i*i<=N; i+=2)
    {
        if(mark[i]==0)
        {
            for(int j = i*i; j<=N; j+=i*2)
            {
                //j+=i here j and i are odd so odd+odd = even(which is not necessary)
                //that's why we use j=i*2 because j odd and i*2 is even number.
                mark[j] = 1;
            }
        }
    }
}
void display_prime(int L)
{
    cout<<"All prime upto : "<<L<<endl;
    for(int i = 2; i<=L; i++)
    {
        if(mark[i]==0)
        {
            cout<<i<<" ";
        }
    }
}

void solve_the_problem(int T)
{
    display_prime(100);
}
int main()
{
    sieve();
    //int t; cin>>t;
    int t = 1;
    for(int i = 1; i<=t; i++)
        solve_the_problem(i);
}

