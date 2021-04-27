#include<iostream>
using namespace std;
/*
��������ģʽ�����ڲ�Ʒ����ṹ��һ�ĳ��ϣ�Ϊһ���Ʒ�ṩ�����Ľӿڣ�
�����󹤳����������ڲ�Ʒ����ṹ��ĳ��ϣ���Ҫ���ڴ���һ�飨�ж�����ࣩ��صĲ�Ʒ��
Ϊ�����ṩ�����Ľӿڣ����ǵ����ж�������ɫʱ�����󹤳�����������ó���
*/

class ProductA
{
public:
	virtual void show() = 0;
};

class ProductA1 :public ProductA
{
public:
	void show()
	{
		cout << "I'm ProductA1" << endl;
	}
};

class ProductA2 :public ProductA
{
public:
	void show()
	{
		cout << "I'm ProductA2" << endl;
	}
};

class ProductB
{
public:
	virtual void show() = 0;
};

class ProductB1 :public ProductB
{
public:
	void show()
	{
		cout << "I'm ProductB1" << endl;
	}
};

class ProductB2 :public ProductB
{
public:
	void show()
	{
		cout << "I'm ProductB2" << endl;
	}
};

class Factory
{
public:
	virtual ProductA* CreateProductA() = 0;
	virtual ProductB* CreateProductB() = 0;
};


class Factory1 : public Factory
{
public:
	ProductA* CreateProductA()
	{
		return new ProductA1();
	}

	ProductB* CreateProductB()
	{
		return new ProductB1();
	}
};

class Factory2 : public Factory
{
	ProductA* CreateProductA()
	{
		return new ProductA2();
	}

	ProductB* CreateProductB()
	{
		return new ProductB2();
	}
};

int main()
{
	Factory* factoryObj1 = new Factory1();
	ProductA* productObjA1 = factoryObj1->CreateProductA();
	ProductB* productObjB1 = factoryObj1->CreateProductB();

	productObjA1->show();
	productObjB1->show();

	Factory* factoryObj2 = new Factory2();
	ProductA* productObjA2 = factoryObj2->CreateProductA();
	ProductB* productObjB2 = factoryObj2->CreateProductB();

	productObjA2->show();
	productObjB2->show();

	if (factoryObj1 != NULL)
	{
		delete factoryObj1;
		factoryObj1 = NULL;
	}

	if (factoryObj2 != NULL)
	{
		delete factoryObj2;
		factoryObj2 = NULL;
	}

	if (productObjA1 != NULL)
	{
		delete productObjA1;
		productObjA1 = NULL;
	}

	if (productObjA2 != NULL)
	{
		delete productObjA2;
		productObjA2 = NULL;
	}

	if (productObjB1 != NULL)
	{
		delete productObjB1;
		productObjB1 = NULL;
	}

	if (productObjB2 != NULL)
	{
		delete productObjB2;
		productObjB2 = NULL;
	}
	return 0;
}
