class Solution {
    bool solve(long long mid, vector<int>& candies, long long k) {
        long long count = 0;
        for (int c : candies) {
            count += c / mid;
            if (count >= k) return true; 
        }
        return count >= k;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for (int c : candies) sum += c;

        
        if (sum < k) return 0;

        long long ans = 0;
        long long si = 1, ei = *max_element(candies.begin(), candies.end());

        while (si <= ei) {
            long long mid = si + (ei - si) / 2;
            if (solve(mid, candies, k)) {
                ans = mid;  
                si = mid + 1;
            } else {
                ei = mid - 1;
            }
        }
        return (int)ans;
    }
};
