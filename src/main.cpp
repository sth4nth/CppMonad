#include <iostream>
#include <vector>
#include <forward_list>
#include <memory>
// #include "expression.hpp"
// #include "monad.hpp"
#include "maybe.hpp"



template<typename... Args>
class Func {

};


template <typename T>
class Function;

template <typename Res, typename... Args>
class Function<Res(Args...)> {
public:
	template <typename T>
	Function& operator=(T t) {
		callable_ = std::make_unique<CallableT<T>>(t);
		return *this;
	}

	Res operator()(Args... args) const {
		return callable_->Invoke(args...);
	}

private:
	class ICallable {
	public:
		virtual ~ICallable() = default;
		virtual Res Invoke(Args...) = 0;
	};

	template <typename T>
	class CallableT : public ICallable {
	public:
		CallableT(const T& t)
			: t_(t) {
		}

		~CallableT() override = default;

		Res Invoke(Args... args) override {
			return t_(args...);
		}

	private:
		T t_;
	};

	std::unique_ptr<ICallable> callable_;
};


void func() {
	std::cout << "func" << std::endl;
}

struct functor {
	void operator()() {
		std::cout << "functor" << std::endl;
	}
};

template<typename... Args>
Func<Args...> make_func(Func<Args...> f) {
	return f;
}


int main() {

	auto b = maybe(1)
	.bind([](auto x) {return maybe(x+1.1);})
	.bind([](auto x) {return maybe();});
	// std::cout << b._x << std::endl;


	// Function<void()> f;
	// f = func;
	// f();
	// f = functor();
	// f();
	// f = []() { std::cout << "lambda" << std::endl; };
	// f();

	// using namespace std;
	// vector<double> args({2.0, 3.0, 4.0});
	// Compile<Negative<Plus<Arg0, Plus<Arg1, Arg2>>>> act;
	// auto v = act(args);
	// cout << v << endl;
	return 0;
}