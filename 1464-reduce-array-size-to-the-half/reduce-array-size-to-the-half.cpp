class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int x:arr)mp[x]++;
        priority_queue<int>maxh;
        for(auto& it:mp)maxh.push(it.second);
        int n=arr.size();
        int cnt=0;
        int ans=0;
        while(cnt<n/2){
            cnt+=maxh.top();maxh.pop();
            ans++;
        }
    return ans;
    }
};