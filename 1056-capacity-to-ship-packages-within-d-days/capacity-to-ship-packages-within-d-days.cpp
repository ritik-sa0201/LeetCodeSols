class Solution {
    int daysRequired(vector<int>& weights, int capacity) {
        int days = 1, currentLoad = 0;

        for (int weight : weights) {
            if (currentLoad + weight > capacity) {
                days++;
                currentLoad = 0;
            }
            currentLoad += weight;
        }

        return days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int si = *max_element(weights.begin(), weights.end()); 
        int ei = accumulate(weights.begin(), weights.end(), 0); 
        int res = ei;

        while (si <= ei) {
            int mid = si + (ei - si) / 2;
            int requiredDays = daysRequired(weights, mid);

            if (requiredDays <= days) {
                res = mid;
                ei = mid - 1;
            } else {
                si = mid + 1;
            }
        }

        return res;
    }
};
