#pragma once
#include <vector>

/*
* 记号(token):是由类型和值组成比如<Integer,1>  <Operation,+> 
* 词法分析器（lexer）: 是将读入的字符串经过分析形成一系列的token的部分
* 
* 1. 实现单个数字之间的加法例如：1+1; 1+2; 类似于这样的表达式，在这种表达式中实际上
  所有的符号包括两类一类是数字（0-9），另一类是字符（'+',' '）这类符号
  在进行分析上面的token的时候可以有两种方法来识别出数字和符号，一种是通过枚举的方式毕竟符号不是很多，
  另一种方式是：判断每个符号是数字还是字符类似于遍历的方式来进行
  
  2.通过词法分析之后我们得到了很多的token之后的工作就是在这些token中寻找一种模式（integer + integer）
  这种模式，然后将这种模式转换成具体的表达式来进行计算。

  TODO:支持加减乘除和括号的任意整数的混合运算
	1. 识别任意位数的整数，包括正负数，小数
	2. 如何根据生成AST
	3. 优先级的支持

* 
*
*/


//! 空格键ASCII值
#define MY_SPACE  32


typedef enum emTokenType
{
	EM_TOKEN_INTEG = 0, //!< 数字
	EM_TOKEN_PLUS,      //!< 加号
	EM_TOKEN_SUB,       //!< 减号
	EM_TOKEN_MUL,       //!< 乘号
	EM_TOKEN_DIV        //!< 除号
}EM_TOKEN_TYPE;


typedef struct tagToken
{
	EM_TOKEN_TYPE  type;
	char           value;

}TOKEN;


//! 词法分析器，将读入的字符串分解成token
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

	//! 语法分析
	bool Interpreter(const std::vector<TOKEN>& token,
		std::string strMatchModel = "+");

	int GetResult();
private:

	void Add(int n);
private:

	int m_result;
};


void TestToken();