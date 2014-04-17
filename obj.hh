#ifndef STUD_OBJ_H
#define STUD_OBJ_H

#include <iostream>
#include <cstdlib>
#include <map>
#include <utility>

namespace stud
{
	static size_t mem_used = 0;

	static std::map<void*,size_t> allocs;


	class obj
	{

		public:

			void * operator new(size_t n)
			{
				std::cerr << "allocate(" << n << ")" << std::endl;
				void *p = malloc(n);
				if(0 == p)
				{
					std::cerr << "malloc() returned null";
					exit(EXIT_FAILURE);
				}
				allocs.insert(std::make_pair(p, n));
				mem_used += n;
				return p;
			}

			void operator delete(void *p)
			{
				auto it = allocs.find(p);
				if(it == allocs.end())
				{
					std::cerr << "unknown pointer in delete: " << p << std::endl;
					exit(EXIT_FAILURE);
				}
				size_t n = it->second;
				free(p);	
				allocs.erase(it);
				mem_used -= n;
				std::cerr << "deleted " << n << " bytes at " << p << std::endl;
			}

			virtual void write(std::ostream & os) = 0;

			virtual ~obj()
			{

			}

		private:

	};


}

#endif
