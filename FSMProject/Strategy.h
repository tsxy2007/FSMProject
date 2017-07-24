//
//  Strategy.hpp
//  FSMProject
//
//  Created by fengkai on 2017/7/24.
//  Copyright © 2017年 fengkai. All rights reserved.
//

/**
 
 策略模式 主要用于mvc中c层。
 */

#ifndef Strategy_hpp
#define Strategy_hpp

class TravelStrategy
{
public:
    virtual void travelAlgorithm() = 0 ;
};

class AirPlaneStrategy : public TravelStrategy
{
    
public:
    virtual void travelAlgorithm();
};

class TrainStrategy : public TravelStrategy
{
    
public:
    virtual void travelAlgorithm();
};

class BicycleStrategy : public TravelStrategy
{
    
public:
    virtual void travelAlgorithm();
};

#endif /* Strategy_hpp */
