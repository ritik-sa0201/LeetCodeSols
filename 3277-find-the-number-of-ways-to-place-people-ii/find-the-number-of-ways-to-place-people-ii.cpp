class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const vector<int>& a,const vector<int>& b){
            if(a[0]==b[0]){
               return a[1]<b[1];
            }
            else return  a[0]>b[0];
        });
         int ans=0;
        for(int i=0;i<points.size()-1;i++){
            int y_maxi = points[i][1];
            int y_mini=INT_MAX;
            for(int j=i+1;j<points.size();j++){
                int ycurr = points[j][1];
                if(ycurr>=y_maxi && y_mini>ycurr){
                    ans++;
                    y_mini = ycurr;
                    if(y_maxi==ycurr)break;
                }
            }
        }
        return ans;
    }
};