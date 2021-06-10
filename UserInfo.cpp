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


// int main()
// {
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
