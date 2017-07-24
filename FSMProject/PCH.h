//
//  PCH.h
//  FSMProject
//
//  Created by fengkai on 2017/7/6.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#ifndef PCH_h
#define PCH_h



#include <iostream>
#include <unistd.h>
#include <list> 
#include <map>
#include "NotificationCenter.h"
#include "State.h"
#include "StateMachine.h"
#include "BaseGameEntity.h"
#include "Command.h"
#include "Troll.h"
#include "SimpleFactory.h"
#include "Factory.h"
#include "AbstractFactory.h"
#include "Template.h"
#include "Iterator.h"
#include "Proxy.h"


#include "MessageDispatcher.h"
using namespace std;

#define DELETE_LIST(type,list)                  \
{                                                    \
for (type::iterator it = list.begin(); it != list.end(); ) \
{                                                    \
          it = list.erase(it);                            \
delete (*it) ;\
}                                                    \
list.clear();                                        \
}

#define SharedNotificaitonCenter() NotificationCenter::getInstance()
#endif /* PCH_h */
