#include "Bridege.h"



void CWechatSender::Send(std::string strSenderName,
	std::string strSenderTxt)
{
	std::cout << "WechatSender---by:" << strSenderName.c_str()
		<< "---" << strSenderName.c_str() << std::endl;
}



void CEmailSender::Send(std::string strSenderName,
	std::string strSenderTxt)
{
	std::cout << "EmailSender---by:" << strSenderName.c_str()
		<< "---" << strSenderTxt.c_str() << std::endl;
}



CAbstractMsg::CAbstractMsg(CMsgSender* msgSender)
	:m_MsgSender(msgSender)
{
	std::cout << "CAbstractMsg ctor\n";
}
	
CAbstractMsg::~CAbstractMsg()
{
	std::cout << "CAbstractMsg dtor\n";
}


void CAbstractMsg::SendMsg(std::string strSenderName,
	std::string strSenderTxt)
{
	m_MsgSender->Send(strSenderName, strSenderTxt);
}



CTxtMsg::CTxtMsg(CMsgSender* msgSender)
	:CAbstractMsg(msgSender)
{

}


void CTxtMsg::SendMsg(std::string strSenderName,
	std::string strSenderTxt)
{
	std::cout << "CTxtMsg::SendMsg\n";
	m_MsgSender->Send(strSenderName, strSenderTxt);
}




CBinaryMsg::CBinaryMsg(CMsgSender* msgSender)
	:CAbstractMsg(msgSender)
{

}


void CBinaryMsg::SendMsg(std::string strSenderName,
	std::string strSenderTxt)
{
	std::cout << "Binary::SendMsg\n";
	m_MsgSender->Send(strSenderName, strSenderTxt);
}




void TestBridge();







void TestBridge()
{
	//! ������Ϣ�ķ��ͷ�ʽ
	CMsgSender* msgSender = new CWechatSender();

	//! ������Ϣ�ĸ�ʽ���ı�
	CAbstractMsg* msg = new CTxtMsg(msgSender);


	msg->SendMsg("Tony", "Hello, how are you!!\n");

	delete msgSender;
	delete msg;

}