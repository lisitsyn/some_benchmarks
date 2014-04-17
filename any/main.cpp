#include "cdiggins_any.hpp"
#include <hayai.hpp>
#include <boost/any.hpp>
#include <string.h>

const int REPEATS = 1000;
const int RUNS = 1000;

BENCHMARK(Any, Boost, RUNS, REPEATS)
{
	std::pair<int, int> pair;
	boost::any any(pair);
	any = boost::any_cast<std::pair<int, int>>(any);
}

BENCHMARK(Any, CDiggins, RUNS, REPEATS)
{
	std::pair<int, int> pair;
	cdiggins::any any(pair);
	any = any.cast<std::pair<int, int>>();
}

int main()
{
	hayai::ConsoleOutputter outputter;
	hayai::Benchmarker::AddOutputter(outputter);
	hayai::Benchmarker::RunAllTests();
	return 0;
}
