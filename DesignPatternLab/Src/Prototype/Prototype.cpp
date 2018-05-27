#include "Prototype.h"


namespace nsPrototype
{

	ConcretePrototype::ConcretePrototype()
		:m_strName("")
	{

	}

	ConcretePrototype::ConcretePrototype(std::string strName)
		: m_strName(strName)
	{

	}

	IPrototype* ConcretePrototype::Clone()
	{
		//! ����һ���µĶ��󲢽��˶���ĳ�Ա�������п���
		ConcretePrototype* tmp = new ConcretePrototype;
		tmp->SetName(this->m_strName);
		
		return tmp;
	}

	std::string ConcretePrototype::GetName()
	{
		return m_strName;
	}


	void ConcretePrototype::SetName(std::string strName)
	{
		m_strName = strName;
	}


	
	void TestPrototype()
	{
		//! ��������
		IPrototype* prototype1 = new ConcretePrototype("Jeff");
		std::cout << "Hi, I am" << (prototype1->GetName()).c_str() << std::endl;

		//! ��¡����
		IPrototype* prototype2 = prototype1->Clone();
		std::cout << "Hi, I am Jeff shadows my name is :" <<
			(prototype2->GetName()).c_str() << std::endl;


		//! ���ٶ���
		delete prototype1;
		prototype1 = nullptr;

		delete prototype2;
		prototype2 = nullptr;
	}
}