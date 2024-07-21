#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2) {
        std::cout << "Program requires Positive Integer Sequence as Input" << std::endl;
        std::cout << "Ex: ./PmergeMe 8 7 6 5 4" << std::endl;
        return 1;
    }

	try
	{
		std::vector<int> vecData;
		std::deque<int> deqData;

		int number;

		for (int index = 1; index < ac; index++)
		{
			std::stringstream ss(av[index]);

			if (!(ss >> number) || !(ss.eof()))
				throw std::invalid_argument("Error: Invalid input");
			
			if (number < 0)
				throw std::invalid_argument("Error: Not a positive number");
			
			vecData.push_back(number);
			deqData.push_back(number);
		}

		PmergeMe<std::vector<int> > pmergeVec;
    	PmergeMe<std::deque<int> > pmergeDeq;

		double vecSortTime;
		double deqSortTime;

		std::cout << "\nGiven data to sort:" << std::endl;
		std::cout << "Vector:" << std::endl;
		pmergeVec.printData(vecData);
		pmergeVec.calculateTime(vecData, vecSortTime);

		std::cout << "\nDeque:" << std::endl;
		pmergeDeq.printData(deqData);
		pmergeDeq.calculateTime(deqData, deqSortTime);

		std::cout << std::endl;
		std::cout << "Sorted Data in Vector:" << std::endl;
		pmergeVec.printData(vecData);

		std::cout << "\nSorted Data in Deque:" << std::endl;
		pmergeDeq.printData(deqData);

		std::cout << "\nTime to process a range of " << ac - 1 << " elements with std::vector : " << vecSortTime << " us"<< std::endl;
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << deqSortTime << " us"<< std::endl;

	}catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}