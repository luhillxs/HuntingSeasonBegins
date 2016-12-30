/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
 */


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pascalRow(rowIndex+1,0);
        int i,j;
        
        pascalRow[0] = 1;
        pascalRow[rowIndex]=1;
        
        
        for(i=1;i<rowIndex;i++){
            pascalRow[i] = 1;
            for(j=i;j>0;j--){
                pascalRow[j] = pascalRow[j]+pascalRow[j-1];
            }
        }
        
        //mathematical method - caused overflowing when rowIndex > 30
        /*
        int boundary = ((int)rowIndex/2)+1;
        for(i=1;i<boundary;i++) { //calculation
            //pascalRow[i] = (pascalRow[i-1]*(rowIndex-i+1))/i;
        }
        
        for(i=boundary;i<=rowIndex;i++) { //mirror
            pascalRow[i] = pascalRow[rowIndex-i];
        }
        */
        
        return pascalRow;
    }
};