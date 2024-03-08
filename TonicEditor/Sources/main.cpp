#include <iostream>
#include "Core/Applications/AppEditor.hpp"
using namespace Core::Applications;
 
int main(int argc, char** argv)
{
	std::cout << "argc = " << argc << ";\n";

	for (int i = 0; i < argc; i++)
	{
		std::cout << argv[i] << std::endl;
	}
	AppEditor app("Tonic Editor");

	try
	{
		app.Run();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}