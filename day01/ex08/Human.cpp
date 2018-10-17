# include "Human.hpp"
# include <iostream>

void	Human::meleeAttack(std::string const & target)
{
	std::cout << "You attacked " << target << " with muzhickiy punch" << std::endl;
}

void	Human::rangedAttack(std::string const & target)
{
	std::cout << "You attacked " << target << " with muzhickiy spit" << std::endl;
}

void	Human::intimidatingShout(std::string const & target)
{
	std::cout << "You have frighten " << target << " with \'ATASHOL\'" << std::endl;
}

void	Human::action(std::string const & action_name, std::string const & target)
{
	std::string actions[] = {"meleeAttack", "rangedAttack", "intimidatingShout"};

    typedef void (Human::*Actions)(std::string const &target);
    Actions methods[3] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};

    for (int i = 0; i < 3; i++)
        if (actions[i] == action_name)
        {
            (this->*(methods[i]))(target);
            break;
        }
}