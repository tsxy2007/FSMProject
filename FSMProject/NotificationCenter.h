//
//  NotificationCenter.hpp
//  FSMProject
//
//  Created by fengkai on 2017/7/12.
//  Copyright © 2017年 fengkai. All rights reserved.
//  通知模式

#ifndef NotificationCenter_hpp
#define NotificationCenter_hpp

class BaseGameEntity;
typedef void (BaseGameEntity::*SelCalFunc)( BaseGameEntity*);
#define CC_CALLFUNCO_SELECTOR(_SELECTOR) static_cast<SelCalFunc>(&_SELECTOR)
class NotificationObserver {
    
private:
    BaseGameEntity* _target;
    SelCalFunc  _selector;
    BaseGameEntity* _sender;
    std::string _name;
public:
    NotificationObserver(BaseGameEntity* target,SelCalFunc selector,const std::string& name , BaseGameEntity* sender);
    ~NotificationObserver();
    void performSelector(BaseGameEntity* sender);
    std::string GetName(){return _name;}
    BaseGameEntity* GetTarget(){return _target;}
    SelCalFunc GetSelector(){return _selector;}
    BaseGameEntity* GetSender(){return _sender;}
};

class NotificationCenter {
private:
    std::list<NotificationObserver*> _observers;
    
public:
    NotificationCenter();
    ~NotificationCenter();
    static NotificationCenter* getInstance();
    void addObserver(BaseGameEntity* target,SelCalFunc selector,const std::string& name , BaseGameEntity* sender);
    void postNotification(const std::string& name,BaseGameEntity* sender );
    void postNotification(const std::string& name);
    bool observerExisted(BaseGameEntity* target,const std::string& name , BaseGameEntity* sender);
    void removeObserver(BaseGameEntity* target , const std::string& name);
    int removeAllObserver( BaseGameEntity* target );
};

#endif /* NotificationCenter_hpp */
