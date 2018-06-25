#pragma once

#include<iostream>
#include <string>

/**
* \brief ����ͬ�����ֵĽӿ�ͳһ�ɣ�������������ֵĽӿڡ���������
* ͳһ������ͬ�Ľӿ�,˵���˾��ǽӿڲ�ͬզ�죿 ��һ�㡣������
*
*/

namespace nsAdapter
{
	/** 
	*  \brief ͳһ�ӿڵ���,Ҳ���ǽ�Ҫת����ͳһ�ӿ�
	*/
	class CTarget
	{
	public:
		virtual void ShowName() = 0;
		virtual void ShowID() = 0;
		virtual void ShowAction() = 0;
	};

	//! ��Ҫ����������װ����
	class CMySpec
	{
	public:
		void MyShowName();
		void MyShowID();
		void MyShowAction();
	};


	//! ��Ӧ��������
	class CAdaPter : public CTarget
	{
	public:
		void ShowName() override;
		void ShowID() override;
		void ShowAction() override;
	private:
		CMySpec m_myspec;
	};

	
	void TestAdapter();
}