//
//  State.h
//  FSMProject
//
//  Created by fengkai on 2017/7/6.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#ifndef State_h
#define State_h


class Troll;
template< typename Type >
class State {
    
public:
    virtual ~State(){};
    virtual void Excute(Type* troll) = 0;
    virtual void Enter(Type* troll) = 0 ;
    virtual void Exit(Type* troll) = 0;
};

template <typename Type>
class State_Test : public State<Type> {
    
public:
    virtual ~State_Test(){};
    virtual void Excute(Type* troll);
    virtual void Enter(Type* troll);
    virtual void Exit(Type* troll);
};

template <typename Type>
void State_Test<Type>::Excute(Type* troll)
{
    
}

template <typename Type>
void State_Test<Type>::Enter(Type *troll)
{
    
}

template <typename Type>
void State_Test<Type>::Exit(Type *troll)
{
    
}

class State_RunAway : public State<Troll> {
public:
    State_RunAway();
    virtual ~State_RunAway(){}
public:
    virtual void Excute(Troll* troll);
    virtual void Enter(Troll* troll);
    virtual void Exit(Troll* troll);
    static State_RunAway* instance()
    {
        static State_RunAway* m_instance = NULL;
        if ( m_instance == NULL )
        {
            m_instance = new State_RunAway;
        }
        return m_instance;
    }
};

class State_Sleep : public State<Troll> {
public:
    State_Sleep();
    virtual ~State_Sleep(){}
public:
    virtual void Excute(Troll* troll);
    virtual void Enter(Troll* troll);
    virtual void Exit(Troll* troll);
    static State_Sleep* instance()
    {
        static State_Sleep* m_instance = NULL;
        if ( m_instance == NULL )
        {
            m_instance = new State_Sleep;
        }
        return m_instance;
    }
};

#endif /* State_h */
