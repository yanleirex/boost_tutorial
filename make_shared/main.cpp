//
// Created by yanlei on 16-9-14.
//

#include <iostream>
#include <string>

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

using namespace std;

class Base
{
public:
    Base(const std::string& name) : _name(name)
    {
        cout<<_name.c_str()<<":~Base()"<<endl;
    }

    virtual void toString() const {
        cout<<_name.c_str()<<endl;
    }
protected:
    std::string _name;
};

class SubClass:public Base{
public:
    SubClass(const std::string& name, uint x=0) : Base(name)
    {
        cout<<_name.c_str()<<":SubClass()"<<endl;
        cout<<"x= "<<x<<endl;
    }

    virtual ~SubClass()
    {
        cout<<_name.c_str()<<":~SubClass()"<<endl;
    }

    void toString() const
    {
        cout<<_name.c_str()<<endl;
    }
};

int main()
{
    cout<<"make_shared: "<<endl;
    //shared_ptr很好的消除了显式的delete调用
    //boost提供了一个自由工厂函数make_shared<T>()，用来显式的消除new调用
    //make_shared和shared_ptr配合使用，代码中不需要new和delete
    boost::shared_ptr<Base> sp = boost::make_shared<Base>("Base 1");
    sp->toString();

    boost::shared_ptr<Base> sp1 = boost::make_shared<SubClass>("SubClass 1");
    sp1->toString();

    //make_shared 比直接创建shared_ptr快，它仅仅分配一次内存，消除了shred_ptr构造时的开销
    //time: sp2>sp3
    boost::shared_ptr<SubClass> sp2 = boost::shared_ptr<SubClass>(new SubClass("SubClass 2"));
    boost::shared_ptr<SubClass> sp3 = boost::make_shared<SubClass>("SubClass 3");

    //make_shared limited your to a maximum 9 paramaters
    boost::shared_ptr<SubClass> sp4 = boost::make_shared<SubClass>("SubClass 4");

    sp2->toString();
    sp3->toString();

    return 0;
}