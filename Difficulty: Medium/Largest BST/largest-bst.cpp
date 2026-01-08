/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
       int ans=0;
    // max in left  min in right
    pair<pair<int,int>,int> solve(Node*root){

        if (!root) 
            return {{INT_MIN, INT_MAX}, 0};
        auto p=solve(root->left);
        auto q=solve(root->right);

        if (root->data > p.first.first && root->data < q.first.second) {
            int sz = p.second + q.second + 1;
            ans = max(ans, sz);

            return {
                {
                    max(root->data, q.first.first),
                    min(root->data, p.first.second)
                },
                sz
            };
        }
//         else if(root->left){
//               if(root->val>p.first.first){
//                ans=max(ans,p.second+1);
//                return {
//     {
//         std::max({root->val, p.first.first}),
//         std::min({root->val, p.first.second})
//     },
//     p.second  + 1
// };
//         }
//         }
//         else{
//              if(q.first.second>root->val){
//              ans=max(ans,q.second+1);
//                   return {
//     {
//         std::max({root->val, q.first.first}),
//         std::min({root->val,q.first.second})
//     },
//      q.second + 1
// };
//         }
//         }

       

         return {{INT_MAX, INT_MIN}, 0};
    }
    int largestBst(Node *root) {
        // Your code here
         solve(root);
        return ans;
    }
};