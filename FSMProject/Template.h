//
//  Template.hpp
//  FSMProject
//
//  Created by fengkai on 2017/7/17.
//  Copyright © 2017年 fengkai. All rights reserved.
//

// 模板模式
#ifndef Template_hpp
#define Template_hpp

class TemplateInterface {
    
public:
    virtual void Run()
    {
        Do1();
        Do2();
        Do3();
    }
    virtual void Do1() = 0;
    virtual void Do2() = 0;
    virtual void Do3() = 0;
};

class TemplateBase : public TemplateInterface{
public:
    virtual void Do1( ) {};
    virtual void Do2( ) {};
    virtual void Do3( ) {};
    
};

class TempLateA : public TemplateBase{
    
public:
    TempLateA();
    ~TempLateA();
    void Do1();
    void Do2();
};

#endif /* Template_hpp */
