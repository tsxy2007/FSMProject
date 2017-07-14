//
//  Factory.hpp
//  FSMProject
//  普通工厂模式
//  Created by fengkai on 2017/7/14.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#ifndef Factory_hpp
#define Factory_hpp

class Factory {
    
public:
    virtual BaseGameEntity* CreateBaseEnity(const std::string& className) = 0;
};

class BaseGameEntityFactory : public Factory {
public:
    BaseGameEntityFactory(){}
    ~BaseGameEntityFactory(){}
    
public:
    static BaseGameEntityFactory* GetIntance();
    virtual BaseGameEntity* CreateBaseEnity(const std::string& className) override;
};

#endif /* Factory_hpp */
