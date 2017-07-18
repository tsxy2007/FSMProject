//
//  Troll.cpp
//  FSMProject
//
//  Created by fengkai on 2017/7/6.
//  Copyright © 2017年 fengkai. All rights reserved.
//


#include "PCH.h"

Troll::Troll(int id):BaseGameEntity(id),power(100)
{
    m_pStateMachine = new StateMachine<Troll>(this);
    m_pStateMachine->SetCurrentState(State_RunAway::instance());
    SharedNotificaitonCenter()->addObserver(this, CC_CALLFUNCO_SELECTOR(Troll::ChangeState), "powerplus", nullptr);
//    SharedNotificaitonCenter()->removeAllObserver(this);
    m_invoker = new Invoker<BaseGameEntity>();
    m_invoker->setCommand(new  ConcerteCommand( this ) );
    
}

Troll::~Troll()
{
    
}

void Troll::Update()
{
    if (m_pStateMachine)
    {
        m_pStateMachine->Update();
    }
}

void Troll::ChangeState(State<Troll> *pNewState)
{
    if (this->m_pStateMachine)
    {
        this->m_pStateMachine->ChangeState(pNewState);
    }
}

void Troll::plusPower()
{
    power++;
    cout<<"State_Sleep Excute ........"<<power<<endl;
    
    
}
void Troll::subPower()
{
    power--;
    cout<<"State_RunAway Excute ........"<<power<<endl;
}
bool Troll::isLei()
{
    return  power <= 30;
}

bool Troll::isPower()
{
    return power >= 90;
}

void Troll::ChangeState(BaseGameEntity *object)
{
    m_invoker->ExecuteCommand();
}

void Troll::Run( )
{
    BaseGameEntity::Run();
    this->ChangeState(State_RunAway::instance());
}

