/*
    Shinwoo Park
    natural7530@gmail.com

    CC0 1.0 Universal
*/

#include <chrono>
#include <iostream>
#include <utility>

std::pair<int, int> p;
std::chrono::duration<double> d[3];

int main()
{
	/*
	To speed up C++ STL containers like vector or deque,
	use customized allocator that reduces system call of memory allocation.
	*/

	using high_resolution_clock = std::chrono::high_resolution_clock;
	high_resolution_clock::time_point st, ed;

	/* make_pair */
	{
		st = high_resolution_clock::now();
		for (int i = 0; i < 1e8; ++i) {
			p = std::make_pair(i, i);
		}

		ed = high_resolution_clock::now();
		d[0] = ed - st;
	}

	/* pair */
	{
		st = high_resolution_clock::now();
		for (int i = 0; i < 1e8; ++i) {
			p = std::pair<int, int>(i, i);
		}

		ed = high_resolution_clock::now();
		d[1] = ed - st;
	}

	/* native */
	{
		st = high_resolution_clock::now();
		for (int i = 0; i < 1e8; ++i) {
			p.first = i, p.second = i;
		}

		ed = high_resolution_clock::now();
		d[2] = ed - st;
	}

	/* print all results */

	// Optimization
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cout.precision(2);
	std::cout.setf(std::ios::fixed);

	std::cout << "make_pair:\t\t" << d[0].count() << std::endl
	          << "pair:\t\t\t" << d[1].count() << std::endl
	          << "native:\t\t\t" << d[2].count() << std::endl
	          << std::endl
	          << "make_pair/native:\t" << d[0].count() / d[2].count()
	          << std::endl
	          << "pair/native:\t\t" << d[1].count() / d[2].count() << std::endl;

	return 0;
}
