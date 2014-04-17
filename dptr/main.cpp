#include <hayai.hpp>
#include "embedded.hpp"
#include "unique.hpp"

const int REPEATS = 10000;
const int RUNS = 100;

BENCHMARK(DPtr, Embedded, RUNS, REPEATS)
{
	WithEmbeddedDPtr object;
	object.doStuff();
}

BENCHMARK(DPtr, Unique, RUNS, REPEATS)
{
	WithUniqueDPtr object;
	object.doStuff();
}

int main()
{
	hayai::ConsoleOutputter outputter;
	hayai::Benchmarker::AddOutputter(outputter);
	hayai::Benchmarker::RunAllTests();
	return 0;
}
