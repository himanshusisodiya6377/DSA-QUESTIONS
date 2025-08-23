class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> s;
        long long maxi=INT_MIN;

        while (!q.empty()) {
            long long node = q.size();
            long long sum = 0;
            for (int i = 0; i < node; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                sum += tmp->val;
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
            maxi=max(maxi,sum);
            s.push_back(sum);
        }

        for(int i=0;i<s.size();i++){
            if(s[i]==maxi) return i+1;
        }

        return -1;

        // sort(s.begin(), s.end());
        
    }
};