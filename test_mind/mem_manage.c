////
//// Created by joan on 19-5-9.
////
//
//#include <iostream>
//#include <vector>
//#include <cstring>
//
//using namespace std;
//
//void* operator new(size_t size)
//{
//  void *p = malloc(size);
//  return p;
//}
//
//
//void operator delete(void *p) _GLIBCXX_USE_NOEXCEPT
//{
//  free(p);
//}
//
//
//class TestClass
//{
//public:
//    void* operator new(size_t size);
//    void operator delete(void* p);
//    //...
//};
//
//void *TestClass::operator new(size_t size)
//{
//  void *p = malloc(size); //replace this with alternative allocator
//  return p;
//}
//
//
//void TestClass::operator delete(void* p)
//{
//  free(p);  //replace with alternative allocator
//}
//
//
////class TestClass
////{
////public:
////    void* operator new[](size_t size);
////    void operator delete[](void *p);
////    //...
////};
////
////
////void *TestClass::operator new[](size_t size)
////{
////  void *p = malloc(size);
////  return p;
////}
////
////
////void TestClass::operator delete[](void* p)
////{
////  free(p);
////}
//
////
////int main(void)
////{
////  TestClass *p = new TestClass[10];
////  //...
////  delete[] p;
////}
//
//
//
//
//
//
//void GetMemory(char* p, int num)
//{
//    p = static_cast<char *>(malloc(sizeof(char)* num));
//}
//
//void Test(void)
//{
//    char *str = NULL;
//    GetMemory(str, 100);    //str 仍然为NULL
//    strcpy(str, "hello");   //运行错误
//}
//
//
//
//void GetMemory2(char** p, int num)
//{
//    *p = static_cast<char *>(malloc(sizeof(char)* num));
//}
//
//void Test2(void)
//{
//    char *str = NULL;
//    GetMemory2(&str, 100);    //注意参数是&str，而不是str
//    strcpy(str, "hello");
//    cout << str << "\n";
//    free(str);
//}
//
//
//char* GetMemory3(int num)
//{
//    char* p = static_cast<char *>(malloc(sizeof(char)*num));
//    return p;
//}
//
//
//void Test3()
//{
//    char *str = NULL;
//    str = GetMemory3(100);
//    strcpy(str, "hello");
//    cout << str << endl;
//    free(str);
//}
//
//
////char *GetString(void)
////{
////    char p[] = "hello world";
////    return p;   //编译器提出警告
////}
////
////
////void Test4(void)
////{
////    char *str = NULL;
////    str = GetString();  //str的内容是垃圾
////    cout << str << "\n";
////}
//
//
//const char *GetString2(void)
//{
//    const char* p = "hello world";
//    return p;
//}
//
//
//void Test5(void)
//{
//    const char *str = NULL;
//    str = GetString2();
//    cout << str << "\n";
//}
//
//
//
//class Point3d
//{
//public:
//    float x;
//    static std::vector<Point3d*> *freeList;
//    float y;
//    static int chunksize;
//    static const int other = 100;
//    float z;
//public:
//    //...
////    Point3d(){this->x = 0, this->y = 0, this->z = 0;}
//};
//
//int Point3d::chunksize = 250;
//const int Point3d::other;
//
//
//template<class class_type, class data_type1, class data_type2>
//const char* access_order(data_type1 class_type::*mem1, data_type2 class_type::*mem2)
//{
//    assert(mem1 != mem2);
//    std::cout << "member1 offset: " << *reinterpret_cast<unsigned int*>(&mem1) << "\n";
//    std::cout << "member2 offset: " << *reinterpret_cast<unsigned int*>(&mem2) << "\n";
//    return *reinterpret_cast<unsigned int*>(&mem1) < *reinterpret_cast<unsigned int*>(&mem2) ? "member 1 occurs first" : "member 2 occurs first";
//}
//
//
//char *p = NULL;
//char * str = static_cast<char*>(malloc(100));
//
//class A
//{
//public:
//    void Func(void){ cout << "Func of class A" << "\n"; }
//};
//
//
////void Test(void)
////{
////    A *p;
////    {
////        A a;
////        p = &a;    //注意a的生命期
////    }
////    p->Func();  //p是野指针
////}
////
////
////void Func(char a[100])
////{
////    cout << sizeof(a) << "\n";   //4字节而不是100字节
////}
//
//
//class Obj{
//public:
//    Obj(void)
//    {
//        cout << "Initialization" << endl;
//    }
//    ~Obj(void)
//    {
//        cout << "Destroy" << endl;
//    }
//
//    void Initialize(void)
//    {
//        cout << "Initialization" << endl;
//    }
//
//    void Destroy(void)
//    {
//        cout << "Destroy" << endl;
//    }
//};
//
//
//void UseMallocFree(void)
//{
//    Obj *a = static_cast<Obj*>(malloc(sizeof(Obj))); //申请动态内存
//    a->Initialize();
//    //...
//    a->Destroy();   //清除工作
//    free(a);    //释放内存
//}
//
//
//void UseNewDelete(void)
//{
//    Obj *a = new Obj;   //申请动态内存并且初始化
//    //...
//    delete a;   //清除并且释放内存
//}
//
//
//void Func1(void)
//{
//    A *a = new A;
//    if(a == NULL)
//    {
//        return ;
//    }
//}
//
//
//
//
//void Func2(void)
//{
//    A *a = new A;
//    if(a == NULL)
//    {
//        cout << "Memory Exhausted" << endl;
//        exit(1);
//    }
//}
//
//
//
//class CritSect{
//    friend class Lock;
//
//public:
//    CritSect() { InitializeCriticalSection(&_critSection); }
//    ~CritSect() { DeleteCriticalSection(&_critSection); }
//
//private:
//    void Acquire()
//    {
//        EnterCriticalSection(&_critSection);
//    }
//    void Release()
//    {
//        LeaveCriticalSection(&_critSection);
//    }
//
//    CRITICAL_SECTION _critSection;
//};
//
//
//
//
//class Lock
//{
//public:
//    Lock(CritSect& critSect): _critSect(critSect)
//    {
//        _critSect.Acquire();
//    }
//
//    ~Lock()
//    {
//        _critSect.Release();
//    }
//
//private:
//    CritSect& _critSect;
//};
//
//
//void Shared::Act() throw (char *)
//{
//    Lock lock(_critSect);
//    //perform action  -- may throw
//    //automatic destructor of lock
//}
//
//
//template <typename T>
//class SmartPointer
//{
//public:
//    SmartPointer(SmartPointer<T>& ptr);
//    void operator=(SmartPointer<T>& ptr);
//
//    ~SmartPointer(){ delete m_p;}
//    T* operator->(){ return m_p;}
//    T const *operator->() const { return m_p;}
//
//    T* Release();
//protected:
//    SmartPointer():m_p(0) {}
//    explicit SmartPointer(T* p): m_p(p){}
//
//private:
//    T * m_p;
//};
//
//template <typename T>
//T* SmartPointer<T>::Release()
//{
//    T *pTmp = m_p;
//    m_p = 0;
//    return pTmp;
//}
//
//template <typename T>
//SmartPointer<T>::SmartPointer(SmartPointer<T> &ptr)
//{
//    m_p = ptr.Release();
//}
//
//
//template <typename T>
//void SmartPointer<T>::operator=(SmartPointer<T> &ptr)
//{
//    if(m_p != ptr.m_p)
//    {
//        delete m_p;
//        m_p = ptr.Release();
//    }
//}
//
//class Stack
//{
//public:
//    enum {maxStack = 3};
//
//    Stack():m_top(0){}
//
//    void Push(SmartPointer<Item> &item) throw(char *)
//    {
//        if(m_top >= maxStack)
//            throw "Stack Overflow";
//        m_arr[m_top++] = item;
//    }
//
//    SmartPointer<Item> Pop()
//    {
//        if(m_top == 0)
//            return SmartPointer<Item>();
//        return m_arr[--m_top];
//    }
//
//private:
//    int m_top;
//    SmartPointer<Item> m_arr[maxStack];
//};
//
//void Stack::Push(SmartPointer<Item> & item) throw(char *)
//{
//    if(_top == MaxStack)
//        throw "Stack overflow";
//    __arr[__top++] = item.Release();
//}
//
//
//
//class SmartItem: public SmartPointer<Item>
//{
//public:
//    explicit SmartItem(int i)
//    : SmartPointer<Item>(new Item(i)){}
//};
//
//
//class RefCounted
//{
//public:
//    RefCounted():m_count(1){}
//    int GetRefCount() const {return m_count;}
//    void IncRefCount() {m_count++;}
//    int DecRefCount(){return --m_count;}
//
//private:
//    int m_count;
//};
//
//template <typename T>
//class RefPtr
//{
//public:
//    RefPtr(T* p):m_p(p) {}
//
//    RefPtr(RefPtr<T>& p)
//    {
//        m_p = p.m_p;
//        m_p->IncRefCount();
//    }
//
//    ~RefPtr()
//    {
//        if(m_p->DecRefCount() == 0)
//        {
//            delete m_p;
//        }
//    }
//
//private:
//    T * m_p;
//};
//
//
////class Link
////{
////    //...
////private:
////    std::auto_ptr<Link> m_next;
////};
////
////// 最好的方法是，将连接控制封装到一个能够进行资源转换的类中。
////// 对于双链表呢？安全的做法是指明一个方向，如forward：
////class DoubleLink
////{
////    //...
////private:
////    DoubleLink* m_prev;
////    std::auto_ptr<Link> m_next;
////};
//
//
//
//template <typename T>
//class CyclePtr
//{
//public:
//    CyclePtr(T* p):m_p(p), m_isBeingDeleted(false){}
//    ~CyclePtr()
//    {
//        if(!m_p->IsBeingDeleted())
//        {
//            delete p;
//        }
//
//    }
//
//    void Set(T *p)
//    {
//        m_p = p;
//    }
//
//    bool IsBeingDeleted() const
//    {
//        return m_isBeingDeleted;
//    }
//
//private:
//    T * m_p;
//    bool m_isBeingDeleted;
//};
//
//
//
//
//
//
//
//
//
//
//
//
