#include <iostream>
using namespace std;

/*
(1)在程序中，需要创建的对象很多，导致对象的new操作多且杂时，需要使用简单工厂模式；
(2)由于对象的创建过程是我们不需要去关心的，而我们注重的是对象的实际操作，
所以，我们需要分离对象的创建和操作两部分，如此，方便后期的程序扩展和维护。
*/
#if 0
typedef enum ProductTypeTag
{
    TypeA, TypeB, TypeC

}PRODUCTTYPE;


class Product
{
public:
    virtual void Show() = 0;
};

class ProductA : public Product
{
public:
    void Show()
    {
        cout << "I'm ProductA" << endl;
    }
};

class ProductB : public Product
{
public:
    void Show()
    {
        cout << "I'm ProductB" << endl;
    }
};

class ProductC : public Product
{
public:
    void Show()
    {
        cout << "I'm ProductC" << endl;
    }
};


class Factory
{
public:
    Product* CreateProduct(PRODUCTTYPE type)
    {
        switch (type)
        {
        case TypeA:
            return new ProductA();

        case TypeB:
            return new ProductB();

        case TypeC:
            return new ProductC();

        default:
            return NULL;
        }
    }
};

int main()
{
    Factory* ProductFactory = new Factory();
    Product* productObjA = ProductFactory->CreateProduct(TypeA);
    if (productObjA != NULL)
        productObjA->Show();

    Product* productObjB = ProductFactory->CreateProduct(TypeB);
    if (productObjB != NULL)
        productObjB->Show();

    Product* productObjC = ProductFactory->CreateProduct(TypeC);
    if (productObjC != NULL)
        productObjC->Show();

    delete ProductFactory;
    ProductFactory = NULL;

    delete productObjA;
    productObjA = NULL;

    delete productObjB;
    productObjB = NULL;

    delete productObjC;
    productObjC = NULL;

    return 0;
}
#endif