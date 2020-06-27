#include <iostream>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("./input.txt", "r")) freopen("./input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << '\n';
    }
    return 0;
}