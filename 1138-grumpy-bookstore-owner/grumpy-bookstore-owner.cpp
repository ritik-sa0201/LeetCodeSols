class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        vector<int>a = customers;
         int early=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                early+=a[i];
                a[i]=0;
            }
        }

        int i=0,j=0,sum=0,ans=INT_MIN;
        while(j<minutes){
            sum+=a[j];
            j++;
        }
        ans = max(ans,sum);
        while(j<n){
            sum-=a[i];
            i++;
            sum+=a[j];
            j++;
            ans = max(ans,sum);
        }
      return early+ans;
    }
};