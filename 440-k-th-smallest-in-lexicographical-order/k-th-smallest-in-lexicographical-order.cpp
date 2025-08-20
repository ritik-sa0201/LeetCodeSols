class Solution {
    int cnt = 0, ans = -1;

    int countSubtree(long long prefix, int n) {
        int count = 0;
        long long first = prefix, last = prefix;
        while (first <= n) {
            count += int(std::min(n + 1LL, last + 1LL) - first);
            first *= 10;
            last = last * 10 + 9;
        }
        return count;
    }

    void solve(long long i, int n, int k) {
        if (i > n || ans != -1) return;
        int subtreeCount = countSubtree(i, n);
        if (cnt + subtreeCount < k) {
            cnt += subtreeCount; 
            return;
        }
      
        cnt++;
        if (cnt == k) {
            ans = int(i);
            return;
        }
      
        for (int j = 0; j <= 9; j++) {
            long long no = i * 10 + j;
            if (no > n) return;
            solve(no, n, k);
            if (ans != -1) return; 
        }
    }
public:
    int findKthNumber(int n, int k) {
        cnt = 0;
        ans = -1;
        for (long long i = 1; i <= 9; i++) {
            if (ans == -1) solve(i, n, k);
        }
        return ans;
    }
};
