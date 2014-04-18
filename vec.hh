#ifndef STUD_VEC_H
#define STUD_VEC_H

#include <vector>

#include "obj.hh"

namespace stud
{

class vec : public obj
{

public:

	void write(std::ostream & os)
	{
		os << '[';
		size_t len = m_vec.size();

		for(size_t i = 0; i < len-1; i++)
		{
			m_vec[i]->write(os);
			os << ',' << ' ';
		}

		m_vec[len-1]->write(os);

		os << ']';
	}

	template<typename Iter>
	static vec * make_vec(Iter begin, Iter end)
	{
		return new vec(begin, end);
	}

	static vec * make_vec()
	{
		return new vec();
	}

	void push_back(obj *p)
	{
		m_vec.push_back(p);
	}


private:
	
	template<typename Iter>
	vec(Iter begin, Iter end) : m_vec(begin, end) {}

	vec() : m_vec() {}

	std::vector<obj*> m_vec;

};

}

#endif
