class Solution {
    bool check(vector<vector<int>>& matrix,int n,int r){
         set<int>st;
         for(int i=0;i<n;i++){
            st.insert(matrix[i][r]);
         }
         if(st.size()!=n)return false;
         st.clear();
         for(int i=0;i<n;i++){
            st.insert(matrix[r][i]);
         }
         if(st.size()!=n)return false;
return true;
    }
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int m=matrix.size();
   
        for(int i=0;i<m;i++){
           if(check(matrix,m,i)==false)return false;
        }
        return true;
    }
};