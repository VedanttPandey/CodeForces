#include <bits/stdc++.h>
using namespace std;

string isPM(int m, int sum) {
    string mini = "";
    for (int available = 1; available <= m; ++available) {
        if (available == 1) {
            for (int i = 1; i <= 9; ++i) {
                int remaining = sum - i;
                int remaining_digits = m - available;
                if (remaining >= 0 && remaining <= remaining_digits * 9) {
                    mini += char('0' + i);
                    sum -= i;
                    break;
                }
            }
        } else {
            for (int i = 0; i <= 9; ++i) {
                int remaining = sum - i;
                int remaining_digits = m - available;
                if (remaining >= 0 && remaining <= remaining_digits * 9) {
                    mini += char('0' + i);
                    sum -= i;
                    break;
                }
            }
        }
    }
    return mini;
}

string maxPM(int m, int sum) {
    string maxi = "";
    for (int available = 1; available <= m; ++available) {
        int start = (available == 1) ? 1 : 0;
        for (int i = 9; i >= start; --i) {
            int remaining = sum - i;
            int remaining_digits = m - available;
            if (remaining >= 0 && remaining <= remaining_digits * 9) {
                maxi += char('0' + i);
                sum -= i;
                break;
            }
        }
    }
    return maxi;
}

int main() {
    int m, s; cin >> m >> s;

    if (s == 0) {
        if (m == 1) cout << 0 << " " << 0 << "\n";
        else cout << -1 << " " << -1 << "\n";
        // return 0;
    }
    else if (s > 9 * m) {
        cout << -1 << " " << -1 << "\n";
    }
else{
    string mini = isPM(m, s);
    string maxi = maxPM(m, s);

    cout << mini << " " << maxi << "\n";
}
    return 0;
}
