#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <stack>

using namespace std;
typedef long long ll;
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (ll i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (ll i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define REPI(i, j) for(ll i=1; i<=j; i++)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define pb push_back
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vl;
const ll mod = 1000000007;

void solve();

int main() {
    //freopen("../input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

void solve() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ele;
        map<int, int> m;
        bool f = false;
        REP(i, n){
            int temp;
            cin>>temp;
            m[temp]++;
            if(m[temp]>(n/2)) f = true, ele = temp;
        }
        if(f) cout<<"YES "<<ele<<endl;
        else cout<<"NO"<<endl;
    }
}