//
//  Proxy.hpp
//  FSMProject
//
//  Created by fengkai on 2017/7/24.
//  Copyright © 2017年 fengkai. All rights reserved.
//

/**
 静态代理模式
 */
#ifndef Proxy_hpp
#define Proxy_hpp

class Subject {
    
public:
    Subject(){};
    ~Subject(){};
    virtual void Request() = 0 ;
};

class RealSubject : public Subject {
    
public:
    RealSubject(){};
    ~RealSubject(){};
    virtual void Request();
};

class Proxy : public Subject {
private:
    RealSubject* rSubject;
public:
    Proxy(RealSubject* ject);
    ~Proxy();
    virtual void Request();
};

/*
 
 动态代理模式
 */

#endif /* Proxy_hpp */
