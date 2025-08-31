class Solution {
    
public:
struct node{
    int val;
    node* child[2];

    node(){
        val = 0;
        child[0]=child[1]=nullptr;
    }
};

   void insert(node* root,int val){
    node*temp = root;
    for(int i=31;i>=0;i--){
        int b = (val>>i)&1;
        if(temp->child[b]==nullptr){
            temp->child[b]=new node();
        }
        temp = temp->child[b];
    }
    temp->val = val;
   }



   int search(node* root,int num){
    if(!root)return -1;
    node* temp = root;

        for(int i=31;i>=0;i--){
            int b = (num>>i)&1;
            if(b==0){
                if(temp->child[1]!=nullptr){
                    temp = temp->child[1];
                }
                else{
                    temp = temp->child[0];
                }
            }
            else if(b==1){
                  if(temp->child[0]!=nullptr){
                    temp = temp->child[0];
                }
                else{
                    temp = temp->child[1];
                }
            }
        }
        return temp->val;
   }

    int findMaximumXOR(vector<int>& nums) {
        node* root = new node();
        for(int x : nums) insert(root,x);
        int ans = 0;
        
        for(int i=0;i<nums.size();i++){
            int p = search(root,nums[i]);
            ans = max(ans,nums[i]^p);
        }
        return ans;
    }
};