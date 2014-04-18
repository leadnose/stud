#ifndef STUD_READ_H
#define STUD_READ_H

#include <iostream>
#include <cctype>
#include <cstdio>

#include "obj.hh"

namespace stud
{

class read_exception : public std::exception
{
public:
	read_exception(const char *s) : m_what(s)
	{
	}
	const char * what() const
	{
		return m_what.c_str();
	}
private:
	const std::string m_what;
};

static fixnum * read_fixnum(std::istream & is)
{
	int i;
	is >> i;
	if(is)
		return fixnum::make_fixnum(i);
	else
		throw read_exception("reading fixnum failed");
}

static obj * read_stuff(std::istream & is)
{

}

static obj * read_vec(std::istream & is)
{

}

static obj * read_symbol(std::istream & is)
{

}




obj * read(std::istream & is)
{

	int ch = is.peek();

	while(isspace(ch = is.get()));

	if(EOF == ch)
		return 0;

	is.putback(ch);

	if('-' == ch || isdigit(ch))
		return read_fixnum(is);
	else if('{' == ch)
		return read_stuff(is);
	else if('[' == ch)
		return read_vec(is);
	else 
		return read_symbol(is);


}

#endif
