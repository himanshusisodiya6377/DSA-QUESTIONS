/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* solve(vector<vector<int>>&grid,int rs,int rend,int cs,int cend){
        bool same=true;
        int value=grid[rs][cs];
        for(int i=rs;i<=rend && same;i++){
            for(int j=cs;j<=cend;j++){
                if(grid[i][j]!=value){
                    same=false;
                    break;
                }
            }
        }

        Node*c;

        if(same){
            c=new Node(value,true);
            // return c;
        }
        else{
            c=new Node(true,false);
             int rm = (rs + rend) / 2;
             int cm = (cs + cend) / 2;
            c->topLeft=solve(grid,rs,rm,cs,cm);
            c->topRight=solve(grid,rs,rm,cm+1,cend);
            c->bottomLeft=solve(grid,rm+1,rend,cs,cm);
            c->bottomRight=solve(grid,rm+1,rend,cm+1,cend);
        }

        return c;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        return solve(grid,0,n-1,0,n-1);
    }
};