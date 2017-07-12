//
//  State.cpp
//  FSMProject
//
//  Created by fengkai on 2017/7/6.
//  Copyright © 2017年 fengkai. All rights reserved.
//
#include "PCH.h"

State_RunAway::State_RunAway()
{
    
}

void State_RunAway::Excute(Troll *troll)
{
    if ( troll->isLei() )
    {
        troll->ChangeState( State_Sleep::instance( ) );
    }
    else
    {
        troll->subPower();
    }
}

void State_RunAway::Enter(Troll *troll)
{
    cout<<"State_RunAway Enter ..........."<<endl;
}

void State_RunAway::Exit(Troll *troll)
{
    cout<<"State_RunAway Exit ..........."<<endl;
}


State_Sleep::State_Sleep()
{
    
}

void State_Sleep::Excute(Troll *troll)
{
    if ( troll->isPower( ) )
    {
        SharedNotificaitonCenter()->postNotification("powerplus");
    }
    else
    {
        troll->plusPower();
    }
}

void State_Sleep::Enter(Troll *troll)
{
    cout<<"State_Sleep Enter ..........."<<endl;
}

void State_Sleep::Exit(Troll *troll)
{
    cout<<"State_Sleep Exit ..........."<<endl;
}
