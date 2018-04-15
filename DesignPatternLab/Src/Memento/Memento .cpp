#include "Memento.h"

void IMemento::Donothing()
{


}


COrigntor::COrigntor()
	: m_mementor(nullptr)
{

}


COrigntor::~COrigntor() = default;


//! ��֤ͬ���Ĳ����ܴ�������
IMemento* COrigntor::CreatMemento(std::string strInfo)
{
	if (strInfo.empty())
	{
		return nullptr;
	}

	IMemento* tmpmementor = new CMementor(strInfo);
	return  tmpmementor;

}



bool COrigntor::Setter(IMemento* memento)
{
	if (nullptr == memento)
	{
		return false;
	}

	CMementor* tmp = dynamic_cast<CMementor*>(memento);
	if (nullptr == tmp)
	{
		return false;
	}

	m_mementor = tmp;
	return true;
}


void COrigntor::DisplayName()
{
	if (nullptr == m_mementor)
	{
		std::cout << "m_mementor is nullptr\n";
		return;
	}

	std::cout << __func__ << " Myname is: " 
		<< m_mementor->GetName().c_str() << std::endl;
}


COrigntor::CMementor::CMementor(std::string strInfo)
	: m_strName(strInfo)
{

}


COrigntor::CMementor::~CMementor()
{

}


void COrigntor::CMementor::SetName(std::string strInfo)
{
	m_strName = strInfo;
}


std::string COrigntor::CMementor::GetName()
{
	return m_strName;
}


CMementorMgr::CMementorMgr()
{
	m_mementorContainer.clear();
}


CMementorMgr::~CMementorMgr()
{
	auto it = m_mementorContainer.begin();
	std::cout << "Memento Num is:" << m_mementorContainer.size()<<"\n";

	for ( ; it != m_mementorContainer.end(); it++)
	{
		delete it->second;
		it->second = nullptr;
	}

}

bool CMementorMgr::SetMemento(std::string strName, IMemento* memento)
{
	if (nullptr == memento || strName.empty())
	{
		return false;
	}

	auto it = m_mementorContainer.begin();
	for (; it != m_mementorContainer.end(); ++it)
	{
		if (it->first == strName)
		{
			//! ����ͬ����֮�ʷ����ϲ����ϲ㴦��
			return false;
		}
	}

	m_mementorContainer.insert(std::pair<std::string, IMemento*>(strName, memento));
	return true;
}


IMemento* CMementorMgr::GetMemento(std::string strName)
{
	auto it = m_mementorContainer.begin();
	for (; it != m_mementorContainer.end(); ++it)
	{
		if (it->first == strName)
		{
			return it->second;
		}
	}

	return nullptr;
}



void TestMemento()
{
	//! ��������¼������
	CMementorMgr mementorcfg;


	//! ������Ҫ�������ģ��
	COrigntor origntor;


	//! ������ͬ�ı���¼
	IMemento* tmp = origntor.CreatMemento("MementorA");
	IMemento* tmp1 = origntor.CreatMemento("MementorB");


	//! ����ص���Ϣ���뱸��¼��������
	mementorcfg.SetMemento( "MementorA", tmp);
	mementorcfg.SetMemento("MementorB", tmp1);


	//! ���ò�ͬ��״̬
	IMemento* retTmp = mementorcfg.GetMemento("MementorA");
	origntor.Setter(retTmp);
	origntor.DisplayName();

	IMemento* retTmp1 = mementorcfg.GetMemento("MementorB");
	origntor.Setter(retTmp1);
	origntor.DisplayName();
}