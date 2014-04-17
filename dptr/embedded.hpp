#pragma once

#include <memory>

template <typename T, int size>
class EmbeddedDPtr
{
public:
	EmbeddedDPtr() : storage()
	{
		static_assert(sizeof(T) <= size, "Can't embed object, expand keeper size");
		new (reinterpret_cast<void*>(storage)) T();
	}
	EmbeddedDPtr(const EmbeddedDPtr<T,size>& other) : storage()
	{
		new (reinterpret_cast<void*>(storage)) T(reinterpret_cast<const T&>(other.storage));
	}
	EmbeddedDPtr& operator=(const EmbeddedDPtr<T,size>& other) = delete;
	~EmbeddedDPtr()
	{
		reinterpret_cast<const T*>(storage)->~T();
	}
	T* operator->() const
	{
		return reinterpret_cast<T*>(const_cast<char*>(storage));
	}
private:
	char storage[size];
};

class WithEmbeddedDPtr
{
public:
	WithEmbeddedDPtr();
	~WithEmbeddedDPtr();
	void doStuff();
private:
	class Self;
	EmbeddedDPtr<Self, 4> self;
};
