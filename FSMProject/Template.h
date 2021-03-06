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

/**
 定义接口 有哪些步骤完成！！
 */
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

/**
 实现接口，并且做成钩子，让子类决定实现那个方法
 */
class TemplateBase : public TemplateInterface{
public:
    virtual void Do1( ) {};
    virtual void Do2( ) {};
    virtual void Do3( ) {};
    
};
/**
 
 自己判断哪个该实现！！！！
 */
class TempLateA : public TemplateBase{
    
public:
    TempLateA();
    ~TempLateA();
    void Do1();
    void Do3();
};

#endif /* Template_hpp */
