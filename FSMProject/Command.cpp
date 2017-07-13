//
//  Command.cpp
//  FSMProject
//
//  Created by fengkai on 2017/7/13.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#include "PCH.h"


ConcerteCommand::ConcerteCommand(BaseGameEntity* rever) : receiver(rever)
{
    
}

void ConcerteCommand::Execute()
{
    receiver->Run();
}

