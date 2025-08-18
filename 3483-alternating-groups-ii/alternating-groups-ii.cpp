class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        vector<int>a = colors;
        for(int i=0;i<k-1;i++)a.push_back(colors[i]);
        int ans=0,temp=1;

        for(int i=1;i<a.size();i++){
            if(a[i]!=a[i-1]){
                temp++;
            }
            else temp=1;

            if(temp>=k)ans++;
        }
        return ans;
    }
};