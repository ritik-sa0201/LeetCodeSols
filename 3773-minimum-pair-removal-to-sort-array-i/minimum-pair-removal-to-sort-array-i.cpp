class Solution {
   
   bool check(vector<int>& nums) {
       if (nums.size() == 1) return true;
       for (int i = 0; i < (int)nums.size() - 1; i++) {
           if (nums[i] > nums[i + 1]) return false;
       }
       return true;
   }

public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;

        while (true) {
            if (check(nums)) break;

            priority_queue<pair<long long,int>, 
                           vector<pair<long long,int>>, 
                           greater<pair<long long,int>>> minh;

            for (int i = 0; i < (int)nums.size() - 1; i++) {
                long long sum = (long long)nums[i] + nums[i + 1];
                minh.push({sum, i});
            }

            auto [sum, idx] = minh.top();
            minh.pop();

            nums[idx] = (int)sum;

            
            for (int i = idx + 1; i < (int)nums.size() - 1; i++) {
                nums[i] = nums[i + 1];
            }
            nums.pop_back();

            count++;
        }

        return count;
    }
};
