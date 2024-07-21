
#include "PmergeMe.hpp"

template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;

template <typename Container>
PmergeMe<Container>::PmergeMe(){}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

template <typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe &other)
{
	(void)other;
	return (*this);
}

template <typename Container>
PmergeMe<Container>::~PmergeMe(){}


template <typename Container>
void PmergeMe<Container>::mergeInsertSort(Container &container, int start, int end)
{
	if (start < end)
	{
		if ((end - start) < 10)
			insertSort(container, start, end);
		else
		{
			int mid = start + (end - start) / 2;
			mergeInsertSort(container, start, mid);
			mergeInsertSort(container, mid + 1, end);
			mergeSort(container, start, mid, end);
		}
	}
}

template <typename Container>
void PmergeMe<Container>::mergeSort(Container &container, int start, int mid, int end)
{
	int n1 = mid - start + 1;
    int n2 = end - mid;

	Container left(container.begin() + start, container.begin() + mid + 1);
    Container right(container.begin() + mid + 1, container.begin() + end + 1);

    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            container[k] = left[i];
            i++;
        } else {
            container[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        container[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        container[k] = right[j];
        j++;
        k++;
    }

}

template <typename Container>
void PmergeMe<Container>::insertSort(Container &container, int start, int end)
{
	for (int index = start; index <= end; index++)
	{
		int temp = container[index];
		int j = index - 1;
		for (; j >=start && container[j] > temp; --j)
			container[j + 1] = container[j];
		container[j + 1] = temp;
	}
}

template <typename Container>
void PmergeMe<Container>::calculateTime(Container &container, double &usedTime)
{
	std::clock_t start = std::clock();
	mergeInsertSort(container, 0, container.size() - 1);
	std::clock_t end = std::clock();
	double elapsed = static_cast<double>(end - start) / (CLOCKS_PER_SEC) * 100.0;
	usedTime = elapsed;
}

template <typename Container>
void PmergeMe<Container>::printData(const Container &container) const
{
	for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}










