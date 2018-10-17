#include "Contact.hpp"

	unsigned int	Contact::get_index(void)
	{
		return (this->index);
	}
	void			Contact::set_index(unsigned int n)
	{
		this->index = n;
	}
	std::string		Contact::get_first_name(void)
	{
		return (this->first_name);
	}
	void			Contact::set_first_name(std::string str)
	{
		this->first_name = str;
	}
	std::string		Contact::get_last_name(void)
	{
		return (this->last_name);
	}
	void			Contact::set_last_name(std::string str)
	{
		this->last_name = str;
	}
	std::string		Contact::get_nickname(void)
	{
		return (this->nickname);
	}
	void			Contact::set_nickname(std::string str)
	{
		this->nickname = str;
	}
	std::string		Contact::get_login(void)
	{
		return (this->login);
	}
	void			Contact::set_login(std::string str)
	{
		this->login = str;
	}
	std::string		Contact::get_post_addr(void)
	{
		return (this->post_addr);
	}
	void			Contact::set_post_addr(std::string str)
	{
		this->post_addr = str;
	}
	std::string		Contact::get_email_addr(void)
	{
		return (this->email_addr);
	}
	void			Contact::set_email_addr(std::string str)
	{
		this->email_addr = str;
	}
	std::string		Contact::get_phone_numb(void)
	{
		return (this->phone_numb);
	}
	void			Contact::set_phone_numb(std::string str)
	{
		this->phone_numb = str;
	}
	std::string		Contact::get_birthday_date(void)
	{
		return (this->birthday_date);
	}
	void			Contact::set_birthday_date(std::string str)
	{
		this->birthday_date = str;
	}
	std::string		Contact::get_favorite_meal(void)
	{
		return (this->favorite_meal);
	}
	void			Contact::set_favorite_meal(std::string str)
	{
		this->favorite_meal = str;
	}
	std::string		Contact::get_underwear_color(void)
	{
		return (this->underwear_color);
	}
	void			Contact::set_underwear_color(std::string str)
	{
		this->underwear_color = str;
	}
	std::string		Contact::get_darkest_secret(void)
	{
		return (this->darkest_secret);
	}
	void			Contact::set_darkest_secret(std::string str)
	{
		this->darkest_secret = str;
	}