#include<iostream>
using namespace std;
/*
��������ģʽ�������Ƕ���һ��������Ʒ����Ĺ����ӿڣ���ʵ�ʴ��������Ƴٵ����൱�С�
���Ĺ����಻�ٸ����Ʒ�Ĵ����������������Ϊһ�����󹤳���ɫ����������幤���������ʵ�ֵĽӿڣ�
������һ�����󻯵ĺô���ʹ�ù�������ģʽ����ʹϵͳ�ڲ��޸ľ��幤����ɫ������������µĲ�Ʒ��

��1������Ƶĳ��ڣ��Ϳ��ǵ���Ʒ�ں��ڻ������չ������£�����ʹ�ù�������ģʽ��
��2����Ʒ�ṹ�ϸ��ӵ�����£�����ʹ�ù�������ģʽ��
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