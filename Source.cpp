#include "Ngraph.h"
#include "Ngraph_function.cpp"
using namespace std;

int main()
{
	Graph<int> test;
	test.add_node(1);
	test.add_node(2);
	test.add_node(3);
	test.show();
}