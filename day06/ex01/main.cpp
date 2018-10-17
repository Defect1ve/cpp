#include "main.hpp"

void * serialize( void )
{
	char*	lol  = new char[20];
	int k = rand() % 214748364;
	std::string an = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 8; i++)
	{
		lol[i] = an[rand() % 62];
		std::cout << lol[i];
	}
	*(reinterpret_cast<int *>(lol + 8)) = k;
	std::cout << k;
	for (int i = 0; i < 8; i++)
	{
		lol[i + 12] = an[rand() % 62];
		std::cout << lol[i + 12];
	}
	std::cout << std::endl;
	return (static_cast<void *>(lol));
}

Data * deserialize(void * raw)
{
	Data	*data = new Data;
	char*	lol  = reinterpret_cast<char *>(raw);

	data->s1 = "";
	data->s2 = "";
	for (int i = 0; i < 8; i++)
	{
		data->s1 += lol[i];
		data->s2 += lol[i + 12];
	}	
	data->n = *(reinterpret_cast<int *>(lol + 8));
	return(data);
}

int		main(void)
{
	Data *data;
	srand(time(0));
	data = deserialize(serialize());
	std::cout << data->s1 << data->n << data->s2 << std::endl;
	delete data;
	return (0);
}