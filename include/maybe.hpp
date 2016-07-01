#pragma once
#include <iostream>

// Maybe monad

template<typename T>
class Maybe;

template<typename T>
Maybe<T> maybe(T const& x);

Maybe<void> maybe();

template<typename T>
class Maybe{

public:
  T const& _x;
  Maybe(T const& x) : _x(x) {}
  // bind
  template<typename F>
  auto bind(F f) {
    return f(_x);
  }
};

template<>
class Maybe<void> {
public:
	Maybe() {}

	template<typename F>
	auto bind(F f){
		return maybe();
	}
};

template<typename T>
Maybe<T> maybe(T const& x) {
	return Maybe<T>(x);
}

Maybe<void> maybe() {
	 return Maybe<void>();
}


