#ifndef STUD_OBJ_H
#define STUD_OBJ_H

#include <iostream>

namespace stud
{

class obj
{

public:

	virtual void write(std::ostream & os);

	virtual ~obj();

};

}

#endif
