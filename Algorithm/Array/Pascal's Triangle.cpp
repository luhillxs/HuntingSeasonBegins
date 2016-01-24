/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        vector<int> curRow;
        int i,j;
        if(numRows >= 1){ //outside for loop: in order to judge once, not every loop
            curRow.push_back(1);
            pascal.push_back(curRow);
        }
        for(i=1;i<numRows;i++){
            curRow.clear();
            curRow.push_back(1);
            for(j=1;j<i;j++){
                curRow.push_back(pascal[i-1][j-1]+pascal[i-1][j]);
            }
            curRow.push_back(1);
            pascal.push_back(curRow);
        }

        return pascal;
    }
    
};