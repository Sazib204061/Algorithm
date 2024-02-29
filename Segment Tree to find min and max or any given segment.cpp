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

#define mx 1000001
int arr[mx];
//int tree[mx * 3];
//int tree[mx*3][2];
vector<pair<int,int>>tree(mx*3);
void init(int node, int b, int e)
{
    if (b == e) {
        tree[node].first = arr[b];
        tree[node].second = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].first = min(tree[Left].first,tree[Right].first);
    tree[node].second = max(tree[Left].second,tree[Right].second);
}

pair<int,int> query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return {INT_MAX, INT_MIN}; 
    if (b >= i && e <= j)
        return {tree[node].first, tree[node].second}; 
    int Left = node * 2; 
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    pair<int,int>p1 = query(Left, b, mid, i, j);
    pair<int,int>p2 = query(Right, mid + 1, e, i, j);
    int Mn = min(p1.first, p2.first);
    int Mx = max(p1.second, p2.second);
    return {Mn, Mx};
}


void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return; 
    if (b >= i && e <= i) { 
        tree[node].first = newvalue;
        tree[node].second = newvalue;
        return;
    }
    int Left = node * 2; 
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node].first = min(tree[Left].first,tree[Right].first);
    tree[node].second = max(tree[Left].second,tree[Right].second);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin >> n>>k;
        for(int i = 1; i<=n; i++)
        {
            cin>>arr[i];
        }
        init(1, 1, n);
        int op, l, r, newvalue, ind;
        while(k--)
        {
            cin>>op;
            if(op==1)  //update
            {
                cin>>ind>>newvalue;
                update(1, 1, n, ind, newvalue);
            }
            else
            {
                cin>>l>>r;
                pair<int,int>ans = query(1, 1, n, l, r);
                cout<<"Min : "<<ans.first<<" "<<"Max : "<<ans.second<<endl;
            }
            
        }
        
    }
    return 0;
}

/*
input: 
1
5 6
5 2 3 4 1

2 1 5
2 1 2
1 1 20
2 1 5
1 5 50
2 1 5

output: 
Min : 1 Max : 5
Min : 2 Max : 5
Min : 1 Max : 20
Min : 2 Max : 50

*/
