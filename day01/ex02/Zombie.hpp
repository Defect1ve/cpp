#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie
{
	public:

		~Zombie();
		void		announce(void);
		void		setName(std::string str);
		std::string	getName(void);
		void		setType(std::string str);
		std::string	getType(void);
		
	private:

		std::string	_type;
		std::string _name;
};
#endif