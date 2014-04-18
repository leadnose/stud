#include <iostream>
#include <vector>

#include "obj.hh"
#include "fixnum.hh"
#include "str.hh"
#include "module.hh"
#include "vec.hh"
#include "osp.hh"
#include "stuff.hh"

int main()
{
	using namespace std;
	using namespace stud;

	osp<vec> v = vec::make_vec();

	v->push_back(fixnum::make_fixnum(666));
	v->push_back(str::make_str("hello, world\n"));
	vector<pair<string,obj*> > syms;
	v->push_back(module::make_module("testi-moduuli", syms));
	v->write(cout);

	osp<keyword> k = keyword::get_keyword("Hello");
	osp<str> s = str::make_str("world!");
	vector<pair<keyword*,obj*>> ps;
	ps.push_back(make_pair(k.ptr(), s.ptr()));	
	osp<stuff> st = stuff::make_stuff(ps.begin(), ps.end());
	st->write(cout);
	
	
}

