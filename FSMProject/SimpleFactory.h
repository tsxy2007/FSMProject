//
//  SimpleFactory.hpp
//  FSMProject
//  简单工厂模式
//  Created by fengkai on 2017/7/14.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#ifndef SimpleFactory_hpp
#define SimpleFactory_hpp

#include <stdio.h>

class SimpleFactory {
    
public:
    SimpleFactory(){}
    ~SimpleFactory(){}
    
public:
    static SimpleFactory* GetIntance();
    BaseGameEntity* CreateBaseEnity(const std::string& className);
};

#endif /* SimpleFactory_hpp */
