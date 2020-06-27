#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("./input.txt", "r")) freopen("./input.txt", "r", stdin);
    while (!cin.eof()) {
        long long x, y, n, res = 1;
        cin >> x >> y >> n;
        x %= n;
        while (y) {
            if (y & 1) {
                res = (res * x) % n;
            }
            x = (x * x) % n;
            y = y >> 1;
        }
        cout << res << '\n';
    }
    return 0;
}