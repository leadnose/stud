#ifndef STUD_KEYWORD_H
#define STUD_KEYWORD_H

#include <map>
#include <string>

#include "obj.hh"

namespace stud
{

class keyword;

static std::map<std::string,keyword*> kwtab;

class keyword : public obj
{

public:

	static keyword * get_keyword(const std::string & name)
	{
		auto it = kwtab.find(name);
		if(it == kwtab.end())
		{
			keyword *k = new keyword(name);
			kwtab.insert(std::make_pair(name,k));
			return k;
		}
		else
		{
			return it->second;
		}
	}

	void write(std::ostream & os)
	{
		os << m_name;
	}

private:

	explicit keyword(const std::string & name) : m_name(name) {}

	std::string m_name;	

};

}

#endif
