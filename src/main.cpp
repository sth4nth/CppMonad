#include <iostream>
#include <vector>
#include <forward_list>
#include "monad.hpp"

int main() {
	using namespace std;
	vector<double> args({2.0, 3.0, 4.0});
	Compile<Negative<Plus<Arg0, Plus<Arg1, Arg2>>>> act;
	auto v = act(args);
	cout << v << endl;
	return 0;
}