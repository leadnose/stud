#ifndef STUD_MODULE_H
#define STUD_MODULE_H

#include <string>
#include <map>
#include <vector>
#include <utility>

#include "obj.hh"

namespace stud
{

class module : public obj
{

public:

	virtual void write(std::ostream & os) 
	{
		os << "#<module " << m_name << " >";
	}

	static module * make_module(const std::string & name, 
					const std::vector<std::pair<std::string,obj*> > & syms)
	{
		return new module(name, syms);
	}

	virtual ~module()
	{

	}


private:

	explicit module(const std::string & name, 
			const std::vector<std::pair<std::string,obj*> > & syms)
		: m_name(name), m_symtab(syms.begin(), syms.end())
	{

	}

	const std::string m_name;

	std::map<std::string, obj*> m_symtab;

};

}

#endif 
