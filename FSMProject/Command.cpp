//
//  Command.cpp
//  FSMProject
//
//  Created by fengkai on 2017/7/13.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#include "PCH.h"


ConcerteCommand::ConcerteCommand(Troll* rever) : receiver(rever)
{
    
}

void ConcerteCommand::Execute()
{
    this->receiver->Run();
}
