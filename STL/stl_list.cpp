#include <iostream>
#include <list>
#include <algorithm> 

using namespace std; 

void print(int num)  
{  
    cout << num << " ";  
}  

bool IsOdd(int i)  
{  
    return ((i & 1) == 1);  
}  

int main() {
    list<int> v;
    list<int>::iterator iv;
    
    cout << "=========Init=========" <<endl;
    v.assign(10,2); // 将10个值为2的元素赋到list中
    // cout<< v.capacity() <<endl; // list无 capacity
    cout << v.size() <<endl; // 返回list实际含有的元素数量
    cout << endl;
    /*
    10
    */
    
    cout << "=========Insert=========" <<endl;
    v.push_front(666);
    for(int i=0; i < 10; i++)
      v.push_back(i);
    // 以下是之后补充的，两步没有运行过
    v.insert(v.begin() , 99); // 不能+和-了  
    v.insert(v.end() , 99);
    
    cout << "=========Iterate=========" <<endl;
    for_each(v.begin(), v.end(), print);
    cout << endl;
    for_each(v.rbegin(), v.rend(), print);
    cout << endl;
    for(iv = v.begin(); iv != v.end(); ++iv) // 不能使用 rbegin/rend
      cout << *iv << " ";
    cout << endl;
    v.reverse();
    for_each(v.begin(), v.end(), print);
    cout << endl;
    /*
    666 2 2 2 2 2 2 2 2 2 2 0 1 2 3 4 5 6 7 8 9
    9 8 7 6 5 4 3 2 1 0 2 2 2 2 2 2 2 2 2 2 666
    666 2 2 2 2 2 2 2 2 2 2 0 1 2 3 4 5 6 7 8 9
    9 8 7 6 5 4 3 2 1 0 2 2 2 2 2 2 2 2 2 2 666 
    */
    
    cout << "=========Sort=========" <<endl;
    v.sort(); // 为链表排序，默认是升序。
    for_each(v.begin(), v.end(), print);
    cout << endl;
    /*
    0 1 2 2 2 2 2 2 2 2 2 2 2 3 4 5 6 7 8 9 666
    */
    
    cout << "=========Remove=========" <<endl;
    v.erase(v.begin());
    for_each(v.begin(), v.end(), print);
    cout << endl;
    v.insert(v.begin(),99);
    for_each(v.begin(), v.end(), print);
    cout << endl;
    v.unique(); // 删掉链表中所有重复的元素
    for_each(v.begin(), v.end(), print);
    cout << endl;
    v.remove(2); //去掉所有含2的元素, 注意与erase的区别 
    for_each(v.begin(), v.end(), print);
    cout << endl;
    v.remove_if(IsOdd); //删掉所有奇数
    for_each(v.begin(), v.end(), print);
    cout << endl;
    v.pop_front();
    v.pop_back();
    for_each(v.begin(), v.end(), print);
    cout << endl;
    /*
    1 2 2 2 2 2 2 2 2 2 2 2 3 4 5 6 7 8 9 666
    99 1 2 2 2 2 2 2 2 2 2 2 2 3 4 5 6 7 8 9 666
    99 1 2 3 4 5 6 7 8 9 666
    99 1 3 4 5 6 7 8 9 666
    4 6 8 666 
    6 8
    */
    
    cout << "=========Check=========" <<endl;
    cout << v.front() << endl;
    cout << v.back() << endl;
    /*
    6
    8
    */
    
    cout << "=========Clear=========" <<endl;
    v.clear();
    cout << v.size() <<endl;
    for_each(v.begin(), v.end(), print); //已经clear，v.begin()==v.end()，不会有任何结果
    /*
    0
    */
    
    cout << "=========Dynamic=========" <<endl;
    list<char *> li;
    list<char *>::iterator iter;
    li.push_back("123");
    li.push_back("456");
    li.push_back("789");
    for(iter = li.begin(); iter != li.end(); ++iter)
      cout << *iter << endl;
    /*
    123
    456
    789
    */
    
    
    return 0;
}