class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        int j=s.size()-1;
        int maxi=INT_MIN;
        int sum = 0;
        int ans = 0;
        while(j>=0){
          sum = sum+ans+s[j];
          ans =ans+s[j];
          maxi = max(maxi,sum);
          j--;
        }
        return maxi<0?0:maxi;
    }
};