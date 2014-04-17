#include "embedded.hpp"

class WithEmbeddedDPtr::Self
{
public:
	void doStuff()
	{
		i++;
	}
private:
	int i;
};

WithEmbeddedDPtr::WithEmbeddedDPtr() : self()
{
}

WithEmbeddedDPtr::~WithEmbeddedDPtr()
{
}

void WithEmbeddedDPtr::doStuff()
{
	self->doStuff();
}
