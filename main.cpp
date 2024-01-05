#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <algorithm>
#include <filesystem>
using namespace std;

string to_upper(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

void	create_h(string file_name)
{
	std::filesystem::create_directory("includes");
	ofstream hpp(("includes/" + file_name + ".hpp").c_str());

	hpp << "#ifndef " << to_upper(file_name) + "_HPP" << endl;
	hpp << "#define " << to_upper(file_name) + "_HPP" << endl;
	hpp << endl;
	hpp << "#include <iostream>" << endl;
	hpp << endl;
	hpp << "class " << file_name << endl;
	hpp << "{" << endl;
	hpp << "	private:" << endl;
	hpp << "		" << endl;
	hpp << "	public:" << endl;
	hpp << "		" << file_name << "();" << endl;
	hpp << "		virtual ~" << file_name << "();" << endl;
	hpp << "		" << file_name << "(const " << file_name << " &cpy);" << endl;
	hpp << "		" << file_name << "&	operator=(const " << file_name << " &objs);" << endl;
	hpp << "};" << endl;
	hpp << endl;
	hpp << "#endif" << endl;
}

void	create_c(string file_name)
{
	std::filesystem::create_directory("srcs");
	ofstream cpp(("srcs/" + file_name + ".cpp").c_str());

	cpp << "#include \"../includes/" << file_name << ".hpp\"" << endl;
	cpp << "" << endl;
	cpp << "" << file_name << "::" << file_name << "()" << endl;
	cpp << "{" << endl;
	cpp << "	std::cout << \"Default " << file_name << " constructor called\" << std::endl;" << endl;
	cpp << "}" << endl;
	cpp << "" << endl;
	cpp << "" << file_name << "::~" << file_name << "()" << endl;
	cpp << "{" << endl;
	cpp << "	std::cout << \"" << file_name << " Destructor called\" << std::endl;" << endl;
	cpp << "}" << endl;
	cpp << "" << endl;
	cpp << "" << file_name << "::" << file_name << "(const " << file_name << " &cpy)" << endl;
	cpp << "{" << endl;
	cpp << "	std::cout << \"Copy constructor called\" << std::endl;" << endl;
	cpp << "	*this = cpy;" << endl;
	cpp << "}" << endl;
	cpp << "" << endl;
	cpp << "" << file_name << "& " << file_name << "::operator=(const " << file_name << " &objs)" << endl;
	cpp << "{" << endl;
	cpp << "	std::cout << \"Copy assignment operator called\" << std::endl;" << endl;
	cpp << "	return *this;" << endl;
	cpp << "}" << endl;
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		create_h(av[1]);
		create_c(av[1]);
	}
}