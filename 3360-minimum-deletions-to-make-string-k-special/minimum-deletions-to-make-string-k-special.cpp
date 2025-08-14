class Solution {
 int helper(vector<int> &a, int i, int k) {
    int num = a[i];
    int ans = 0;
    
    for (int j = 0; j < a.size(); j++) {
        if (a[j] < num) {
            ans += a[j];
        }
        else if (a[j] > num + k) {
            ans += (a[j] - (num + k));
        }
    }
    return ans;
}



public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int>mp;
        for(char ch:word)mp[ch]++;
        vector<int>a;
        for(auto& it:mp)a.push_back(it.second);
        sort(a.begin(),a.end());
        set<int>st;
        int ans=INT_MAX;
        for(int i=0;i<a.size();i++){
         if(st.find(a[i])==st.end()){
            int solve = helper(a,i,k);
            ans = min(ans,solve);
            st.insert(a[i]);
         }
        }
        return ans;
    }
};