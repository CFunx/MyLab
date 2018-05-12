#include "Proxy.h"

namespace nsProxy
{
	std::string CRealObj::GetName()
	{
		return "Gobin";
	}

	std::string CRealObj::GetSex()
	{
		return "Man";
	}

	std::string CRealObj::GetIDCard()
	{
		return "1008610010";
	}


	CProxy::CProxy(IObject* obj)
		:m_obj(obj)
	{


	}

	std::string CProxy::GetName()
	{
		//! 做相关的定制或者是保护性操作
		std::cout << "this is my name : Gobin\n";
		return m_obj->GetName();
	}

	std::string CProxy::GetSex()
	{
		//! 做相关的定制操作
		std::cout << "this is my sex : man\n";
		return m_obj->GetSex();
	}

	std::string CProxy::GetIDCard()
	{
		std::cout << "Please show your name before get my Id\n";
		return m_obj->GetIDCard();
	}

	void TestProxy()
	{
		IObject* obj = new CRealObj();

		CProxy proxy(obj);
		std::cout<<proxy.GetName()<<"\n";
		std::cout << proxy.GetSex() << "\n";
		std::cout << proxy.GetIDCard() << "\n";

		delete obj;
		obj = nullptr;
	}

}