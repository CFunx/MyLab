#pragma once
#include <iostream>
#include <string>

/**
	代理模式主要是为其他对象提供一种代理来控制对真实对象的访问。其本质就是控制对象的访问
	代理模式主要有以下几种：
	1.虚拟代理
	2.远程代理
	3.Copy_on_write 代理
	4.保护代理
	5.Cache代理
	6.防火墙代理
	7.同步代理
	8.智能指引
*/

namespace nsProxy
{
	
	//! 保护代理
	class IObject
	{
	public:
		virtual std::string GetName() = 0;
		virtual std::string GetSex() = 0;
		virtual std::string GetIDCard() = 0;
	};

	class CRealObj : public IObject
	{
	public:
		CRealObj() = default;
		~CRealObj() = default;
		std::string GetName() override;
		std::string GetSex() override;
		std::string GetIDCard() override;
	};


	class CProxy : public IObject
	{
	public:
		CProxy(IObject* obj);
		~CProxy() = default;
		std::string GetName() override;
		std::string GetSex() override;
		std::string GetIDCard() override;
	private:
		IObject* m_obj;
	};

	void TestProxy();

}