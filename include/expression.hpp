#pragma once

#include <cstddef>
using std::size_t;

class Arg0 {};
class Arg1 {};
class Arg2 {};

template<size_t i>
class GetArg { // instance of the concept PR
public:
	template<typename Args>
	auto operator()(Args const& args) {
		return args[i];
	}
};

template<typename T>
class Unit {
	T _v;
public:
	Unit(T const& v) : _v(v) {}

	template<typename Args>
	auto operator()(Args const& args) {
		return _v;
	}
};

template<typename T>
Unit<T> unit(T const& v) {
	return Unit<T>(v);
}

template<typename Func, typename Cont>
class Bind {
	Func _func;
	Cont _cont;
public:
	Bind(Func func, Cont cont)
		: _func(func), _cont(cont)
	{}

	template<typename Args>
	auto operator()(Args const& args) {
		return _cont(_func(args))(args);
	}
};

template<typename Func, typename Cont>
Bind<Func, Cont> bind(Func func, Cont cont) {
	return Bind<Func, Cont>(func, cont);
}

template<typename Func, typename Cont>
Bind<Func, Cont> operator|( Func func, Cont cont) {
	return Bind<Func, Cont>(func, cont);
}

template<typename E>
class Negative {};

template<typename E0, typename E1>
class Plus {};

template<typename E0, typename E1>
class Minus {};

template<typename E>
class Compile;

template<>
class Compile<Arg0> : public GetArg<0> {};

template<>
class Compile<Arg1> : public GetArg<1> {};

template<>
class Compile<Arg2> : public GetArg<2> {};

template<typename E0>
class Compile<Negative<E0> > {
public:
	template<typename Args>
	auto operator()(Args const& args) {
		return bind(
			Compile<E0>(),
			[](auto v) {
				return unit(-v);
			}
		)(args);
	}
};

template<typename E0, typename E1>
class Compile<Plus<E0, E1>> {
public:
	template<typename Args>
	auto operator()(Args const& args) {
		return bind(
			Compile<E0>(),
			[](auto const& e0) {
				return bind(
					Compile<E1>(),
					[e0](auto const& e1) {
						return unit(e0+e1);
					}
				);
			}
		)(args);
	}
};


