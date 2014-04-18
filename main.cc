#include <iostream>
#include <vector>

#include "obj.hh"
#include "fixnum.hh"
#include "str.hh"
#include "module.hh"
#include "osp.hh"

int main()
{
	using namespace std;
	using namespace stud;

	osp<fixnum> p = fixnum::make_fixnum(666);
	p->write(cout);

	osp<str> s = str::make_str("hello, world\n");
	s->write(cout);

	vector<pair<string,obj*> > syms;

	osp<module> m = module::make_module("testi-moduuli", syms);
	m->write(cout);

}

