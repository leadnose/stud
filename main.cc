#include <iostream>

#include "obj.hh"
#include "fixnum.hh"
#include "str.hh"

int main()
{
	using namespace std;
	using namespace stud;
	
	fixnum *p = fixnum::make_fixnum(666);
	p->write(cout);

	str *s = str::make_str("hello, world\n");
	s->write(cout);
}

