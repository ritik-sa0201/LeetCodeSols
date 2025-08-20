class Solution {
    int cnt = 0, ans = -1; // cnt = how many numbers we've visited so far in lexicographic order, ans = result when found

    // Count how many numbers are in the lexicographic subtree rooted at prefix i (within limit n)
    int countSubtree(long long i, int n) {
        int count = 0;           // total numbers under this prefix
        long long lb = i, ub = i; // lb = current lower bound, ub = current upper bound (prefix range)

        while (lb <= n) { // while the range starting at this prefix is still within n
            if (n >= lb && n <= ub) {
                // Case 1: n falls inside this prefix range
                // We can only count up to n
                count += int(n - lb + 1);
                break; 
            }
            else {
                // Case 2: whole range fits in [lb, ub] ≤ n
                // Count all numbers from lb to ub
                count += int(ub - lb + 1);  // ✅ FIX: your code had (lb - ub + 1), which is negative
            }

            // Go one level deeper in the lexicographic tree
            lb *= 10;         // expand prefix lower bound (e.g., 1 → 10)
            ub = ub * 10 + 9; // expand upper bound (e.g., 1 → 19, then 10 → 109)
        }
        return count;
    }

    // DFS with pruning using subtree counts
    void solve(long long i, int n, int k) {
        if (i > n || ans != -1) return; // stop if prefix exceeds n or we already found answer

        int subtreeCount = countSubtree(i, n); // how many numbers under prefix i
        if (cnt + subtreeCount < k) {
            // If the k-th number is NOT inside this subtree, skip it entirely
            cnt += subtreeCount; 
            return;
        }
      
        // Otherwise, this prefix contributes to the answer path
        cnt++; 
        if (cnt == k) {        // If this is exactly the k-th number
            ans = int(i);      // record the answer
            return;
        }
      
        // Recurse into children (append digits 0–9)
        for (int j = 0; j <= 9; j++) {
            long long no = i * 10 + j; // child prefix
            if (no > n) return;        // no need to go deeper if child prefix exceeds n
            solve(no, n, k);           // recursive call
            if (ans != -1) return;     // stop once answer is found
        }
    }

public:
    int findKthNumber(int n, int k) {
        cnt = 0; // reset counter
        ans = -1; // reset answer
        for (long long i = 1; i <= 9; i++) { // start DFS from prefixes 1–9
            if (ans == -1) solve(i, n, k);
        }
        return ans; // return final answer
    }
};
