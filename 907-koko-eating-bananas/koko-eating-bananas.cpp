class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int si = 1;  // Start from 1 (minimum speed can't be 0)
        int ei = *max_element(piles.begin(), piles.end()); // Maximum pile size
        int ans = ei;

        while (si <= ei) {
            int mid = si + (ei - si) / 2;
            long long hours = 0;  // Use long long to prevent overflow

            // Calculate total hours needed at speed 'mid'
            for (int pile : piles) {
                hours += (pile + mid - 1) / mid;  // Equivalent to ceil(pile / mid)
            }

            if (hours <= h) {
                ans = mid; // Try for a smaller speed
                ei = mid - 1;
            } else {
                si = mid + 1; // Increase speed
            }
        }

        return ans;
    }
};