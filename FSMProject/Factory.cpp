//
//  Factory.cpp
//  FSMProject
//
//  Created by fengkai on 2017/7/14.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#include "PCH.h"

BaseGameEntityFactory* BaseGameEntityFactory::GetIntance()
{
    static BaseGameEntityFactory* m_instance;
    if (m_instance==nullptr)
    {
        m_instance = new BaseGameEntityFactory();
    }
    return m_instance;
}

BaseGameEntity* BaseGameEntityFactory::CreateBaseEnity(const std::string &className)
{
    BaseGameEntity* newClass = nullptr;
    if (className == "Troll")
    {
        newClass = new Troll(1);
    }
    return newClass;
}
