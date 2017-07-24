//
//  Proxy.cpp
//  FSMProject
//
//  Created by fengkai on 2017/7/24.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#include "PCH.h"

void RealSubject::Request()
{
    cout<<"RealSubject Request"<<endl;
}

Proxy::Proxy(RealSubject* ject) : rSubject(ject)
{
    
}

Proxy::~Proxy()
{
    if (rSubject)
    {
         delete rSubject;
        rSubject = NULL;
    }
}

void Proxy::Request()
{
    if (rSubject != NULL)
    {
        rSubject->Request();
    }
}
