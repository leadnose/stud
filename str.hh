#ifndef STUD_STR_H
#define STUD_STR_H

#include <string>

#include "obj.hh"

namespace stud
{

class str : public obj
{

public:

	static str * make_str(const std::string & val)
	{
		return new str(val);
	}

	virtual void write(std::ostream & os)
	{
		os << m_val;
	}

	virtual ~str()
	{

	}

private:

	explicit str(const std::string & val) : m_val(val) {}

	const std::string m_val;
	
};


}

#endif
