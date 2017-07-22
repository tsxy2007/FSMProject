//
//  MenuComponent.hpp
//  FSMProject
//
//  Created by 朱同宽 on 2017/7/22.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#ifndef MenuComponent_hpp
#define MenuComponent_hpp

class Component
{
    
public:
    virtual void add(Component* menuComponent) = 0;
    virtual void remove(Component* menuComponent) = 0;
    virtual Component* getChild(int i) = 0 ;
    virtual std::string getName() = 0 ;
    virtual void print() = 0 ;
};

class MenuComponent : public Component{
    
public:
    virtual void add(Component* component){};
    virtual void remove(Component* component){};
    virtual Component* getChild(int i){return NULL;};
    virtual std::string getName(){return "";}
    virtual void print(){}
};

class MenuItem : public MenuComponent
{

private:
    std::string mName;
public:
    MenuItem(std::string name);
    virtual std::string getName(){ return mName;};
    virtual void print();
};

class Menu : public MenuComponent {
private:
    std::vector<Component*> mMenuComponents;
    std::string mName;
public:
    Menu(std::string name);
    virtual void add(Component* component);
    virtual void remove(Component* component);
    virtual Component* getChild(int i);
    virtual std::string getName(){return mName;};
    virtual void print();
};

#endif /* MenuComponent_hpp */
