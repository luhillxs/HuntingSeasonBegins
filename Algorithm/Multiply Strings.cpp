class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0"){
            return "0";
        }
        
        int ptr1,ptr2,ptrr;
        string result;
        
        for(ptr2 = num2.size()-1;ptr2>=0;ptr2--){
            ptrr=num2.size()-1-ptr2;
            for(ptr1 = num1.size()-1;ptr1>=0;ptr1--){
                string temp = to_string((num1[ptr1]-'0')*(num2[ptr2]-'0'));
                temp.insert(0,"0");
                reverse(temp.begin(),temp.end());
                int nextdig = 0;
                int i;
                for(i=0;i<temp.size();i++){
                    if(result[ptrr+i]<'0')  {result.replace(ptrr+i,1,"0");}
                    int digit = temp[i] + result[ptrr+i] - 2*'0' + nextdig;
                    if(digit>9){
                        nextdig = digit/10;
                        digit = digit %10;
                    }
                    else{
                        nextdig = 0;
                    }
                    result.replace(ptrr+i,1,to_string(digit));
                }
                if(result[ptrr+i]<'0')  {result.replace(ptrr+i,1,"0");}
                result[ptrr+i] += nextdig;
                ptrr++;
            }
        }
        int i;
        for(i=result.size()-1;i>0;i--){
            if(result[i]!='0') break;
        }
        result.erase(i+1);
        // if(result[result.size()-2]=='0') result.erase(result.size()-2);
        // else if (result[result.size()-1]=='0') result.erase(result.size()-1);
        reverse(result.begin(),result.end());
        return result;
    }
};