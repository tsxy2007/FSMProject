//
//  main.cpp
//  FSMProject
//
//  Created by fengkai on 2017/7/6.
//  Copyright © 2017年 fengkai. All rights reserved.
//


#include "PCH.h"
int main(int argc, const char * argv[]) {
    Troll* t = new Troll(1);
//    State_RunAway* pState = new State_RunAway( );
//    t->ChangeState( pState );
    while (true) {
        t->Update() ;
        usleep(33 * 1000);
    }
    return 0;
}
