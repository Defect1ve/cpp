# include <string>
# include <fstream>
# include <sstream>
# include <iostream>

int		main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./replace filename s1 s2" << std::endl;
		return (0);
	}
	std::ifstream	ifs(argv[1]);
	std::ofstream	ofs((std::string)argv[1] + (std::string)".replace");
	std::stringstream ss;
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	std::string		str = "";
	size_t			pos = 0;

	ss << ifs.rdbuf();
	str = ss.str();
	ifs.close();
	if (!s1.empty())
	{
		while ((pos = str.find(s1, pos)) != std::string::npos)
		{
			str.replace(pos, s1.length(), s2);
			pos += s2.length();
		}
	}
	ofs << str;
	ofs.close();
}