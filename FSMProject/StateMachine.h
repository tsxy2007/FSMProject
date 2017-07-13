//
//  StateMachine.hpp
//  FSMProject
//
//  Created by fengkai on 2017/7/6.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#ifndef StateMachine_hpp
#define StateMachine_hpp

//class State;
template <class Type>
class StateMachine
{
private:
    
    Type* m_pOwner;
    State<Type>* m_pCurrentState;
    State<Type>* m_pPreviousState;
    State<Type>* m_pGlobalState;
public:
    StateMachine(Type* owner);
    void SetCurrentState(State<Type>* state);
    void SetGlobalState(State<Type>* state);
    void SetPreviousState(State<Type>* state);
    void Update()const;
    void ChangeState(State<Type>* state);
    void RevertToPreviousState();
    State<Type>* CurrentState() const {return  m_pCurrentState;}
    State<Type>* GlobalState() const { return m_pGlobalState;}
    State<Type>* PreviousState()const{return m_pPreviousState;}
    bool isInState(const State<Type>& st)const ;
};

template <typename Type>
StateMachine< Type >::StateMachine(Type* type)
    : m_pOwner(type)
    , m_pCurrentState(NULL)
    , m_pPreviousState(NULL)
    , m_pGlobalState(NULL)
{
    
}


template <typename Type>
void StateMachine<Type>::SetCurrentState(State<Type> *state)
{
    m_pCurrentState = state;
}

template <typename Type>
void StateMachine<Type>::SetGlobalState(State<Type> *state)
{
    m_pGlobalState = state;
}

template <typename Type>
void StateMachine<Type>::SetPreviousState(State<Type> *state)
{
    m_pPreviousState = state;
}

template <typename Type>
void StateMachine<Type>::Update( ) const
{
    if (m_pGlobalState)
    {
        m_pGlobalState->Excute(m_pOwner);
    }
    if (m_pCurrentState)
    {
        m_pCurrentState->Excute(m_pOwner);
    }
}

template <class Type>
void StateMachine<Type>::ChangeState(State<Type> *state)
{
    m_pPreviousState = m_pCurrentState;
    if (m_pCurrentState)
        m_pCurrentState->Exit(m_pOwner);
    m_pCurrentState = state;
    m_pCurrentState->Enter(m_pOwner);
}

template <class Type>
void StateMachine<Type>::RevertToPreviousState()
{
    ChangeState(m_pPreviousState);
}



#endif /* StateMachine_hpp */
