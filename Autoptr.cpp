#include <iostream>

template<typename T>
class AutoPtr 
{
private:
	T* m_ptr = nullptr;
public:
	AutoPtr(T* ptr=nullptr) :m_ptr(ptr)
	{
		std::cout << "Call constructor " << std::endl;
	}
	AutoPtr(AutoPtr&& obj)
	{
		this->m_ptr = obj.m_ptr;
		obj.m_ptr = nullptr;
		std::cout << "Call move constructor " << std::endl;
	}
	AutoPtr& operator=(AutoPtr&& obj)
	{
		if (this != obj)
		{
			delete m_ptr;
			m_ptr = obj.m_ptr;
			obj.m_ptr = nullptr;
		}
		return *this;
		std::cout << "Call move operator assignment " << std::endl;
	}
	~AutoPtr()
	{
		delete m_ptr;
		std::cout << "Call destructor " << std::endl;
	}
public:
	T& operator *()
	{
		return *m_ptr;
	}
	T* operator ->()
	{
		return m_ptr;
	}
};

int main(int argc, char** argv)
{
	AutoPtr<int>ptr(new int(10));
	AutoPtr<int>ptr2 = std::move(ptr);

	return 0;
}