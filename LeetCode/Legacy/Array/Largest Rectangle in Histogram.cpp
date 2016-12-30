class Solution {
public:
    struct tempstack{
        int height;
        int width;
    };

    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0){
            return 0;
        }
        if(heights.size()==1){
            return heights[0];
        }
        
        int max = 0;
        vector<tempstack> tstack;
        
        for(int i=0;i<heights.size();i++){
            tempstack currentelement;
            currentelement.height = heights[i];
            currentelement.width = 1;
            while(tstack.size()!=0&&currentelement.height<=tstack.back().height){
                int temp = tstack.back().width;
                tstack.pop_back();
                if(tstack.size()==0 || currentelement.height>tstack.back().height){
                    currentelement.width += temp;
                    break;
                }
                else{
                    tstack.back().width += temp;
                    if(tstack.back().height*tstack.back().width>=max){
                        max = tstack.back().height*tstack.back().width;
                    }
                }
            }
            if(currentelement.height*currentelement.width>=max){
                max = currentelement.height*currentelement.width;
            }
            tstack.push_back(currentelement);
        }
        
        int temp = 0;
        while(tstack.size()!=0){
            tstack.back().width += temp;
            if(tstack.back().height*tstack.back().width>=max){
                max = tstack.back().height*tstack.back().width;
            }
            temp = tstack.back().width;
            tstack.pop_back();
        }
        
        return max;
        
    }
};