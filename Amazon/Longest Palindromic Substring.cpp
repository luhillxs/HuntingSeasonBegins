class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        
        int maxLength = 1;
        int left = 0;
        
        int i = 0;
        while(i < s.size()){
            if(maxLength > ( s.size() - 1 - i ) * 2 + 1)
                break;
                
            int j = i - 1, k = i + 1, length = 1;
            while(k < s.size() && s.at(k) == s.at(i)) // Skip duplications
                ++k;
            i = k;
            while(j >= 0 && k < s.size() &&  s.at(j) == s.at(k)){ // Expand left and right
                ++k;
                --j;
            }
            
            length = k -j -1;
                
            if(length > maxLength){
                left = j + 1;
                maxLength = length;
            }
        }
        
        return s.substr(left, maxLength);
    }
};