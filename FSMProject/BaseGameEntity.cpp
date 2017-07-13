//
//  BaseGameEntity.cpp
//  FSMProject
//
//  Created by fengkai on 2017/7/6.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#include "PCH.h"

BaseGameEntity::BaseGameEntity(int id)
{
    SetID(id);
}

BaseGameEntity::~BaseGameEntity()
{
    
}

int BaseGameEntity::ID()const
{
    return m_ID;
}

void BaseGameEntity::SetID(int val)
{
    m_ID = val;
}

void BaseGameEntity::Run()
{
    
}
