#include <iostream>
using namespace std;

// To execute C++, please define "int main()"
int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const auto& word : words) {
    cout << word;
  }
  return 0;
}

// str1 = "apple"
// str2 = "let"
// return 2

int function(string *str1, string *str2){
  if(str1.empty()||str2.empty()||str2.size()>str1.size()){
    return NULL;
  }
  
  string *ptr1, *ptr2;
  ptr1 = str1;
  ptr2 = str2;
  int position = -1;
  for(;ptr1;ptr1++){
    string *temp;
    temp = ptr1;
    position++;
    for(ptr2 = str2;*ptr2!='/0';ptr2++){
      if(*ptr1!=*ptr2){
        break;
      }
      ptr1++;
    }
    ptr1=temp;
    if(*ptr2!='/0'){
      
    }
    else{
      return position;
    }
  }
  return NULL;
}

// str1 = aaaaaaaaaaaa
// str2 = aaaaaaaaaaab

// nums = [7, 1, 4, 1, 4, 4, 12]
// k = 1
// return [4]

// k = 2
// return [4, 1]

// k = 3
// return [4, 1, 7] (also ok: [4, 1, 12])
struct structure{
  int val;
  int times;
}


vector<int> function(vector<int> nums,int k){
  std::sort(nums.begin(),nums.end());
  vector<strucure> result;
  
  int time = 1;
  for(int i = 0;i<=nums.size();i++){
    if(i==0){
      continue;
    }
    if(nums[i]==num[i-1]){
      times++;
    }
    else{
      structure temp;
      temp.val = nums[i-1];
      temp.times = times;
      result.push_back(temp);
      times = 1;
    }
  }
  
  vector<int> ret;
  int max=0,temp;
  for(int i=k;i>0;i--){
    for(int j = 0;j<result.size();j++){
      if(result[j].times>max){
        max = result[j].times;
        temp = result[j].val;
        result.erase(result.begin()+j);
      }
    }
    ret.push_back(temp);
    max = 0;
  }
  return ret;
}



