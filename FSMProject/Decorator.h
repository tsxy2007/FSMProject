//
//  Decorator.hpp
//  FSMProject
//
//  Created by fengkai on 2017/7/24.
//  Copyright © 2017年 fengkai. All rights reserved.
//

/**
 
 装饰者模式
 */

#ifndef Decorator_hpp
#define Decorator_hpp

class Property
{
public:
    virtual void print( ) = 0;
    virtual float GetSpeed() = 0;
};

class PropertySpeed : public Property {
private:
    float speed;
    
public:
    PropertySpeed():speed(10.0f){};
    virtual float GetSpeed() {return speed;};
    virtual void print();
};

class AddPropertySpeed : public Property
{
private:
    Property* mPro;
    float addSpeed;
public:
    AddPropertySpeed(Property * speed);
    virtual void print() ;
    virtual std::string add();
    virtual float GetSpeed();
    virtual void huanyuan();
};

class SubPropertySpeed : public Property {
private:
    Property* mPro;
    float subSpeed;
public:
    SubPropertySpeed(Property* pt);
    virtual void print();
    virtual std::string sub();
    virtual float GetSpeed();
};

#endif /* Decorator_hpp */
