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
	Singleton()//为了防止在外部调用类的构造函数而构造实例，设置为私有的。
	{
		m_Test = 10;
	}
	static Singleton* m_Instance;
	int m_Test;
};
Singleton* Singleton::m_Instance = NULL;




//上述单例模式的实现如果在多线程环境下，就可能会创建多个Singleton实例。
//改善版本(加锁)
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (m_Instance == NULL)//进行两次判断，就可以避免多次加锁与解锁操作，同时也保证了线程安全（双检锁）
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



//上述方法如果进行大数据的操作，加锁操作将成为一个性能的瓶颈


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
//因为静态初始化在程序开始时，也就是进入主函数之前，由主线程以单线程方式完成了初始化，
//所以静态初始化实例保证了线程安全性。在性能要求比较高时，就可以使用这种方式，从而避免频繁的加锁和解锁造成的资源浪费。


//由于上述三种实现，都要考虑到实例的销毁。由此，就出现了第四种实现方式：
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