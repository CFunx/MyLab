#pragma once
#include <iostream>


class CMsgSender
{
public:
	virtual void Send(std::string strSenderName, 
		std::string strSenderTxt) = 0;
};


class CWechatSender : public CMsgSender
{
public:
	void Send(std::string strSenderName,
		std::string strSenderTxt);
	
};


class CEmailSender : public CMsgSender
{
public:
	void Send(std::string strSenderName,
		std::string strSenderTxt);

};




/**
* ��Ϣ�ĳ����࣬�����ж�����Ϣ��ʵ���ϴ����൱�ڰ�
  Msg��sender�������������������һ���Žӵ�����
  ��ʱ���Խ���������������������ϲ�����CAbstractMsg�������
  �����Ե��е㲻ֱ��
*/
class CAbstractMsg
{
public:
	CAbstractMsg(CMsgSender* msgSender);

	virtual ~CAbstractMsg();
	virtual void SendMsg(std::string strSenderName,
		std::string strSenderTxt);


protected:

	//! �˴����ǽ���Ϣ�ķ����ߣ��Ͳ�ͬ����Ϣ������������
	CMsgSender* m_MsgSender;
};



/**
   \brief ʵ���Ͼ��ǽ���ͬ�ķ��ͷ�����װ����������ص���Ϣ
*/
class CTxtMsg : public CAbstractMsg
{
public:
	
	CTxtMsg(CMsgSender* msgSender);

	void SendMsg(std::string strSenderName,
		std::string strSenderTxt);
};

class CBinaryMsg : public CAbstractMsg
{
public:

	CBinaryMsg(CMsgSender* msgSender);

	void SendMsg(std::string strSenderName,
		std::string strSenderTxt);

};


void TestBridge();


