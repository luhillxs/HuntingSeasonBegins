#include <iostream>
#include <map>  
#include <queue>
#include <vector>

using namespace std;

class Result{
  public:
    int id;
    int value;
    
    Result(int id, int value){
        this->id = id;
        this->value = value;
    }
};

map<int, double> High_Five(vector<Result> results){
    map<int, priority_queue<int, vector<int>, greater<int> > > topFive; // 小顶堆存最大5个分数，注意最后3个>之间有空格
    map<int, double> res;
    map<int, priority_queue<int, vector<int>, greater<int> > >::iterator iterMap;

    if(results.empty() || results.size() == 0)
      return res;
    
    for(int i = 0; i<results.size(); i++){
      if(results[i].value < 0) // 数据不合法，返回空map
        return res;
        
      topFive[results[i].id].push(results[i].value); 
      if(topFive[results[i].id].size() > 5)
        topFive[results[i].id].pop();
    }
    
    for(iterMap = topFive.begin(); iterMap != topFive.end(); iterMap++){
      int sum = 0;
      int count = 0;
      while(!iterMap->second.empty()){
        sum += iterMap->second.top();
        count++;
        iterMap->second.pop();
      }
      
      if(count == 0)
        res[iterMap->first] = 0;
      else
        res[iterMap->first] = (double)sum / (double)count;
    }
    
    return res;
}


// ==================Test Case==================
int main() {    
    // Result *r1 = new Result(1, -1);
    Result *r1 = new Result(1, 95);
    Result *r2 = new Result(1, 95);
    Result *r3 = new Result(1, 91);
    Result *r4 = new Result(1, 91);
    Result *r5 = new Result(1, 93);
    Result *r6 = new Result(1, 105);
    Result *r7 = new Result(2, 6);
    Result *r8 = new Result(2, 6);
    Result *r9 = new Result(2, 7);
    Result *r10 = new Result(2, 6);
    Result *r11 = new Result(2, 6);
    Result *r12 = new Result(3, 0);
    
    vector<Result> results;
    results.push_back(*r1);
    results.push_back(*r2);
    results.push_back(*r3);
    results.push_back(*r4);
    results.push_back(*r5);
    results.push_back(*r6);
    results.push_back(*r7);
    results.push_back(*r8);
    results.push_back(*r9);
    results.push_back(*r10);
    results.push_back(*r11);
    results.push_back(*r12);

    map<int, double> res = High_Five(results);
    map<int, double>::iterator iterRes;
    
    for(iterRes = res.begin(); iterRes != res.end(); iterRes++){
      cout << iterRes->first << ": " << iterRes->second << endl;
    }
}