import os

def create_class_files(class_name):
	#push ctrl alt H
	
    # Create header file content
    header_content = f"""#ifndef {class_name.upper()}_HPP
#define {class_name.upper()}_HPP

#include <iostream>
#include <string>

class {class_name} {{
	private:
	    // Add your private members here

	public:
	    {class_name}();
		{class_name}(const {class_name}& other);
        {class_name} &operator=(const {class_name} &other);
	    ~{class_name}();
	
}};

#endif //
"""

    # Create source file content
    source_content = f"""#include "{class_name}.hpp"

{class_name}::{class_name}() {{
    std::cout << "{class_name} Default constructor called" << std::endl;
    return ;
}}


{class_name}::{class_name}(const {class_name} &other) {{
    std::cout << "{class_name} Copy constructor called" << std::endl;
    (void) other;
    return ;
}}


{class_name} &{class_name}::operator=(const {class_name} &other) {{
    std::cout << "{class_name} Assignment operator called" << std::endl;
    if (this != &other)
        this->"" = other."";
    return *this;
}}


{class_name}::~{class_name}() {{
    std::cout << "{class_name} Default destructor called" << std::endl;
    return ;
}}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

"""

    # Write header file
    with open(f"{class_name}.hpp", "w") as header_file:
        header_file.write(header_content)

    # Write source file
    with open(f"{class_name}.cpp", "w") as source_file:
        source_file.write(source_content)

    print(f"Class {class_name} created with {class_name}.hpp and {class_name}.cpp")

if __name__ == "__main__":
    class_name = input("Enter the class name: ")
    create_class_files(class_name)