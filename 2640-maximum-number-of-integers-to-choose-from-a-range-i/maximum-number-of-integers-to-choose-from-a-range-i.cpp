class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>st;
        for(int ch:banned)st.insert(ch);
        int ans=0;
        for(int i=1;i<n+1;i++){
            if(maxSum<0)break;
           if(st.find(i)==st.end() && maxSum>=i){
            ans+=1;
            maxSum-=i;
           }
        }
        return ans;
    }
};