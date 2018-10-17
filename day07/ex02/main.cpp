# include "Array.hpp"

int		main(void)
{
	Array<int> *arr1 = new Array<int>();
	Array<int> *arr2 = new Array<int>(13);
	Array<int> arr3 = *arr1;
	Array<int> arr4 = *arr2;

	try
	{
		std::cout << "Size of arr1: " << arr1->size() << std::endl;
		std::cout << "Size of arr2: " << arr2->size() << std::endl;
		std::cout << "Size of arr3: " << arr3.size() << std::endl;
		std::cout << "Size of arr4: " << arr4.size() << std::endl;
		std::cout << "arr2[5] = " << (*arr2)[5] << std::endl;
		std::cout << "arr4[5] = " << arr4[5] << std::endl;
		std::cout << "arr1[5] = " << (*arr1)[5] << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}