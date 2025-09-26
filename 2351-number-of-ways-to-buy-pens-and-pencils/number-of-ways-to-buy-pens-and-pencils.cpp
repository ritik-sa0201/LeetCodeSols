class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        for (long long i = 0; i * cost1 <= total; i++) {
            long long rem = total - i * cost1;
            long long p = rem / cost2;
            ans += (p + 1);
        }
        return ans;
    }
};
