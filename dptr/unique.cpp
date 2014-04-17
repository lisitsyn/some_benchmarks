#include "unique.hpp"

class WithUniqueDPtr::Self
{
public:
	void doStuff()
	{
		i++;
	}
private:
	int i;
};

WithUniqueDPtr::WithUniqueDPtr() : self()
{
}

WithUniqueDPtr::~WithUniqueDPtr()
{
}

void WithUniqueDPtr::doStuff()
{
	self->doStuff();
}

