#pragma once
#include <iostream>
#include <map>

/**
*  \brief ����¼ģʽ����Ҫ����������ڲ��ཫĳ�����״̬����������ͬʱ
�ṩһ���ⲿ��������������Ǵ洢��Ӧ��״̬�������ⲿ�಻�ܹ������ڲ���ľ��巽��
*/



//! ����¼�ľ���ӿ�
class IMemento
{
public:
	
	//! ʵ��Ϊ�գ���Ŀ������ֹ�ⲿ����¼�е�����
	virtual void Donothing();
};




//! ��Ҫ����¼�Ĺ���ģ��
class COrigntor
{
public:
	COrigntor();
	~COrigntor();

	IMemento* CreatMemento(std::string strName);

	bool Setter(IMemento* memento);

	void DisplayName();
private:

	class CMementor : public IMemento
	{
	  public:
		  CMementor(std::string strName);
		  ~CMementor();

		  void SetName(std::string strName);
		  std::string GetName();
	  private:
		  std::string  m_strName;
	};
private:

	//! �����Ӧ����¼��ָ��
	CMementor* m_mementor;
};



class CMementorMgr
{
public:

	CMementorMgr(); 
	~CMementorMgr();

	bool SetMemento(std::string strName,IMemento* memento);

	IMemento* GetMemento(std::string strName);
private:

	std::map<std::string, IMemento* > m_mementorContainer;
};



void TestMemento();


