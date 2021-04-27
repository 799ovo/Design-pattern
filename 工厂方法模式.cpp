#include<iostream>
using namespace std;
/*
工厂方法模式的意义是定义一个创建产品对象的工厂接口，将实际创建工作推迟到子类当中。
核心工厂类不再负责产品的创建，这样核心类成为一个抽象工厂角色，仅负责具体工厂子类必须实现的接口，
这样进一步抽象化的好处是使得工厂方法模式可以使系统在不修改具体工厂角色的情况下引进新的产品。

（1）在设计的初期，就考虑到产品在后期会进行扩展的情况下，可以使用工厂方法模式；
（2）产品结构较复杂的情况下，可以使用工厂方法模式；
*/

#if 0
class Product
{
public:
	virtual void show() = 0;
};

class ProductA :public Product
{
public:
	void show()
	{
		cout << "I'm ProductA" << endl;
	}
};

class ProductB :public Product
{
public:
	void show()
	{
		cout << "I'm ProductB" << endl;
	}
};

class ProductC :public Product
{
public:
	void show()
	{
		cout << "I'm ProductC" << endl;
	}
};

class Factory
{
public:
	virtual Product* CreateProduct() = 0;
};

class FactoryA :public Factory
{
public:
	Product* CreateProduct()
	{
		return new ProductA();
	}
};

class FactoryB :public Factory
{
public:
	Product* CreateProduct()
	{
		return new ProductB();
	}
};

class FactoryC :public Factory
{
public:
	Product* CreateProduct()
	{
		return new ProductC();
	}
};

int main()
{
	Factory* factoryA = new FactoryA();
	Product* productObjA = factoryA->CreateProduct();
	productObjA->show();

	Factory* factoryB = new FactoryB();
	Product* productObjB = factoryB->CreateProduct();
	productObjB->show();

	Factory* factoryC = new FactoryC();
	Product* productObjC = factoryC->CreateProduct();
	productObjC->show();

	if (factoryA != NULL)
	{
		delete factoryA;
		factoryA = NULL;
	}

	if (factoryB != NULL)
	{
		delete factoryB;
		factoryB = NULL;
	}

	if (productObjA != NULL)
	{
		delete productObjA;
	}

	if (productObjB != NULL)
	{
		delete productObjB;
	}

	if (productObjC != NULL)
	{
		delete productObjC;
	}
	return 0;
}
#endif