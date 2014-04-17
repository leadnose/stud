#include <iostream>
#include <vector>

#include "obj.hh"
#include "fixnum.hh"
#include "str.hh"
#include "module.hh"

void stud_atexit()
{
	std::cerr << "memory still in use at exit: " << stud::mem_used << std::endl;
}

int main()
{
	using namespace std;
	using namespace stud;

	atexit(stud_atexit);
	
	fixnum *p = fixnum::make_fixnum(666);
	p->write(cout);

	str *s = str::make_str("hello, world\n");
	s->write(cout);

	vector<pair<string,obj*> > syms;

	module *m = module::make_module("testi-moduuli", syms);
	m->write(cout);

	delete p;
	delete s;
	delete m;
}

