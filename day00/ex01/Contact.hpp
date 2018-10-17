#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class	Contact{
	public:

	unsigned int	get_index(void);
	void			set_index(unsigned int n);
	std::string		get_first_name(void);
	void			set_first_name(std::string str);
	std::string		get_last_name(void);
	void			set_last_name(std::string str);
	std::string		get_nickname(void);
	void			set_nickname(std::string str);
	std::string		get_login(void);
	void			set_login(std::string str);
	std::string		get_post_addr(void);
	void			set_post_addr(std::string str);
	std::string		get_email_addr(void);
	void			set_email_addr(std::string str);
	std::string		get_phone_numb(void);
	void			set_phone_numb(std::string str);
	std::string		get_birthday_date(void);
	void			set_birthday_date(std::string str);
	std::string		get_favorite_meal(void);
	void			set_favorite_meal(std::string str);
	std::string		get_underwear_color(void);
	void			set_underwear_color(std::string str);
	std::string		get_darkest_secret(void);
	void			set_darkest_secret(std::string str);

	private:

	unsigned int	index;
	std::string		first_name;
	std::string		last_name;
	std::string		nickname;
	std::string		login;
	std::string		post_addr;
	std::string		email_addr;
	std::string		phone_numb;
	std::string		birthday_date;
	std::string		favorite_meal;
	std::string		underwear_color;
	std::string		darkest_secret;
};
#endif