#pragma once
#include <iostream>
#include <vector>

/**
	���ģʽ��Ҫ��������"Ҷ�Ӷ���"��"��϶���"ʱ�Ĺ�ϵ,�������ֶ���Ľӿڽ���ͳһ��һ����������
	�����Ͳ���Ҫ������Ҷ�ӻ�����϶����������̶�������ͳһ�ķ��ʷ�ʽ��
*/


namespace Composite
{

	//! �������Ҷ�ӽڵ����϶���ӿڵļ���
	class IComponent
	{
	public:
		IComponent() = default;
		virtual ~IComponent() = default;

		//! ��Ͻڵ���Ҫ�Ľӿڣ�Ҷ�ӽڵ�ʵ�����ǲ���Ҫ��
		virtual void SetChild(IComponent* component);

		//! ��ӡ��ؽṹ������
		virtual void PrintStruct();

	};


	class CComposite : public IComponent
	{
	public:
		CComposite(std::string strName);
		~CComposite();

		void SetChild(IComponent* component) override;

		void PrintStruct() override;
	private:

		std::string m_comName;

		std::vector<IComponent*> m_comCotainers;

	};


	class CLeaf : public IComponent
	{
	public:
		CLeaf(std::string strName);
		~CLeaf();

		void PrintStruct() override;

	private:
		std::string m_comName;
	};


	void TestComposite();
}