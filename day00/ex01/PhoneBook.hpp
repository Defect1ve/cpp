#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include "Contact.hpp"

class	PhoneBook{
	public:

	PhoneBook();

	Contact			Contacts[8];
	unsigned int	get_records(void);
	void			incr_records(void);
	void			add();
	void			search();

	private:

	unsigned int	records;
};
#endif