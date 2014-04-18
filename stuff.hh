#ifndef STUD_STUFF_H
#define STUD_STUFF_H

#include <map>

#include "obj.hh"
#include "keyword.hh"

namespace stud
{

class stuff : public obj
{

public:

	template<typename Iter>
	static stuff * make_stuff(Iter begin, Iter end)
	{
		return new stuff(begin, end);
	}

	void write(std::ostream & os)
	{
		os << '{';

		for(auto p : m_map)
		{
			os << '\t';
			p.first->write(os);
			os << ": ";
			p.second->write(os);
			os << std::endl;	
		}
		

		os << '}';
	}
	

private:

	template<typename Iter>
	stuff(Iter begin, Iter end) : m_map(begin, end) {}

	std::map<keyword*, obj*> m_map;

};

}

#endif
