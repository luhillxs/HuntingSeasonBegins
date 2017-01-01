#include <iostream>
#include <vector>
#include <algorithm> 
#include <stdexcept>  

using namespace std; 

void print(int num)  
{  
    cout << num << " ";  
}  

int main() {
    vector<int> v;
    vector<int>::iterator iv;
    
    cout << "=========Init=========" <<endl;
    v.reserve(100); //设置vector最小的元素容纳数量
    v.assign(10,2); //将10个值为2的元素赋到vector中
    cout << v.capacity() << endl; 
    cout << v.size() <<endl;
    /*
    100
    10
    */
    
    cout << "=========Insert=========" <<endl;
    //注意：push_front()只适用于list和deque容器类型 
    for(int i = 0; i < 10;++i){
      v.push_back(i);
    }
    for_each(v.begin(), v.end(), print); //需要#include <algorithm> 
    cout << endl << v.size() <<endl;
    v.insert(v.begin()+3, 99);
    v.insert(v.end()-3, 99);
    /*
    2 2 2 2 2 2 2 2 2 2 0 1 2 3 4 5 6 7 8 9 
    20
    */
    
    cout << "=========iterate=========" <<endl;
    for_each(v.begin(), v.end(), print); 
    cout << endl;
    for_each(v.rbegin(), v.rend(), print); // 逆序迭代器逆序逆序迭代器
    cout << endl;
    for(iv = v.begin(); iv != v.end(); ++iv)
      cout << *iv << " ";
    cout << endl;
    /*
    2 2 2 99 2 2 2 2 2 2 2 0 1 2 3 4 5 6 99 7 8 9 
    9 8 7 99 6 5 4 3 2 1 0 2 2 2 2 2 2 2 99 2 2 2 
    2 2 2 99 2 2 2 2 2 2 2 0 1 2 3 4 5 6 99 7 8 9 
    */
    
    cout << "=========delete=========" <<endl;
    v.erase(v.begin()+3);
    for_each(v.begin(), v.end(), print); 
    cout << endl;
    v.insert(v.begin()+3, 99); // 复原
    for_each(v.begin(), v.end(), print);
    cout << endl;
    v.erase(v.begin(), v.begin()+3); // 删掉3个而不是4个 
    for_each(v.begin(), v.end(), print); 
    cout << endl;
    v.pop_back(); // 不能 i = v.pop_back()
    for_each(v.begin(), v.end(), print); 
    cout << endl;
    /*
    2 2 2 2 2 2 2 2 2 2 0 1 2 3 4 5 6 99 7 8 9 
    2 2 2 99 2 2 2 2 2 2 2 0 1 2 3 4 5 6 99 7 8 9 
    99 2 2 2 2 2 2 2 0 1 2 3 4 5 6 99 7 8 9
    99 2 2 2 2 2 2 2 0 1 2 3 4 5 6 99 7 8 
    */
    
    cout << "=========check=========" <<endl;
    cout << v.front() << endl; //q区分v.begin/end()
    cout << v.back() << endl;
    /*
    99
    8
    */
    
    cout << "=========clear=========" <<endl;
    v.clear();
    cout << v.capacity() << endl; 
    cout << v.size() <<endl;
    /*
    100
    0
    */
    
    //危险的做法，但一般我们就像访问数组那样操作就行  
    for (int i = 15; i < 25; i++)  
        cout << "Element " << i << " is " << v[i] << endl;  
    //安全的做法  
    int i;  
    try  
    {  
        for (i = 15; i < 25; i++)  
            cout << "Element " << i << " is " << v.at(i) << endl;  
    }  
    catch (out_of_range err)//#include <stdexcept>  
    {  
        cout << "out_of_range at " << i << endl;  
    }  
    cout << endl;
    /*
    Element 15 is 99
    Element 16 is 7
    Element 17 is 8
    Element 18 is 9
    Element 19 is 7
    Element 20 is 8
    Element 21 is 9
    Element 22 is 0
    Element 23 is 0
    Element 24 is 0
    out_of_range at 15
    */
    
    return 0;
}