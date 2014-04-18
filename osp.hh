#ifndef STUD_OSP_H
#define STUD_OSP_H

#include <vector>

namespace stud
{

// shared between all template specializations
static std::vector<obj*> stack;

template <typename T>
class osp
{

public:

	osp(T *p) : m_ptr(p)	
	{
		stack.push_back(p);
	}

	~osp()
	{
		stack.pop_back();
	}

	T & operator*()
	{
		return *m_ptr;
	}

	T * operator->()
	{
		return m_ptr;
	}

private:

	T *m_ptr;

};



}

#endif
