#pragma once

#include <iostream>
#include<mutex>
#include<memory>

namespace nsSinglton
{

	///////////////////////////////Version1.0/////////////////////////////////
	//!singleton.h
	class Singlton
	{
	public:
		static Singlton* GetInstance();
		static void      DelInstance();
		~Singlton() {}

	private:
		Singlton() {};

	private:
		static Singlton* m_pSingle;
	};










	///////////////////////////////Version1.1/////////////////////////////////
	//!singleton.h
	class SingltonV1
	{
	public:
		static SingltonV1* GetInstance();
		static void      DelInstance();


	private:
		SingltonV1() {};
		~SingltonV1()
		{
			std::cout << "11111" << std::endl;
		}


	private:
		static SingltonV1* m_pSingle;
	};












	///////////////////////////////Version1.2/////////////////////////////////
	//!singleton.h
	class SingltonV2
	{
	public:
		static SingltonV2* GetInstance();
		static void      DelInstance();

		//! c++11之后的方法 建议使用
		//SingltonV2(const SingltonV2&) = delete;
		//SingltonV2& operator=(const SingltonV2&) = delete;

	private:
		SingltonV2(const SingltonV2&);
		SingltonV2& operator=(const SingltonV2&);

		SingltonV2() {};
		~SingltonV2() {}


	private:
		static SingltonV2* m_pSingle;
	};






	///////////////////////////////Version1.3/////////////////////////////////
	class CSingleton
	{
	public:
		static CSingleton* GetInstance();
		void DoSomething() {}

	private:
		CSingleton() {}
		~CSingleton() {}

		CSingleton(const CSingleton&) = delete;
		CSingleton& operator=(const CSingleton&) = delete;

		static CSingleton* _instance;

	private:
		class Deleter
		{
		public:
			~Deleter()
			{
				if (CSingleton::_instance != nullptr)
				{
					delete CSingleton::_instance;
				}
			}
		};
		// 定义一个静态的Deleter实例
		static Deleter deleter;
	};

	/////////////////////////////Version2.0/////////////////////////////////

	class smartSingleton
	{
	public:
		static std::shared_ptr<smartSingleton>& getInstance();

		void demo() {}
		~smartSingleton() {};
	private:
		smartSingleton() {};
		smartSingleton(const smartSingleton& rs);
		smartSingleton& operator = (const smartSingleton& rs);

		static std::mutex _mutex;
	};

	/////////////////////////////Version2.1/////////////////////////////////
	class safeSingleton
	{
		static std::shared_ptr<safeSingleton>instance_;
		static std::once_flag only_one;

		safeSingleton(int id) {}
		safeSingleton(const safeSingleton& rs);
		safeSingleton& operator = (const safeSingleton& rs);

	public:
		~safeSingleton() {}
		static safeSingleton & getInstance(int id)
		{
			std::call_once(safeSingleton::only_one,
				[](int idx)
			{
				safeSingleton::instance_.reset(new safeSingleton(idx));
			}, id);

			return*instance_;
		}
	};


	////////////////////////////////////////////////////////////////////////////////







	//!	 静态成员变量懒汉模式
	class LazySingleton
	{
	public:
		static LazySingleton* GetInstance();
		static void  DelInstance();

	private:
		LazySingleton() {}
		~LazySingleton() {}

	private:
		static LazySingleton* m_pSingle;
	};









	/////////////////////////////////////////////////////////////////////////

	//!内部静态实例懒汉模式实现
	class InnerLazySingleton
	{
	public:
		static InnerLazySingleton& GetInstance();

	private:
		InnerLazySingleton() {}
		~InnerLazySingleton() {}

		//! 拷贝构造函数 和赋值构造函数设置为私有的 
		InnerLazySingleton(const InnerLazySingleton& innercopy);
		InnerLazySingleton& operator=(const InnerLazySingleton& in);
	};








	/////////////////////////////////////////////////////////////////////////

	//! 饿汉模式
	class HungrySingleton
	{
	public:
		static const HungrySingleton* GetInstance();
		static void DelSingleton();

	private:

	private:
		static const HungrySingleton* m_HunSingleton;

	};

}

/////////////////////////////////////////////////////////////////////