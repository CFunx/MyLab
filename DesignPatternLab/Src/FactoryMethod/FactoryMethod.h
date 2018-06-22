#pragma once
#include <iostream>
#include <string>

/**
*	������������һ�����ڴ�������Ľӿڣ����������ʵ������һ���࣬Factory Method 
*  ʹһ�����ʵ���ӳٵ������ࡣ �ò�ͬ�ļ��ĵ�����ʽ��Ϊ����
*/


namespace nsFactoryMethod
{
	class IExportFileApi
	{
	public:
		virtual void exPort(std::string strConTent) = 0;

	};


	class CExportTxtFile : public IExportFileApi
	{
	public:
		CExportTxtFile()  = default;
		~CExportTxtFile() = default;

		void exPort(std::string strConTent) override;
	};


	class CExportDBFile : public IExportFileApi
	{
	public:
		CExportDBFile()  = default;
		~CExportDBFile() = default;

		void exPort(std::string strConTent) override;
	};


	class IExportOperate
	{
	public:
		void exPort(std::string strContent);

	protected:
		virtual	IExportFileApi* factoryMethod() = 0;

	};


	class ExportTxtOperate : public IExportOperate
	{
	public:
		ExportTxtOperate() = default;
		~ExportTxtOperate() = default;

	protected:
		//! ����ʵ����������
		IExportFileApi* factoryMethod() override;

	};


	class ExportDBOperate : public IExportOperate
	{
	public:
		ExportDBOperate()  = default;
		~ExportDBOperate() = default;

	protected:
		//! ����ʵ����������
		IExportFileApi* factoryMethod() override;

	};


	void TestFactoryMethod();


}