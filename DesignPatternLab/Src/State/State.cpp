#include "State.h"
#include <assert.h>

void ConcreteStateA::Handle(std::string strStateID)
{
	assert(!strStateID.empty());
	std::cout << __func__ << " I am " << strStateID.c_str() << std::endl;
}


void ConcreteStateB::Handle(std::string strStateID)
{
	assert(!strStateID.empty());
	std::cout << __func__ << " I am " << strStateID.c_str() << std::endl;
}


bool ContextState::Init(std::string strStateA,
	std::string strStateB)
{
	if (strStateA.empty() || strStateB.empty())
	{
		return false;
	}

	IStste* sta = new ConcreteStateA;
	IStste* stb = new ConcreteStateB;

	m_state.insert(std::pair<std::string, IStste*>(strStateA, sta));
	m_state.insert(std::pair<std::string, IStste*>(strStateB, stb));

	return true;
}


bool ContextState::Destory()
{
	auto it = m_state.begin();
	for (; it != m_state.end(); it++)
	{
		delete it->second;
		it->second = nullptr;
	}
	return true;
}


void ContextState::MakeChoice(std::string strStateID)
{
	IStste* S = (m_state.at(strStateID));
	S->Handle(strStateID);
}



void TestState()
{
	ContextState cstate;
	cstate.Init("Sa", "Sb");

	cstate.MakeChoice("Sa");
	cstate.MakeChoice("Sb");

	cstate.Destory();
}