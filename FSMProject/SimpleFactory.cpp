//
//  SimpleFactory.cpp
//  FSMProject
//
//  Created by fengkai on 2017/7/14.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#include "PCH.h"


SimpleFactory* SimpleFactory::GetIntance()
{
    static SimpleFactory* m_instance;
    if (m_instance == nullptr)
    {
        m_instance = new SimpleFactory( );
    }
    return  m_instance;
}

BaseGameEntity* SimpleFactory::CreateBaseEnity(const std::string &className)
{
    if (className == "Troll")
    {
        return new Troll(1);
    }
    
    return nullptr;
}
