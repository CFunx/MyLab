#include "State/State.h"
#include "Proxy/Proxy.h"
#include "Facade/Facade.h"
#include "Bridge/Bridege.h"
#include "Command/Command.h"
#include "Visitor/Visitor.h"
#include "Memento/Memento.h"
#include "Builder/Builder.h"
#include "Adapter/Adapter.h"
#include "Observer/Observer.h"
#include "Iterator/Iterator.h"
#include "Strategy/Strategy.h"
#include "Mediator/Mediator.h"
#include "Prototype/Prototype.h"
#include "Composite/Composite.h"
#include "Decorator/Decorator.h"
#include "FlyWeight/FlyWeight.h"
#include "AbsFactory/AbsFactory.h"
#include "FactoryMethod/FactoryMethod.h"
#include "TemplateMethod/TemplateMethod.h"
#include "ChainOfResponsibility/ChainOfResponsibility.h"


int main(int argc, char* argv[])
{
	nsFacade::TestFacade();
	getchar();
	return 0;
}