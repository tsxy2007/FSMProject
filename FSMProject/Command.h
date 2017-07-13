//
//  Command.hpp
//  FSMProject
//  命令模式代码
//
//  Created by fengkai on 2017/7/13.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#ifndef Command_hpp
#define Command_hpp

class Troll;
template <typename Type>
class ICommand {
    
public:
    virtual void Execute() = 0 ;
};


class ConcerteCommand : public ICommand<Troll> {
    
private:
    Troll* receiver;
public:
    ConcerteCommand(Troll* reveive);
    void Execute();
};


template <typename Type>
class Invoker {
private:
    ICommand<Type>* command;
    
public:
    void setCommand(ICommand<Type>* com);
    void ExecuteCommand();
};

template <typename Type>
void Invoker<Type>::setCommand(ICommand<Type> *com)
{
    if (command)
    {
        delete command;
        command = nullptr;
    }
    command = com;
}

template <typename Type>
void  Invoker<Type>::ExecuteCommand( )
{
    command->Execute();
}




#endif /* Command_hpp */
