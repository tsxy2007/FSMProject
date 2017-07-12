//
//  Troll.hpp
//  FSMProject
//
//  Created by fengkai on 2017/7/6.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#ifndef Troll_hpp
#define Troll_hpp
//class State;
//class BaseGameEntity;
//class StateMachine;
class Troll : public BaseGameEntity{
private:
    StateMachine<Troll>* m_pStateMachine;
    int power;
public:
    void subPower();
    void plusPower();
    bool isLei();
    bool isPower();
    Troll(int val);
    ~Troll();
    void Update();
    void ChangeState(State<Troll>* pNewState);
    void ChangeState(BaseGameEntity* object);
};


#endif /* Troll_hpp */
