class Solution {
  string ans = "";

  int fact(int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) ans *= i;
    return ans;
  }

  
  void solve(string op, int i, int k, int &cnt) {
    if (!ans.empty()) return;
    if (i == (int)op.size() - 1) {
      cnt++;
      if (cnt == k) ans = op;
      return;
    }
    sort(op.begin() + i, op.end());
    for (int j = i; j < (int)op.size(); j++) {
      swap(op[i], op[j]);
      solve(op, i + 1, k, cnt);
      swap(op[i], op[j]);
      if (!ans.empty()) return;
    }
  }

public:
  string getPermutation(int n, int k) {
    int facto = fact(n);
    int pnc = facto / n; 

    int first_dig = (k + pnc - 1) / pnc;
    string op = "";
    op += char(first_dig + '0');

    if (first_dig == 1) {
      for (int i = 2; i <= n; i++) op += char(i + '0');
    } else {
      for (int i = 1; i <= n; i++) if (i != first_dig) op += char(i + '0');
    }

    k = k % pnc;
    if (k == 0) k = pnc;

    if (op.size() == 1) return op; 

    int cnt = 0;
    solve(op, 1, k, cnt);
    return ans;
  }
};
