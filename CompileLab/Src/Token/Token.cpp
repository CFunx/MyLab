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


//! TODO: 如何识别任意的数字？？
//! 表达式之间有换行，空白符，甚至其他的字符导致的表达式不正确的情况
//! 整数的转化 https://codereview.stackexchange.com/questions/45755/implementation-of-atoi
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


//!TODO: 如何进行相关的模式匹配???
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

	//! 词法分析器
	CLexer lexer;
	lexer.Parse(exp);


	//! 获取去Tokens 
	std::vector<TOKEN> tmpTokens = lexer.GetToken();


	//! 解释其中进行语法和语义的解析
	CInterpreter inter;
	inter.Interpreter(tmpTokens);


	//! 输出结果
	std::cout << exp << "=" << inter.GetResult() << "\n";
}