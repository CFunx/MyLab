#pragma  once
#include <iostream>
#include <string>

/**
	������ģʽ(Builder)���ǽ�һ������Ĺ��������ʾ���룬ʹ��ͬ���Ĺ������̿��Դ���
	��ͬ�ı�ʾ����Ҫ��������ͬ�Ĳ��赫��ÿ�������ʵ���ǲ�ͬ�����
*/

namespace nsBuilder
{
	//! ��������Ҫ������Լ����������Ľӿڣ��Լ����������װ����
	//! ����װ�õ������װ����Ʒ��ȥ
	class IBuilder
	{
	public:
		virtual void CreateName(std::string strName) = 0;
		virtual void BeautifyName() = 0;
		virtual std::string GetName() = 0;
	};



	//! �����ʵ����A,��Ҫʵ��
	class CBuilderA : public IBuilder
	{
	public:
		CBuilderA();
		~CBuilderA() = default;
		
		void CreateName(std::string strName) override;
		void BeautifyName() override;
		std::string GetName() override;

	private:

		//! �������Ĳ�Ʒ
		std::string m_ProductName;
	};


	class CBuilderB : public IBuilder
	{
	public:
		CBuilderB();
		~CBuilderB() = default;

		void CreateName(std::string strName) override;
		void BeautifyName() override;
		std::string GetName() override;
	private:
		//! �������Ĳ�Ʒ
		std::string  m_ProductName;
	};


	//! ָ������������������װ�����ߣ������Ǹ���ĳ������
	//! �����ò�ͬ�Ĳ���,�ڸ��ӵ�����»�Ҫ��Builder������ͨ��
	//��ʵ����Director���Ǹ���������װ��Ʒ�Ĺ���
	class CDirector
	{
	public:
		CDirector()= default;
		~CDirector() = default;
		void SetBuilder(IBuilder* builder);
		void Constructor(std::string strName);
	private:
		IBuilder* m_builder;
	};


	void TestBuilder();

}