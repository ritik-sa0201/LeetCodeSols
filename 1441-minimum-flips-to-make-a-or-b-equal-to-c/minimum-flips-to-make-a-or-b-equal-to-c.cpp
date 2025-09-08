class Solution {
    string toBin(int a) {
        if (a == 0) return "0";
        string ans = "";
        while (a > 0) {
            ans += to_string(a % 2);
            a /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string pad(string s, int len) {
        while ((int)s.size() < len) {
            s = "0" + s;
        }
        return s;
    }

public:
    int minFlips(int a, int b, int c) {
        string x = toBin(a);
        string y = toBin(b);
        string z = toBin(c);

        int n = max({x.size(), y.size(), z.size()});
        x = pad(x, n);
        y = pad(y, n);
        z = pad(z, n);

        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            char abit = x[i];
            char bbit = y[i];
            char cbit = z[i];

            if (cbit == '0') {
                if (abit == '1') ans++;
                if (bbit == '1') ans++;
            } else {
                if (abit == '0' && bbit == '0') ans++;
            }
        }
        return ans;
    }
};
