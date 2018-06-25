#pragma once

#include<iostream>
#include <string>

/**
* \brief 将不同的名字的接口统一成，满足需求的名字的接口。这样就能
* 统一调用相同的接口,说白了就是接口不同咋办？ 包一层。。。。
*
*/

namespace nsAdapter
{
	/** 
	*  \brief 统一接口的类,也就是将要转换的统一接口
	*/
	class CTarget
	{
	public:
		virtual void ShowName() = 0;
		virtual void ShowID() = 0;
		virtual void ShowAction() = 0;
	};

	//! 需要用适配器包装的类
	class CMySpec
	{
	public:
		void MyShowName();
		void MyShowID();
		void MyShowAction();
	};


	//! 相应的适配器
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