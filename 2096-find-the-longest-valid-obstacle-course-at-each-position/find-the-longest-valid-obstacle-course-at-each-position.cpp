class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& os) {
        vector<int>temp,ans;
        temp.push_back(os[0]);
        ans.push_back(1);
        int len=1;
        for(int i=1;i<os.size();i++){
            if(os[i]>=temp.back()){
                temp.push_back(os[i]);
                len++;
                ans.push_back(len);
            }

            else{
                int it = upper_bound(temp.begin(),temp.end(),os[i])-temp.begin();
                 temp[it]=os[i];
                 ans.push_back(it+1);
                            }
        }
        return ans;
    }
};