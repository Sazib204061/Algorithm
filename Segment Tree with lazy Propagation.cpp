Problem CSES : Range Update Queries
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

#define mx 1000001
lli arr[mx];
struct info {
    lli prop, sum;  //sum ছাড়াও নিচে অতিরিক্ত কত যোগ হচ্ছে সেটা রাখবো prop এ
} tree[mx * 3]; 


void init(lli node, lli b, lli e)
{
    if (b == e) {
        tree[node].sum = arr[b];
        tree[node].prop = 0;
        return;
    }
    lli Left = node * 2;
    lli Right = node * 2 + 1;
    lli mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].sum = tree[Left].sum+tree[Right].sum;
    tree[node].prop = 0;
}


void update(lli node, lli b, lli e, lli i, lli j, lli x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j) //নোডের রেঞ্জ আপডেটের রেঞ্জের ভিতরে
    {
        tree[node].sum += ((e - b + 1) * x); //নিচে নোড আছে e-b+1 টি, তাই e-b+1 বার x যোগ হবে এই রেঞ্জে
        tree[node].prop += x; //নিচের নোডগুলোর সাথে x যোগ হবে
        return;
    }
    lli Left = node * 2;
    lli Right = (node * 2) + 1;
    lli mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
    //উপরে উঠার সময় পথের নোডগুলো আপডেট হবে
    //বাম আর ডান পাশের সাম ছাড়াও যোগ হবে নিচে অতিরিক্ত যোগ হওয়া মান
}

lli query(lli node, lli b, lli e, lli i, lli j, lli carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1); //সাম এর সাথে যোগ হবে সেই রেঞ্জের সাথে অতিরিক্ত যত যোগ করতে বলেছে সেটা

    lli Left = node << 1;
    lli Right = (node << 1) + 1;
    lli mid = (b + e) >> 1;

    lli p1 = query(Left, b, mid, i, j, carry + tree[node].prop); //প্রপাগেট ভ্যালু বয়ে নিয়ে যাচ্ছে carry ভ্যারিয়েবল
    lli p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

int main()
{
    lli n, q, op, a, b, u, k;
    cin>>n>>q;
    for(lli i = 1; i<=n; i++)
    {
        cin>>arr[i];
    }
    init(1, 1, n);
    while(q--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>a>>b>>u;
            update(1, 1, n, a, b, u);
        }
        else
        {
            cin>>k;
            cout<<query(1, 1, n, k,k)<<nl;
        }
    }
    /*
    init(1, 1, n);
    //cout<<tree[8].sum<<" "<<tree[8].prop<<endl;
    update(1, 1, n, 1, 2, 5);
    update(1, 1, n, 1, 2, );
    cout<<query(1, 1, n, 1, 4)<<endl;*/
}

/*
input:
8 3
3 2 4 5 1 1 5 3
2 4
1 2 5 1
2 4

output:
5
6
*/
