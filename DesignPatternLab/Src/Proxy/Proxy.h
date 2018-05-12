#pragma once
#include <iostream>
#include <string>

/**
	����ģʽ��Ҫ��Ϊ���������ṩһ�ִ��������ƶ���ʵ����ķ��ʡ��䱾�ʾ��ǿ��ƶ���ķ���
	����ģʽ��Ҫ�����¼��֣�
	1.�������
	2.Զ�̴���
	3.Copy_on_write ����
	4.��������
	5.Cache����
	6.����ǽ����
	7.ͬ������
	8.����ָ��
*/

namespace nsProxy
{
	
	//! ��������
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