#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
	private:
	    std::string ideas[100];
		int size;

	public:
	    Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
	    ~Brain();

		std::string getIdea(int index) const;
		void addIdea(std::string idea);
};

#endif //
