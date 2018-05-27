#pragma  once
#include <iostream>
#include <string>

/**
	原型模式就是根据现有的对象创建出一个与之完全一样的对象的模式
*/

namespace nsPrototype
{
	//! 原型模式的接口
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