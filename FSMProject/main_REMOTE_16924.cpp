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
    
    int m[10] = {1,2,3,4,5,6,7,8,9,10};
    
    arrayIterator<int> ArrayIterator(m,10);
    
    while (ArrayIterator.hasNext())
    {
        int b = ArrayIterator.next();
        cout<<"ArrayIterator next is "<<b<<endl;
    }
    
    TempLateA* ta = new TempLateA();
    ta->Run();
    
    
    Menu menu("menu_root");

    menu.add(new MenuItem("menu_item_1"));
    
    Menu* menu_1 = new Menu("menu_1");
    menu_1->add(new MenuItem("menu_1_item_1"));
    menu.add(menu_1);
    
    menu.print();
    
    
    while (true)
    {
        t->Update() ;
        usleep(33 * 1000);
    }
   
    return 0;
}
