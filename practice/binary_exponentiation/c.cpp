#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("./input.txt", "r")) freopen("./input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        if (!a) {
            cout << "0\n";
        } else {
            a %= 10;
            long long res = 1;
            while (b) {
                if (b & 1) {
                    res = (res * a) % 10;
                }
                a = (a * a) % 10;
                b = b >> 1;
            }
            cout << res << '\n';
        }
    }
    return 0;
}