#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie
{
	public:

		Zombie();
		~Zombie();
		void		announce(void);
		static std::string	getName(int n);
		static std::string	getType(int n);
		
	private:

		static std::string names[5];
		static std::string types[5];
		std::string	_type;
		std::string _name;
};
#endif