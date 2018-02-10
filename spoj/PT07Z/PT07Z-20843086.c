#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <cstdio>

using namespace std;
typedef long long ll;
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define REPI(i, j) for(int i=1; i<=j; i++)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define pb push_back
#define si(x)    scanf("%d",&x)
#define sl(x)    scanf("%lld",&x)
#define ss(s)    scanf("%s",s)
#define pi(x)    printf("%d\n",x)
#define pl(x)    printf("%lld\n",x)
#define ps(s)    printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vl;
const int mod = 1000000007;

void solve();

int main() {
    //freopen("../input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

vector<int> adj[100000];
map<int, int> max_count;

int res = 0;

void dfs(int i, int p=0){
    int first = -1, second = -1;
    for(auto a: adj[i]){
        if(a != p){
            dfs(a, i);
        }
    }
    for(auto j: adj[i]){
        if(j!=p){
            if(max_count[j] > first){
                second = first;
                first = max_count[j];
            }else if(max_count[j] > second){
                second = max_count[j];
            }
        }
    }
    int temp = first+ second + 2;
    max_count[i] = first + 1;
    if(temp> res) res = temp;
    return;
}

void solve() {
    int n;
    cin>>n;
    REP(i, n-1){
        int a, b;
        cin>>a>>b;
        a--, b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(0);
    cout<<res;
}
