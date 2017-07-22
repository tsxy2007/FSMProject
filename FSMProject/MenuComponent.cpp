//
//  MenuComponent.cpp
//  FSMProject
//
//  Created by 朱同宽 on 2017/7/22.
//  Copyright © 2017年 fengkai. All rights reserved.
//

#include "PCH.h"

MenuItem::MenuItem(std::string name): mName(name)
{
    
}

void MenuItem::print()
{
    MenuComponent::print();
    cout<<"Name = "<<mName<<endl;
}

Menu::Menu(std::string name ): mName(name)
{
    
}

void Menu::add(Component *component)
{
    mMenuComponents.push_back(component);
}

void Menu::remove(Component *component)
{
    typedef vector<Component*>::iterator comIterator;
    comIterator it = find(mMenuComponents.begin(), mMenuComponents.end(), component);
    if ( it!= mMenuComponents.end( ) )
        mMenuComponents.erase(it);
    
}


Component* Menu::getChild(int index)
{
    for (int i = 0; i<mMenuComponents.size(); i++)
    {
        if (i == index) {
            return mMenuComponents[i];
        }
    }
    return nullptr;
}

void Menu::print()
{
    cout<<"menu name = "<<mName<<endl;
    typedef vector<Component*>::iterator comIterator;
    comIterator it  = mMenuComponents.begin();
    for (; it != mMenuComponents.end(); it++)
    {
        Component* com = (Component*)(*it);
        com->print();
        
    }
}
