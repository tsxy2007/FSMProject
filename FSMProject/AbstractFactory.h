//
//  AbstractFactory.hpp
//  FSMProject
//
//  Created by fengkai on 2017/7/14.
//  Copyright © 2017年 fengkai. All rights reserved.
//

/**
 
  抽象工厂！！！！！
 */

#ifndef AbstractFactory_hpp
#define AbstractFactory_hpp

template <typename Product,typename ConcreteProduct>
class ConcreteFactory {
public:
    static Product* createProduct(int val)
    {
        return new ConcreteProduct( val );
    }
};

template <typename Product> // 产品基类
class BaseFactory
{
public:
    typedef Product* (*CreateProductDelegate)(int val); //产品初始化方法
    typedef std::map<std::string,CreateProductDelegate> factoryMap; // 产品及初始化健值对
public:
    BaseFactory(){};
    ~BaseFactory(){};
    BaseFactory(BaseFactory& factory);
    static BaseFactory& GetInstance()
    {
        static BaseFactory<Product> m_instance ;
        return m_instance;
    }
    
public:
    template <typename ConcreteProduct> // 产品工厂
    void registerFactory(const std::string& _type) // 注册产品工厂
    {
        mFactoryMaps[_type] = ConcreteFactory<Product, ConcreteProduct>::createProduct;
    }
    void unregisterFactory();
    Product* createProduct(const std::string& _type,int val);
private:
    factoryMap mFactoryMaps;//保存所有注册过的具体工厂
};

template <typename Product>
void BaseFactory<Product>::unregisterFactory( )
{
    mFactoryMaps.clear( );
}

template <typename Product>
Product*  BaseFactory<Product>::createProduct(const std::string &_type , int val)
{
    typename factoryMap::iterator it = mFactoryMaps.find(_type);
    if (it!= mFactoryMaps.end())
    {
        CreateProductDelegate create = it->second;
        if (create != 0)
        {
            return create( val );
        }
    }
    return nullptr;
}


#endif /* AbstractFactory_hpp */
