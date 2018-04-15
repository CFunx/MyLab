#pragma once
#include <iostream>
#include <map>

/**
*  \brief 备忘录模式，主要是利用李哥内部类将某个类的状态保存起来，同时
提供一个外部的类来管理或者是存储相应的状态，但是外部类不能够访问内部类的具体方法
*/



//! 备忘录的具体接口
class IMemento
{
public:
	
	//! 实现为空，其目的是阻止外部备忘录中的内容
	virtual void Donothing();
};




//! 需要备忘录的管理模块
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

	//! 存放相应备忘录的指针
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


