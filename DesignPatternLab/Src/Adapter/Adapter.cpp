#include "Adapter.h"


namespace nsAdapter
{

	void CMySpec::MyShowName()
	{
		std::cout << "My name is cfun \n";
	}

	void CMySpec::MyShowID()
	{
		std::cout << "My ID is 31772 \n";
	}

	void CMySpec::MyShowAction()
	{
		std::cout << "My Action is running \n";
	}



	void CAdaPter::ShowName()
	{
		m_myspec.MyShowName();
	}

	void CAdaPter::ShowID()
	{
		m_myspec.MyShowID();
	}

	void CAdaPter::ShowAction()
	{
		m_myspec.MyShowAction();
	}


	void TestAdapter()
	{
		CTarget& target = CAdaPter();
		target.ShowName();
		target.ShowID();
		target.ShowAction();
	}


}