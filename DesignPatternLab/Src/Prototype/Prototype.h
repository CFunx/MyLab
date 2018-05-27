#pragma  once
#include <iostream>
#include <string>

/**
	ԭ��ģʽ���Ǹ������еĶ��󴴽���һ����֮��ȫһ���Ķ����ģʽ
*/

namespace nsPrototype
{
	//! ԭ��ģʽ�Ľӿ�
	class IPrototype
	{
	public:
		virtual IPrototype* Clone() = 0;
		virtual std::string GetName() = 0;
	};


	class ConcretePrototype : public IPrototype
	{
	public:
		ConcretePrototype();
		ConcretePrototype(std::string strName);
		~ConcretePrototype() = default;

		IPrototype* Clone() override;
		std::string GetName() override;
		void SetName(std::string strName);
	private:
		std::string m_strName;

	};


	void TestPrototype();

}