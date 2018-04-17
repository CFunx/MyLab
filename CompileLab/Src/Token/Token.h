#pragma once
#include <vector>

/*
* �Ǻ�(token):�������ͺ�ֵ��ɱ���<Integer,1>  <Operation,+> 
* �ʷ���������lexer��: �ǽ�������ַ������������γ�һϵ�е�token�Ĳ���
* 
* 1. ʵ�ֵ�������֮��ļӷ����磺1+1; 1+2; �����������ı��ʽ�������ֱ��ʽ��ʵ����
  ���еķ��Ű�������һ�������֣�0-9������һ�����ַ���'+',' '���������
  �ڽ��з��������token��ʱ����������ַ�����ʶ������ֺͷ��ţ�һ����ͨ��ö�ٵķ�ʽ�Ͼ����Ų��Ǻܶ࣬
  ��һ�ַ�ʽ�ǣ��ж�ÿ�����������ֻ����ַ������ڱ����ķ�ʽ������
  
  2.ͨ���ʷ�����֮�����ǵõ��˺ܶ��token֮��Ĺ�����������Щtoken��Ѱ��һ��ģʽ��integer + integer��
  ����ģʽ��Ȼ������ģʽת���ɾ���ı��ʽ�����м��㡣

  TODO:֧�ּӼ��˳������ŵ����������Ļ������
	1. ʶ������λ����������������������С��
	2. ��θ�������AST
	3. ���ȼ���֧��

* 
*
*/


//! �ո��ASCIIֵ
#define MY_SPACE  32


typedef enum emTokenType
{
	EM_TOKEN_INTEG = 0, //!< ����
	EM_TOKEN_PLUS,      //!< �Ӻ�
	EM_TOKEN_SUB,       //!< ����
	EM_TOKEN_MUL,       //!< �˺�
	EM_TOKEN_DIV        //!< ����
}EM_TOKEN_TYPE;


typedef struct tagToken
{
	EM_TOKEN_TYPE  type;
	char           value;

}TOKEN;


//! �ʷ�����������������ַ����ֽ��token
class CLexer
{
public:
	CLexer();
	~CLexer();
	
	CLexer(const CLexer&) = delete;
	CLexer& operator=(const CLexer&) = delete;

	bool Parse(const char* text);

	std::vector<TOKEN>& GetToken();
private:
	
	void GenerateToken(char input);
	void SaveToken(EM_TOKEN_TYPE type, char value);
private:

	std::vector<TOKEN> m_tokens;
};



class CInterpreter
{
public:

	CInterpreter();
	~CInterpreter();

	CInterpreter(const CInterpreter&) = delete;
	CInterpreter& operator=(const CInterpreter&) = delete;

	//! �﷨����
	bool Interpreter(const std::vector<TOKEN>& token,
		std::string strMatchModel = "+");

	int GetResult();
private:

	void Add(int n);
private:

	int m_result;
};


void TestToken();