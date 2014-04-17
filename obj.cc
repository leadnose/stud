#include "obj.hh"

namespace stud
{

void obj::write(std::ostream & os)
{
	os << "#<obj@" << (void*) this << '>';
}

obj::~obj()
{

}

}
