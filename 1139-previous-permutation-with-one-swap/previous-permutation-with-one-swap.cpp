#include <vector>
using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int i = n - 1;
        
  
        while (i > 0 && arr[i - 1] <= arr[i]) {
            i--;
        }
        if (i == 0) return arr; 
        
        int j=i;
        int min_i=j;
        int min_el=arr[j];

        for(j;j<n;j++){
            if(min_el<arr[j] && arr[j]<arr[i-1]){
                min_i=j;
                min_el=arr[j];
            }
        } 
     
        swap(arr[i - 1], arr[min_i]);
        return arr;
    }
};
