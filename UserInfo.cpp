#include "UserInfo.h"

#include <string>
#include <iostream>

using std::string;

using std::cout;
using std::endl;


//业务对象
class IUserBO
{
public:
    virtual void setUserId(const string& strUserId)
    {
        cout << "IUserBO: setUserId" << endl;
    }
    virtual string getUserId() {return "";}

    virtual void setUserName(const string& strUserId)
    {
        cout << "IUserBO: setUserName" << endl;
    }
    virtual string getUserName() { return ""; }

    virtual void setPassWord(const string& strUserId)
    {
        cout << "IUserBO: setPassWord" << endl;
    }
    virtual string getPassWord() { return ""; }

};

//业务行为
class IUserBiz
{
public:
    virtual bool changePassWord() 
    {
        cout << "IUserBiz: changePassWord" << endl;
        return true; 
    }
    virtual bool deleteUser(IUserBO userBO) 
    { 
        cout << "IUserBiz: deleteUser" << endl;
        return true; 
    }

    virtual void mapUser(IUserBO userBO) 
    { 
        cout << "IUserBiz: mapUser" << endl;
        return; 
    }

    virtual bool addOrg(IUserBO userBO, int orgID) 
    {
        cout << "IUserBiz: addOrg" << endl;
        return true; 
    }

    virtual bool addRole(IUserBO userBO, int orgID) 
    {
        cout << "IUserBiz: addRole" << endl;
        return true; 
    }
};

class IUserInfo : public IUserBO, public IUserBiz
{
public:
    IUserInfo() {};
    virtual ~IUserInfo() {};


};

class UserInfo : public IUserInfo
{

public:

    //业务对象
    void setUserId(const string& strUserId)
    {
        cout << "UserInfo: setUserId" << endl;
        m_strUserId = strUserId;
    }
    string getUserId() { return m_strUserId; }

    void setUserName(const string& strUserName) 
    { 
        cout << "UserInfo: setUserName" << endl;
        m_strUserName = strUserName; 
    }
    string getUserName() { return m_strUserName; }

    void setPassWord(const string& strPassWord) 
    { 
        cout << "UserInfo: setPassWord" << endl;
        m_strPassWord = strPassWord; 
    }
    string getPassWord() { return m_strPassWord; }

    //业务行为
    bool changePassWord() 
    { 
        cout << "UserInfo: changePassWord" << endl;
        return true; 
    }

    bool deleteUser(IUserBO* userBO) 
    {
        cout << "UserInfo: deleteUser" << endl;
        return true; 
    }

    void mapUser(IUserBO* userBO) 
    { 
        cout << "UserInfo: mapUser" << endl;
        return ; 
    }

    bool addOrg(IUserBO* userBO, int orgID) 
    {
        cout << "UserInfo: addOrg" << endl;
        return true; 
    }
    bool addRole(IUserBO* userBO, int orgID) 
    {
        cout << "UserInfo: addRole" << endl;
        return true; 
    }

private:
    string  m_strUserId;
    string  m_strUserName;
    string  m_strPassWord;
};

class Animal
{
public:
    virtual void makeSound() = 0;
};

class Dog :public Animal
{
public:
    void makeSound() 
    {
        bark();
    }

    void bark() 
    {
        cout << "汪汪叫" << endl;
    }
};

class Cat :public Animal
{
    void makeSound()
    {
        meow();
    }

    void meow()
    {
        cout << "喵喵叫" << endl;
    }

};

class FlyBehavior
{
public:
    virtual void fly() = 0;

};

class FlyWithRocket :public FlyBehavior
{
    void fly()
    {
        cout << "用火箭动力飞行" << endl;
    }

};

class QuackBehavior
{
public:
    virtual void quack() = 0;

};

class Quack :public  QuackBehavior
{
    void quack()
    {
        cout << "鸭子呱呱叫" << endl;
    }
};

class Squeak :public  QuackBehavior
{
    void quack()
    {
        cout << "橡皮鸭子吱吱叫" << endl;
    }
};

class MuteQuack :public  QuackBehavior
{
    void quack()
    {
        cout << "什么都不做, 不会叫" << endl;
    }
};



class Duck
{
protected:
    FlyBehavior*     m_fly;
    QuackBehavior*   m_quack;

public:

    Duck(FlyBehavior* fly, QuackBehavior* quack)
    :m_fly(fly)
    ,m_quack(quack)
    {}

    virtual void swim() = 0;

    virtual void display() = 0;

    void performFly() 
    {
        m_fly->fly(); 
    }

    void performQuack() 
    {
        m_quack->quack();
    }


};

class MallardDuck :public Duck
{
public:

    MallardDuck()
    :Duck::Duck(new FlyWithRocket(), new Quack())
//     :m_fly(new FlyWithRocket())
//     ,m_quack(new Quack())
    {
        m_fly = new FlyWithRocket();
        m_quack = new Quack();
    }

    void swim()
    {
        cout  << "游泳" << endl;
    }

    void display()
    {
        cout << "外观是绿头" << endl;
    }

};



// int main()
// {
//     //针对实现编程
//     Dog* dog = new Dog();
//     dog->bark();
// 
//     Animal* animal = new Dog();
//     animal->makeSound();
// 
//     animal = new Cat();
//     animal->makeSound();
// 
//     Duck* duck = new MallardDuck();
//     duck->performFly();
//     duck->performQuack();
// 
//     cout << "Hello World !!!" << endl;
//     std::shared_ptr<IUserInfo> userInfo(new UserInfo());
// 
//     IUserBO*  userBO = dynamic_cast<IUserBO*>(userInfo.get());
//     userBO->setPassWord("abc");
// 
//     std::shared_ptr<IUserBO> userBO_V2(new IUserBO());
//     userBO_V2->setPassWord("iii");
// 
//     IUserBiz*  userBiz = dynamic_cast<IUserBiz*>(userInfo.get());
//     userBiz->changePassWord();
// 
//     std::shared_ptr<IUserBiz> userBiz_V2(new IUserBiz());
//     userBiz_V2->changePassWord();
// 
// }
