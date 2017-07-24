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
    

    RealSubject* sub = new RealSubject();
    Proxy* proxy = new Proxy(sub);
    proxy->Request();
    
    
    Menu menu("menu_root");

    menu.add(new MenuItem("menu_item_1"));
    
    Menu* menu_1 = new Menu("menu_1");
    menu_1->add(new MenuItem("menu_1_item_1"));
    menu.add(menu_1);
    
    menu.print();
    
    TravelStrategy* toolTravel = new AirPlaneStrategy();
    toolTravel->travelAlgorithm()  ;
    delete toolTravel;
    toolTravel = new TrainStrategy();
    toolTravel->travelAlgorithm();
    
    Property* pro = new PropertySpeed( );
    pro->print();
    AddPropertySpeed* pro1 = new AddPropertySpeed( pro );
    pro1->print();
    
    Property* pro2 = new SubPropertySpeed( pro1);
    pro2->print();
    
    pro1->huanyuan();
    pro2->print();
    
    while (true)
    {
        t->Update() ;
        usleep(33 * 1000);
    }
    
    auto_ptr<RealSubject*> rt ;
    return 0;
}
