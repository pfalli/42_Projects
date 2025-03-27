#include "Brain.hpp"

Brain::Brain() {
    size = 0;
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {{
    std::cout << "Brain Copy constructor called" << std::endl;
	*this = other;
}}


Brain &Brain::operator=(const Brain &other) {{
    std::cout << "Brain Assignment operator called" << std::endl;
    for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	this->size = other.size;
	return (*this);
    
}}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
    return ;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

std::string Brain::getIdea(int index) const
{
	if(index < 0 || index > 99 || this->ideas[index] == "")
    {
        std::cout << "Idea does not exist" << std::endl;
        return "";
    }
	return (this->ideas[index]);
}

void Brain::addIdea(std::string idea)
{
	if (size == 100){
		std::cout << "Maximum 100 ideas. Brain is full!" << std::endl;
		return;
	}
	this->ideas[size++] = idea;
}