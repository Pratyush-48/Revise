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
    bool check(vector<vector<int>>&grid,int x,int y,int n){
        for(int i=x;i<(x+n);i++){
            for(int j=y;j<(y+n);j++){
                if(grid[x][y]!=grid[i][j]) return false;
            }
        }
        return true;
    }
    Node* traverse(vector<vector<int>>&grid,int x,int y,int n){
        if(check(grid,x,y,n)){
            Node* ans = new Node(grid[x][y],true);
            return ans;
        }
        Node* ans = new Node(grid[x][y],false);
        ans->topLeft = traverse(grid,x,y,n/2);
        ans->topRight = traverse(grid,x,y+n/2,n/2);
        ans->bottomLeft = traverse(grid,x+n/2,y,n/2);
        ans->bottomRight = traverse(grid,x+n/2,y+n/2,n/2);
        return ans;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        Node* result = traverse(grid,0,0,n);
        return result;
    }
};