#if 0
#include<deque>
#include<vector>
#include<iostream>


template<class T>
std::vector<T> getMaxWindow(std::vector<T> vec, int w)
{
	std::vector<T> res;
	if (vec.empty() || w < 1 || vec.size() < w)
		return res;
	std::deque<T> qu;
	for (int i = 0; i < vec.size(); i++)
	{
		while (!qu.empty() && vec[qu.back()] <= vec[i])
			qu.pop_back();
		qu.push_back(i);
		if (qu.front() == i - w)
			qu.pop_front();
		if (i >= w - 1)
			res.push_back(vec[qu.front()]);
	}
	return res;
}

int main()
{
	int arr[] = { 4,3,5,4,3,3,6,7 };
	std::vector<int> vec(arr,arr+sizeof(arr)/sizeof(int));
	std::vector<int> res = getMaxWindow(vec, 3);
	for (int i = 0; i < res.size(); i++)
		std::cout << res[i] << std::endl;
	return 0;
}
#endif