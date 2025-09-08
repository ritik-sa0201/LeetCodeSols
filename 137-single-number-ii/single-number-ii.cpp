class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> ct(32, 0);

        for (int num : nums) {
            for (int bit = 0; bit < 32; bit++) {
                if ((num >> bit) & 1) {
                    ct[bit]++;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (ct[i] % 3 != 0) {
                ans |= (1 << i);
            }
        }

        if (ans & (1 << 31)) {
            ans -= (1LL << 32);  
        }

        return ans;
    }
};
