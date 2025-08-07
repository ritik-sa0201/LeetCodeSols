class Solution {
public:

    bool check(int mid,vector<int>&position,int m){
       int count = 1; 
       int last = position[0];
    
     for (int i = 1; i < position.size(); i++) {
        if (position[i] - last >= mid) {
            count++;
            last = position[i];
        }
        if (count >= m) return true; 
    }
    return false;
    }


    int maxDistance(vector<int>& position, int m) {
         sort(position.begin(),position.end());
         int n=position.size();
         int i=1,j=position[n-1]-position[0];
         int ans=0;

         while(i<=j){
            int mid = i + (j-i)/2;
            bool val = check(mid,position,m);

            if(val){
                ans = mid;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
         }
         return  ans;
    }
};