#pragma once

#include <memory>

template <typename T>
class Unique : public std::unique_ptr<T>
{
public:
	Unique() : std::unique_ptr<T>(new T())
	{
	}
	Unique(const Unique<T>& other) = default;
	~Unique() = default;
};

class WithUniqueDPtr
{
public:
	WithUniqueDPtr();
	~WithUniqueDPtr();
	void doStuff();
private:
	class Self;
	Unique<Self> self;
};
