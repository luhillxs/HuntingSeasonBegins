#include <iostream>
#include <deque> 
#include <algorithm> 
#include <stdexcept>

using namespace std; 

void print(int num)  
{  
    cout << num << " ";  
}  


int main() {
    deque<int> v;
    deque<int>::iterator iv;
    
    cout << "=========Init=========" <<endl;
    v.assign(10,2);
    cout << v.size() << endl;
    cout << endl;
    /*
    10
    */
    
    cout << "=========Insert=========" <<endl;
    v.push_front(666);
    for(int i = 0; i < 10; i++)
      v.push_back(i);
    for_each(v.begin(),v.end(),print);
    cout << endl;
    v.insert(v.begin()+3,99);
    v.insert(v.end(),99);
    for_each(v.begin(),v.end(),print);
    cout << endl;
    /*
    666 2 2 2 2 2 2 2 2 2 2 0 1 2 3 4 5 6 7 8 9 
    666 2 2 99 2 2 2 2 2 2 2 2 0 1 2 3 4 5 6 7 8 9 99 
    */
    
    cout << "=========Iterate=========" <<endl;
    for_each(v.rbegin(),v.rend(),print);
    cout << endl;
    for(iv = v.begin(); iv != v.end(); ++iv)
      cout << *iv << " ";
    cout << endl;
    /*
    99 9 8 7 6 5 4 3 2 1 0 2 2 2 2 2 2 2 2 99 2 2 666 
    666 2 2 99 2 2 2 2 2 2 2 2 0 1 2 3 4 5 6 7 8 9 99 
    */
    
    cout << "=========Remove=========" <<endl;
    v.erase(v.begin() + 3);
    for_each(v.begin(),v.end(),print);
    cout << endl;
    v.insert(v.begin()+3,99);
    v.erase(v.begin(), v.begin() + 3); // 第二个参数不删除 
    for_each(v.begin(),v.end(),print);
    cout << endl;
    v.pop_front();
    v.pop_back();
    for_each(v.begin(),v.end(),print);
    cout << endl;
    /*
    666 2 2 2 2 2 2 2 2 2 2 0 1 2 3 4 5 6 7 8 9 99 
    99 2 2 2 2 2 2 2 2 0 1 2 3 4 5 6 7 8 9 99
    2 2 2 2 2 2 2 2 0 1 2 3 4 5 6 7 8 9 
    */
    
    cout << "=========Check=========" <<endl;
    cout << v.front() << endl;
    cout << v.back() << endl;
    /*
    2
    9
    */
    
    //危险的做法，但一般我们就像访问数组那样操作就行 
    for(int i = 15; i < 25;i++)
      cout << "Element " << i << " is " << v[i] <<endl;
    cout << endl;
    cout << "安全的做法:" <<endl;
    int i;
    try{ 
        for(int i = 15; i < 25;++i)
          cout << "Element " << i << " is " << v.at(i) <<endl;
    }
    catch(out_of_range err){ //#include <stdexcept>
      cout << "out_of_range at " << i << endl;
    }
    cout << endl;
    /*
    Element 15 is 7
    Element 16 is 8
    Element 17 is 9
    Element 18 is 99
    Element 19 is 0
    Element 20 is 0
    Element 21 is 0
    Element 22 is 0
    Element 23 is 0
    Element 24 is 0

安全的做法:
Element 15 is 7
Element 16 is 8
Element 17 is 9
out_of_range at 32766
    */
    
    cout << "=========Clear=========" <<endl;
    v.clear();
    cout << v.size() << endl;
    cout << endl;
    /*
    0
    */
    
    return 0;
}