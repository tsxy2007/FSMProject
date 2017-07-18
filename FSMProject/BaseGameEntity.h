//
//  BaseGameEntity.hpp
//  FSMProject
//
//  Created by fengkai on 2017/7/6.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#ifndef BaseGameEntity_hpp
#define BaseGameEntity_hpp

class BaseGameEntity
{
    
private:
    int m_ID;
    static int m_iNextValidID ;
public:
    void SetID(int val);
    BaseGameEntity(int id);
    virtual ~BaseGameEntity();
    int ID() const;
    virtual void Run();
    static int GetNextID();
    
};

#endif /* BaseGameEntity_hpp */
