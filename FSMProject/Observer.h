//
//  Observer.hpp
//  FSMProject
//
//  Created by fengkai on 2017/7/31.
//  Copyright © 2017年 fengkai. All rights reserved.
//

/**
 观察者模式
 */

#ifndef Observer_hpp
#define Observer_hpp

class Subject_Ob {
    
public:
    Subject_Ob(){};
    ~Subject_Ob(){};
    virtual void update() = 0 ;
};

class Observer {
private:
    std::vector<Subject_Ob*> m_observers;
public:
    Observer(){};
    ~Observer()
    {
        for (std::vector<Subject_Ob*>::iterator it = m_observers.begin()    ; it != m_observers.end();)
        {
            it = m_observers.erase(it);
        }
    };
    void addObserver(Subject_Ob* observer);
    void removeObserver(Subject_Ob* observer);
    void notify();
    
};

class Test_Subject : public Subject_Ob {
    
public:
    Test_Subject(){};
    ~Test_Subject(){};
    virtual void update()
    {
        std::cout<<"Test_subject _ notifiy"<<std::endl;
    }
};

#endif /* Observer_hpp */
