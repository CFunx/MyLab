#include "State/State.h"
#include "Proxy/Proxy.h"
#include "Bridge/Bridege.h"
#include "Command/Command.h"
#include "Visitor/Visitor.h"
#include "Memento/Memento.h"
#include "Builder/Builder.h"
#include "Observer/Observer.h"
#include "Iterator/Iterator.h"
#include "Strategy/Strategy.h"
#include "Mediator/Mediator.h"
#include "Prototype/Prototype.h"
#include "Composite/Composite.h"
#include "Decorator/Decorator.h"
#include "FlyWeight/FlyWeight.h"
#include "TemplateMethod/TemplateMethod.h"
#include "ChainOfResponsibility/ChainOfResponsibility.h"


int main(int argc, char* argv[])
{
	nsBuilder::TestBuilder();
	getchar();
	return 0;
}