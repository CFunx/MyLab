#include "Singleton.h"

namespace nsSinglton
{
	/////////////////////////////////Version1.0//////////////////////////////////
	//! singleton.cpp
	Singlton* Singlton::m_pSingle = nullptr;
	Singlton* Singlton::GetInstance()
	{
		if (!m_pSingle)
		{
			m_pSingle = new Singlton;
			return m_pSingle;
		}
		return m_pSingle;
	}

	void Singlton::DelInstance()
	{
		if (!m_pSingle)
		{
			return;
		}
		delete m_pSingle;
		m_pSingle = nullptr;
	}



	////////////////////////////////////Version1.1////////////////////////////////////
	SingltonV1* SingltonV1::m_pSingle = nullptr;
	SingltonV1* SingltonV1::GetInstance()
	{
		if (!m_pSingle)
		{
			try
			{
				m_pSingle = new SingltonV1;
				return m_pSingle;
			}
			catch (...)
			{
				return nullptr;
			}
		}

		return m_pSingle;
	}

	void SingltonV1::DelInstance()
	{
		if (!m_pSingle)
		{
			return;
		}
		delete m_pSingle;
		m_pSingle = nullptr;
	}



	//////////////////////////////////////version1.2///////////////////////////////////
	SingltonV2* SingltonV2::m_pSingle = nullptr;
	SingltonV2* SingltonV2::GetInstance()
	{
		if (!m_pSingle)
		{
			try
			{
				m_pSingle = new SingltonV2;
				return m_pSingle;
			}
			catch (...)
			{
				return nullptr;
			}
		}

		return m_pSingle;
	}

	void SingltonV2::DelInstance()
	{
		if (!m_pSingle)
		{
			return;
		}
		delete m_pSingle;
		m_pSingle = nullptr;
	}


	///////////////////////////////Version1.3/////////////////////////////////////
	CSingleton::Deleter CSingleton::deleter;
	CSingleton* CSingleton::_instance = nullptr;

	CSingleton* CSingleton::GetInstance()
	{
		if (!_instance)
		{
			try
			{
				_instance = new CSingleton;
				return _instance;
			}
			catch (...)
			{
				return nullptr;
			}
		}

		return _instance;

	}











	/////////////////////////////Version2.0/////////////////////////////////
	std::mutex smartSingleton::_mutex;

	std::shared_ptr<smartSingleton>& smartSingleton::getInstance()
	{
		static std::shared_ptr<smartSingleton> instance = nullptr;
		if (!instance)
		{
			std::lock_guard<std::mutex> lock(_mutex);
			if (!instance)
			{
				instance.reset(new smartSingleton());
			}
		}
		return instance;
	}

	/////////////////////////////Version2.1/////////////////////////////////
	std::once_flag safeSingleton::only_one;
	std::shared_ptr<safeSingleton>instance_(nullptr);






















	////////////////////////////////////////////////////////////

	LazySingleton* LazySingleton::m_pSingle = nullptr;
	LazySingleton* LazySingleton::GetInstance()
	{
		if (!m_pSingle)
		{
			//! 单例在第一次被使用的时候进行创建
			m_pSingle = new LazySingleton;
			return m_pSingle;
		}
		return m_pSingle;
	}

	void LazySingleton::DelInstance()
	{
		if (!m_pSingle)
		{
			return;
		}
		delete m_pSingle;
		m_pSingle = nullptr;
	}


	/////////////////////////////////////////////////////////////////////////

	InnerLazySingleton& InnerLazySingleton::GetInstance()
	{
		//local static initialization
		// before c++11 need lock 
		static InnerLazySingleton inLazySigleton; //========[1]
		return inLazySigleton;
	}

	//If multiple threads attempt to initialize the same static local variable concurrently, 
	//the initialization occurs exactly once
	//(similar behavior can be obtained for arbitrary functions with std::call_once).
	//Note: usual implementations of this feature use variants of the double-checked locking pattern,
	//which reduces runtime overhead for already-initialized local statics to a single non-atomic boolean comparison.
















	/////////////////////////////////////////////////////////////////////////////

	const HungrySingleton* HungrySingleton::m_HunSingleton
		= new HungrySingleton;

	const HungrySingleton* HungrySingleton::GetInstance()
	{
		return m_HunSingleton;
	}

	void HungrySingleton::DelSingleton()
	{
		if (nullptr != m_HunSingleton)
		{
			delete m_HunSingleton;
		}
	}

	/////////////////////////////////////////////////////////////////////////////
}