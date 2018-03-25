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
* 消息的抽象类，可能有多种消息，实际上此类相当于把
  Msg和sender组合起来了这样就起到了一个桥接的作用
  此时可以借助第三方的类来进项组合不用在CAbstractMsg进行组合
  这样显得有点不直观
*/
class CAbstractMsg
{
public:
	CAbstractMsg(CMsgSender* msgSender);

	virtual ~CAbstractMsg();
	virtual void SendMsg(std::string strSenderName,
		std::string strSenderTxt);


protected:

	//! 此处就是将信息的发送者，和不同的信息连接起来的桥
	CMsgSender* m_MsgSender;
};



/**
   \brief 实际上就是将不同的发送方法包装起来，给相关的信息
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


