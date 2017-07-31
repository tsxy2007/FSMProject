//
//  Observer.cpp
//  FSMProject
//
//  Created by fengkai on 2017/7/31.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#include "PCH.h"

void Observer::addObserver(Subject_Ob *observer)
{
    std::vector<Subject_Ob*>::iterator it = std::find(m_observers.begin(), m_observers.end(), observer);
    if (it != m_observers.end())
        return;
    m_observers.push_back(observer);
}

void Observer::removeObserver(Subject_Ob *observer)
{
    std::vector<Subject_Ob*>::iterator it = std::find(m_observers.begin(), m_observers.end(), observer);
    if (it == m_observers.end())
        return;
    m_observers.erase(it);
}

void Observer::notify()
{
    typedef std::vector<Subject_Ob*>::iterator iterator_suboject;
    for (iterator_suboject it = m_observers.begin(); it != m_observers.end(); it++)
    {
        Subject_Ob* observer = (Subject_Ob*)(*it);
        observer->update();
    }
}
