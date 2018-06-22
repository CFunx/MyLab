#include "FactoryMethod.h"


namespace nsFactoryMethod
{
	void CExportTxtFile::exPort(std::string strConTent)
	{
		std::cout << "Txt file was exPort:" << strConTent << "\n";
	}

	void CExportDBFile::exPort(std::string strConTent)
	{
		std::cout << "DB file was exPort:" << strConTent << "\n";
	}


	void IExportOperate::exPort(std::string strContent)
	{
		IExportFileApi* file = factoryMethod();
		file->exPort(strContent);
		
		delete file;
		file = nullptr;
	}

	IExportFileApi* ExportTxtOperate::factoryMethod()
	{
		return  new CExportTxtFile();
	}


	IExportFileApi* ExportDBOperate::factoryMethod()
	{
		return  new CExportDBFile();
	}


	void TestFactoryMethod()
	{
		IExportOperate& test1 = ExportDBOperate();
		test1.exPort("test1");

		IExportOperate& test2 = ExportTxtOperate();
		test2.exPort("test2");
	}
}