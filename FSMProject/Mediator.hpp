//
//  Mediator.hpp
//  FSMProject
//
//  Created by fengkai on 2017/8/23.
//  Copyright © 2017年 fengkai. All rights reserved.
//
// 中介者模式

#ifndef Mediator_hpp
#define Mediator_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Mediator;

class Colleage {
private:
    string name;
    string content;
public:
    Colleage(string n = "") : name(n) {};
    void set_name(string name)
    {
        this->name = name;
    }
    string get_name()
    {
        return this->name;
    }
    void set_content(string c)
    {
        this->content = c;
    }
    string get_content()
    {
        return this->content;
    }
    virtual void talk() = 0;
};

class Monitor : public  Colleage
{
private:
public:
    Monitor(string n = "") : Colleage( n )
    {
        
    }
    virtual void talk()
    {
        cout<<"大班长说:"<<get_content()<<endl;
    }
};

class TuanZhiShu : public Colleage
{
public:
    TuanZhiShu(string n = "") : Colleage( n )
    {
        
    }
    virtual void talk()
    {
        cout<<"团支书说 : "<<get_content()<<endl;
    }
};

class StudentA : public Colleage
{
public:
    StudentA(string n = "") : Colleage( n )
    {
        
    }
    virtual void talk()
    {
        cout<<"同学A说 : "<<get_content()<<endl;
    }
};

class Mediator
{
public:
    vector<Colleage*> students;
    virtual void add_student(Colleage* student)
    {
        students.push_back(student);
    }
    
public:
    virtual void notify(Colleage* student){};
    virtual void chart(Colleage* student1 , Colleage* student2){};
};

class QQMediator : public Mediator
{
public:
    virtual void notify(Colleage* student)
    {
        student->talk();
        for (int i = 0 ; i<students.size(); i++)
        {
            students[i]->talk();
        }
    }
    virtual void chart(Colleage* student1,Colleage* student2)
    {
        student1->talk();
        student2->talk();
    }
};

#endif /* Mediator_hpp */
