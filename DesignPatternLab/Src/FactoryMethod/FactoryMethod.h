#pragma once
#include <iostream>
#include <string>

/**
*	工厂方法定义一个用于创建对象的接口，让子类决定实例化那一个类，Factory Method 
*  使一个类的实例延迟到其子类。 用不同文件的导出格式作为例子
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
		//! 创建实例工厂方法
		IExportFileApi* factoryMethod() override;

	};


	class ExportDBOperate : public IExportOperate
	{
	public:
		ExportDBOperate()  = default;
		~ExportDBOperate() = default;

	protected:
		//! 创建实例工厂方法
		IExportFileApi* factoryMethod() override;

	};


	void TestFactoryMethod();


}