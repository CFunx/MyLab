#pragma once
#include <iostream>
#include <utility>


template<typename T>
class CTmpCl;

template<typename T>
void swap(CTmpCl<T>& lh, const CTmpCl<T>& rh) noexcept;

template<typename T>
class CTmpCl
{
public:
	CTmpCl(const T& param);
	~CTmpCl();

	CTmpCl(CTmpCl<T>&& cmcl) noexcept;
	CTmpCl(const CTmpCl<T>& cmcl);
	
	CTmpCl<T>& operator=(CTmpCl<T>&& cmcl) noexcept;
	CTmpCl<T>& operator=(const CTmpCl<T>& cmcl);

	void Display(T t);

	//! �Զ�Ӧ�Ľ�������
	//!http://en.cppreference.com/w/cpp/language/friend
	friend void swap<>(CTmpCl& lh, const CTmpCl& rh) noexcept;
private:

	T m_a;
};

template<typename T>
inline void swap(CTmpCl<T>& lh, const CTmpCl<T>& rh) noexcept
{
	lh.m_a = rh.m_a;
	std::cout << "My selfdefinition swap\n";
}


template<typename T>
CTmpCl<T>::CTmpCl(const T& param)
	: m_a(param)
{
	std::cout << "CTmpCl() constructor\n";
}


template<typename T>
CTmpCl<T>::~CTmpCl()
{
	std::cout << "~CTmpCl() \n";
}


template<typename T>
CTmpCl<T>::CTmpCl(CTmpCl<T>&& cmcl) noexcept
{
	m_a = cmcl.m_a;

	//! ���ݾ�������ѡ����Ӧ�����ٲ���
	cmcl.m_a = 0;
	std::cout << "move constructor" << std::endl;
}


template<typename T>
CTmpCl<T>::CTmpCl(const CTmpCl<T>& cmcl)
	:m_a(cmcl.m_a)
{
	//this->m_a = cmcl.m_a;
	std::cout<< "copy constructor" << std::endl;
}


template<typename T>
CTmpCl<T>& CTmpCl<T>::operator=(const CTmpCl<T>& cmcl)
{
	using std::swap;
	swap(*this, cmcl);
	std::cout << "operator =\n";
	return *this;
}


template<typename T>
CTmpCl<T>& CTmpCl<T>::operator=(CTmpCl<T>&& cmcl)noexcept
{
	/**
	����ǰ�������д�Ļ� T ����֧�� move operator=
	����ĿǰT��֧�� move operator ���Բ�����ôд
	*/
	//m_a = std::move(cmcl.m_a);
	m_a = cmcl.m_a;
	cmcl.m_a = 0;
	std::cout << "move operator=\n";
	return *this;
}


template<typename T>
void CTmpCl<T>::Display(T t)
{
	std::cout << "t value :" << t << std:endl;
}


//! �ػ�
template<>
class CTmpCl<double>
{
public:
	void DisPlay(double t);
};


void TestCTmpCl();
