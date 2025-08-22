class Solution {
    
    int bs(vector<long long>& a, long long el) {
        int n = a.size();
        int i = 0, j = n - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (a[mid] == el) return mid;
            else if (a[mid] < el) j = mid - 1;  
            else i = mid + 1;
        }
        return -1;
    }

public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> pfx(n, 0), sfx(n, 0);

        pfx[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pfx[i] = nums[i] + pfx[i - 1];
        }

        sfx[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            sfx[i] = nums[i] + sfx[i + 1];
        }

        int ans = INT_MAX;

     
        for (int i = 0; i < n; i++) {
            if (pfx[i] == x) ans = min(ans, i + 1);
        }

       
        for (int i = 0; i < n; i++) {
            if (sfx[i] == x) ans = min(ans, n - i);
        }

       
        for (int i = 0; i < n; i++) {
            if (pfx[i] > x) break;
            long long target = x - pfx[i];
            int j = bs(sfx, target);
            if (j != -1 && i < j) { 
                ans = min(ans, (i + 1) + (n - j));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
