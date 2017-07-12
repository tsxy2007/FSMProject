//
//  NotificationCenter.cpp
//  FSMProject
//
//  Created by fengkai on 2017/7/12.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#include "PCH.h"
typedef  std::list<NotificationObserver*>::iterator observerIterator;
NotificationObserver::NotificationObserver(BaseGameEntity* target,SelCalFunc selector,const std::string& name , BaseGameEntity* sender) : _target(target) , _selector(selector) , _name(name),_sender(sender)
{
    
}

NotificationObserver::~NotificationObserver()
{
    cout<<"~NotificationObserver release"<<endl;
}

void NotificationObserver::performSelector(BaseGameEntity *sender)
{
    if (_target)
    {
        if (sender)
        {
            ( _target->*_selector )(sender);
        }
        else
        {
            (_target->*_selector)(_sender);
        }
    }
    
}


NotificationCenter::NotificationCenter()
{
    
}

NotificationCenter::~NotificationCenter()
{
    DELETE_LIST(std::list<NotificationObserver*>,_observers);
}

static NotificationCenter* m_instance = nullptr ;

NotificationCenter * NotificationCenter::getInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new NotificationCenter();
    }
    return  m_instance;
}

void NotificationCenter::addObserver(BaseGameEntity *target, SelCalFunc selector, const std::string &name, BaseGameEntity *sender)
{
    if (observerExisted(target, name, sender))
        return;
    NotificationObserver* observer = new NotificationObserver(target,selector,name,sender);
    if (observer)
        _observers.push_back(observer);
}

void NotificationCenter::postNotification(const std::string &name,BaseGameEntity* sender )
{
    for (std::list<NotificationObserver*>::iterator it = _observers.begin(); it != _observers.end(); it++ )
    {
        NotificationObserver* obj = (*it);
        if (obj == nullptr)
            continue;
        if ( obj->GetName( ) == name  )
        {
            obj->performSelector(sender);
        }
    }
}

void NotificationCenter::postNotification(const std::string &name)
{
    postNotification(name,nullptr);
}

bool NotificationCenter::observerExisted(BaseGameEntity *target, const std::string &name, BaseGameEntity *sender)
{
    for (observerIterator it = _observers.begin(); it != _observers.end(); it++)
    {
        NotificationObserver* obj = (*it);
        if (obj == nullptr)
            continue;
        if (obj->GetTarget() == target && obj->GetName() == name && obj->GetSender() == sender )
            return true;
    }
    return false;
}

void NotificationCenter::removeObserver(BaseGameEntity *target, const std::string &name)
{
    for (observerIterator it = _observers.begin(); it != _observers.end(); it++)
    {
        NotificationObserver* obj = (*it);
        if (obj == nullptr)
            continue;
        if (obj->GetTarget() == target && obj->GetName() == name)
        {
            it = _observers.erase(it);
            delete obj;
        }
        
    }
}

int NotificationCenter::removeAllObserver(BaseGameEntity *target)
{
    int i = 0;
    for (observerIterator it = _observers.begin(); it != _observers.end(); it++)
    {
        NotificationObserver* obj = (*it);
        if (obj == nullptr)
            continue;
        if (obj->GetTarget() == target)
        {
            i++;
            it = _observers.erase(it);
            delete (obj);
        }
    }
    return i;
}
