class Solution {
    int cnt = 0, ans = -1;

int countSubtree(long long i, int n) {
    int count = 0;
    long long first = i, last = i;

    while (first <= n) {
        if (n >= first && n <= last) {
            count += int(n - first + 1);
            break; 
        }
        else {
            count += int(last - first + 1);
        }
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
