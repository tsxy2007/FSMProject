//
//  main.cpp
//  FSMProject
//
//  Created by fengkai on 2017/7/6.
//  Copyright © 2017年 fengkai. All rights reserved.
//


#include "PCH.h"
int main(int argc, const char * argv[]) {
    typedef BaseFactory<Troll> TrollFactory;
    TrollFactory& factory = TrollFactory::GetInstance();
    factory.registerFactory<Troll>("Troll");
    
    Troll* t  = factory.createProduct("Troll", 1);
    Troll* t1 = factory.createProduct("Troll", 2);
//    Troll* t = (Troll*)SimpleFactory::GetIntance()->CreateBaseEnity("Troll");
//    Troll* t = (Troll*)BaseGameEntityFactory::GetIntance()->CreateBaseEnity("Troll");
//    State_RunAway* pState = new State_RunAway( );
//    t->ChangeState( pState );
    
    
    TempLateA* ta = new TempLateA();
    ta->Run();
    
    while (true) {
        t->Update() ;
        usleep(33 * 1000);
    }
   
    return 0;
}
