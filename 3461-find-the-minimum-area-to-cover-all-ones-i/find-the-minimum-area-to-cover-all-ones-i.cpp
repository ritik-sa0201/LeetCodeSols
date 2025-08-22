class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int l = grid[0].size()-1, r=0;
        int u = grid.size()-1, d = 0;
        for(int ir=0; ir<grid.size(); ir++)
            for(int ic=0; ic<grid[0].size(); ic++){
                if(grid[ir][ic]){
                    l = min(l, ic);
                    r = max(r, ic);
                    u = min(u, ir);
                    d = max(d, ir);
                }
            }
        return l>r? 0 : (r-l+1)*(d-u+1);
    }
};