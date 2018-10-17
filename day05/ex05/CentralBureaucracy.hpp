#ifndef CENTRAL_BUREAUCRACY_HPP
# define CENTRAL_BUREAUCRACY_HPP
# include "OfficeBlock.hpp"
# include <queue>

class CentralBureaucracy
{

public:
	class EmptyOfficeException : public std::exception
	{
		public:
			EmptyOfficeException(void);
			virtual ~EmptyOfficeException() throw();
			EmptyOfficeException(EmptyOfficeException const &src);
			void operator=(EmptyOfficeException const &src);
			virtual const char * what() const throw();
	};
	typedef struct s_queue
	{
		std::string		target;
		struct s_queue	*next;
	}				t_queue;
	CentralBureaucracy();
	CentralBureaucracy(CentralBureaucracy const&src);
	CentralBureaucracy &operator=(CentralBureaucracy const&src);
	~CentralBureaucracy();
	void	FillBur(Bureaucrat const &bur);
	void	queueUp(std::string);
	std::string		getFirst();
	void			doBureaucracy(void);
private:
	OfficeBlock *_mass;
	int			_mass_count;
	t_queue *my;
};

#endif