#include <algorithm>
#include <iostream>
using namespace std;

int mod = 1e7 + 7;

long long pow(long long a, long long b) {
    long long res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("./input.txt", "r")) freopen("./input.txt", "r", stdin);
    while (true) {
        int a, b;
        cin >> a >> b;
        if (!b and !a) break;
        long long result = pow(a - 1, a - 1) + pow(a - 1, b);
        result = (result << 1) + pow(a, b) + pow(a, a);
        result %= mod;
        cout << result << '\n';
    }
    return 0;
}