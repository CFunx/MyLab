#include "Token.h"
#include <limits.h>
#include <iostream>


CLexer::CLexer()
{
	m_tokens.clear();
}



CLexer::~CLexer()
{


}


bool CLexer::Parse(const char* text)
{
	if (nullptr == text)
	{
		return false;
	}

	while (*text)
	{
		if (*text != ' ')
		{
			GenerateToken(*text);
		}

		++text;
	}

	return true;
}


std::vector<TOKEN>& CLexer::GetToken()
{
	return m_tokens;
}


//! TODO: ���ʶ����������֣���
//! ���ʽ֮���л��У��հ׷��������������ַ����µı��ʽ����ȷ�����
//! ������ת�� https://codereview.stackexchange.com/questions/45755/implementation-of-atoi
void CLexer::GenerateToken(char input)
{
	switch (input)
	{
	case '0':
		SaveToken(EM_TOKEN_INTEG, input);
		break;
	case '1':
		SaveToken(EM_TOKEN_INTEG, input);
		break;
	case '2':
		SaveToken(EM_TOKEN_INTEG, input);
		break;
	case '3':
		SaveToken(EM_TOKEN_INTEG, input);
		break;
	case '4':
		SaveToken(EM_TOKEN_INTEG, input);
		break;
	case '5':
		SaveToken(EM_TOKEN_INTEG, input);
		break;
	case '6':
		SaveToken(EM_TOKEN_INTEG, input);
		break;
	case '7':
		SaveToken(EM_TOKEN_INTEG, input);
		break;
	case '8':
		SaveToken(EM_TOKEN_INTEG, input);
		break;
	case '9':
		SaveToken(EM_TOKEN_INTEG, input);
		break;
	case '+':
		SaveToken(EM_TOKEN_PLUS, input);
		break;

	default:
		break;
		INT_MIN;
	}

}


void CLexer::SaveToken(EM_TOKEN_TYPE type, char value)
{
	TOKEN token;
	token.type = type;
	token.value = value;

	switch (type)
	{
	case EM_TOKEN_INTEG:
		
		std::cout << "< " << "int " << "," << value << ">\n";
		break;
	case EM_TOKEN_PLUS:
		
		std::cout << "< " << "+ " << "," << value << ">\n";
		break;
	default:
		break;
	}

	m_tokens.push_back(token);
}


CInterpreter::CInterpreter()
	:m_result(0)
{

}


CInterpreter::~CInterpreter()
{

}


//!TODO: ��ν�����ص�ģʽƥ��???
bool CInterpreter::Interpreter(const std::vector<TOKEN>& token,
	std::string strMatchModel /*= "+"*/)
{
	int i = 1;
	auto it = token.begin();
	for (; it != token.end(); it++, i++)
	{
		if ((i % 2 != 0) && it->type == EM_TOKEN_INTEG)
		{
			Add(atoi(&(it->value)));
		}
	}

	return true;
}


void CInterpreter::Add(int n)
{
	m_result += n;
}


int CInterpreter::GetResult()
{
	return m_result;
}


void TestToken()
{
	char* exp = "1+3";

	//! �ʷ�������
	CLexer lexer;
	lexer.Parse(exp);


	//! ��ȡȥTokens 
	std::vector<TOKEN> tmpTokens = lexer.GetToken();


	//! �������н����﷨������Ľ���
	CInterpreter inter;
	inter.Interpreter(tmpTokens);


	//! ������
	std::cout << exp << "=" << inter.GetResult() << "\n";
}