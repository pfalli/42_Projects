#include <iostream>
#include <string>
#include "Base.hpp"


int	main()
{
	Base *form;

	form = generate();
	identify(form);
	identify(*form);
	delete form;

}