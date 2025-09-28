class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long total = 0;
        long long mx = 0;
        for (int m : milestones) {
            total += m;
            mx = max(mx, (long long)m);
        }
        long long rest = total - mx;
        if (mx <= rest) return total;
        return 2 * rest + 1;
    }
};
