//
//  Decorator.cpp
//  FSMProject
//
//  Created by fengkai on 2017/7/24.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#include "PCH.h"

void PropertySpeed::print()
{
    cout<< speed<<endl;
}

AddPropertySpeed::AddPropertySpeed(Property* pro) : mPro(pro)
{
    
}

std::string AddPropertySpeed::add()
{
    return "add";
}

void AddPropertySpeed::print()
{
    cout<<add()<<GetSpeed()<<endl;
}

float AddPropertySpeed::GetSpeed()
{
    if (mPro == nullptr)
    {
        return 0.0f;
    }
    return mPro->GetSpeed();
}

SubPropertySpeed::SubPropertySpeed(Property* pro):mPro(pro)
{
    
}

float SubPropertySpeed::GetSpeed()
{
    if (mPro == nullptr)
    {
        return 0.0f;
    }
    return mPro->GetSpeed();
}

std::string SubPropertySpeed::sub()
{
    return "sub";
}

void SubPropertySpeed::print()
{
    cout<<sub()<<GetSpeed()<<endl;
}
