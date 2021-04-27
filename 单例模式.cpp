#include<iostream>
#include<mutex>
using namespace std;
mutex g_mutex;


#if 0
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (m_Instance == NULL)
		{
			m_Instance = new Singleton();
		}
		return m_Instance;
	}
	static void DestroyInstance()
	{
		if (m_Instance != NULL)
		{
			delete m_Instance;
			m_Instance = NULL;
		}
	}
	int GetTest()
	{
		return m_Test;
	}
private:
	Singleton()//Ϊ�˷�ֹ���ⲿ������Ĺ��캯��������ʵ��������Ϊ˽�еġ�
	{
		m_Test = 10;
	}
	static Singleton* m_Instance;
	int m_Test;
};
Singleton* Singleton::m_Instance = NULL;




//��������ģʽ��ʵ������ڶ��̻߳����£��Ϳ��ܻᴴ�����Singletonʵ����
//���ư汾(����)
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (m_Instance == NULL)//���������жϣ��Ϳ��Ա����μ��������������ͬʱҲ��֤���̰߳�ȫ��˫������
		{
			g_mutex.lock();
			if (m_Instance == NULL)
			{
				m_Instance = new Singleton();
			}
			g_mutex.unlock();
		}
		return m_Instance;
	}

	static void DestoryInstance()
	{
		if (m_Instance != NULL)
		{
			delete m_Instance;
			m_Instance = NULL;
		}
	}

	int GetTest()
	{
		return m_Test;
	}

private:
	Singleton() { m_Test = 20; }
	static Singleton* m_Instance;
	int m_Test;
};
Singleton* Singleton::m_Instance = NULL;



//��������������д����ݵĲ�����������������Ϊһ�����ܵ�ƿ��


class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return const_cast <Singleton*>(m_Instance);
	}

	static void DestoryInstance()
	{
		if (m_Instance != NULL)
		{
			delete m_Instance;
			m_Instance = NULL;
		}
	}

	int GetTest()
	{
		return m_Test;
	}

private:
	Singleton() { m_Test = 10; }
	static const Singleton* m_Instance;
	int m_Test;
};
const Singleton* Singleton::m_Instance = new Singleton();


int main()
{
	Singleton* singletonObj = Singleton::GetInstance();
	cout << singletonObj->GetTest() << endl;
	Singleton::DestoryInstance();
	return 0;
}
//��Ϊ��̬��ʼ���ڳ���ʼʱ��Ҳ���ǽ���������֮ǰ�������߳��Ե��̷߳�ʽ����˳�ʼ����
//���Ծ�̬��ʼ��ʵ����֤���̰߳�ȫ�ԡ�������Ҫ��Ƚϸ�ʱ���Ϳ���ʹ�����ַ�ʽ���Ӷ�����Ƶ���ļ����ͽ�����ɵ���Դ�˷ѡ�


//������������ʵ�֣���Ҫ���ǵ�ʵ�������١��ɴˣ��ͳ����˵�����ʵ�ַ�ʽ��
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		static Singleton m_Instance;
		return &m_Instance;
	}

	int GetTest()
	{
		return m_Test++;
	}

private:
	Singleton() { m_Test = 10; };
	int m_Test;
};
int main()
{
	Singleton* singletonObj = Singleton::GetInstance();
	cout << singletonObj->GetTest() << endl;

	singletonObj = Singleton::GetInstance();
	cout << singletonObj->GetTest() << endl;
}

#endif