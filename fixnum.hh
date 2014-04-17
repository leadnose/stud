#ifndef STUD_FIXNUM_H
#define STUD_FIXNUM_H

#include "obj.hh"

namespace stud
{

class fixnum : public obj
{

public:

	static fixnum * make_fixnum(int val)
	{
		return new fixnum(val);
	}

	virtual void write(std::ostream & os)
	{
		os << m_val;
	}


private:

	explicit fixnum(int val) : m_val(val) {}

	const int m_val;

};

}

#endif
