//
//  Iterator.hpp
//  FSMProject
//
//  Created by fengkai on 2017/7/17.
//  Copyright © 2017年 fengkai. All rights reserved.
//

// 迭代器模式

#ifndef Iterator_hpp
#define Iterator_hpp

#include <stdio.h>

template <typename Type>
class iterator_ {
public:
    virtual bool hasNext() = 0 ;
    virtual Type next() = 0 ;
};

template <typename Type>
class arrayIterator : public iterator_<Type> {
    
private:
    Type* mData;
    int mPosition;
    int mSize;
public:
    arrayIterator(Type* array , int lenght);
    virtual bool hasNext();
    virtual Type next();
};

template <typename Type>
arrayIterator<Type>::arrayIterator(Type* array , int lenght):mData(array), mSize(lenght),mPosition(0)
{
//    mData = new Type();
//    for (int i = 0 ; i<lenght; i++)
//    {
//        mData[i] = array[i];
//    }
//    std::cout<<"msize = "<< mSize <<std::endl;
}

template <typename Type>
bool arrayIterator<Type>::hasNext( )
{
    return mPosition < mSize;
}

template <typename Type>
Type arrayIterator<Type>::next( )
{
    Type item = NULL;
    if (hasNext())
    {
        item = mData[mPosition];
        mPosition += 1;
    }
        
    return item;
}

#endif /* Iterator_hpp */
