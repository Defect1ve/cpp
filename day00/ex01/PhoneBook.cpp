#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook ()
{
	this->records = 0;
}

unsigned int	PhoneBook::get_records(void)
{
	return (this->records);
}
void			PhoneBook::incr_records(void)
{
	this->records++;
}

std::string		line_get()
{
	std::string		str;

	if (!getline(std::cin, str))
		exit(0);
	return (str);
}

void			PhoneBook::add(void)
{
	Contact		cont;
	std::string input;

	if (this->get_records() == 8)
	{
		std::cout << "Too much contacts(maximum is 8)\nExiting..." << std::endl;
		std::cin >> input;
		exit(0);
	}
	cont.set_index(this->get_records() + 1);
	std::cout << "Please, enter your first name: " << std::endl;
	cont.set_first_name(line_get());
	std::cout << "Please, enter your last name: " << std::endl;
	cont.set_last_name(line_get());
	std::cout << "Please, enter your nickname: " << std::endl;
	cont.set_nickname(line_get());
	std::cout << "Please, enter your login: " << std::endl;
	cont.set_login(line_get());
	std::cout << "Please, enter your post address: " << std::endl;
	cont.set_post_addr(line_get());
	std::cout << "Please, enter your email address: " << std::endl;
	cont.set_email_addr(line_get());
	std::cout << "Please, enter your phone number: " << std::endl;
	cont.set_phone_numb(line_get());
	std::cout << "Please, enter your birthday date: " << std::endl;
	cont.set_birthday_date(line_get());
	std::cout << "Please, enter your favorite meal: " << std::endl;
	cont.set_favorite_meal(line_get());
	std::cout << "Please, enter your underwear color: " << std::endl;
	cont.set_underwear_color(line_get());
	std::cout << "Please, enter your darkest secret: " << std::endl;
	cont.set_darkest_secret(line_get());
	this->Contacts[this->get_records()] = cont;
	this->incr_records();
}

void			display(std::string str)
{
	if (str.length() < 11)
		std::cout << std::setw(10) << str;
	else
	{
		str.resize(9);
		std::cout << str;
		std::cout << '.';
	}
}

void			PhoneBook::search(void)
{
	unsigned int	size;
	std::string		str;

	size = this->get_records();
	for (unsigned int i = 1; i <= size; i++)
	{
		display(std::to_string(this->Contacts[i - 1].get_index()));
		std::cout << "|";
		display(this->Contacts[i - 1].get_first_name());
		std::cout << "|";
		display(this->Contacts[i - 1].get_last_name());
		std::cout << "|";
		display(this->Contacts[i - 1].get_nickname());
		std::cout << std::endl;
	}
	if (!std::getline(std::cin, str))
		exit(0);
	size = std::atoi(str.c_str());
	if (size < 1 || size > this->get_records())
		std::cout << "Invalid input..." << std::endl;
	else
	{
		std::cout << "First name: " << this->Contacts[size - 1].get_first_name() << std::endl;
		std::cout << "Last name: " << this->Contacts[size - 1].get_last_name() << std::endl;
		std::cout << "Nickname: " << this->Contacts[size - 1].get_nickname() << std::endl;
		std::cout << "Login: " << this->Contacts[size - 1].get_login() << std::endl;
		std::cout << "Postal address: " << this->Contacts[size - 1].get_post_addr() << std::endl;
		std::cout << "Email address: " << this->Contacts[size - 1].get_email_addr() << std::endl;
		std::cout << "Phone number: " << this->Contacts[size - 1].get_phone_numb() << std::endl;
		std::cout << "Birthday day: " << this->Contacts[size - 1].get_birthday_date() << std::endl;
		std::cout << "Favorite meal: " << this->Contacts[size - 1].get_favorite_meal() << std::endl;
		std::cout << "Underwear color: " << this->Contacts[size - 1].get_underwear_color() << std::endl;
		std::cout << "Darkest secret: " << this->Contacts[size - 1].get_darkest_secret() << std::endl;
	}
}