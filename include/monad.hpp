#pragma once

#include <functional>

template<typename T>
struct Monad {
	// unit(return)
	Monad(T) = delete;
	// bind
	template<typename R>
	Monad<R> bind(std::function<Monad<R>(T)> f) const = delete;
};

template<typename T>
Monad<T> uint(T v);

template<typename To, typename From>
Monad<To> bind(Monad<From> m, std::function<Monad<To>(From)> f);

// Maybe monad
template<typename T>
struct Maybe {
  T const* _p;
  // unit (return)
  Maybe() : _p(nullptr) {}
  Maybe(T const& t) : _p(&t) {}
  // bind
  template<typename R>
  Maybe<R> bind(std::function<Maybe<R>(T)> f) const {
    return _p ? Maybe<R>(f(*_p)) : Maybe<R>();
  }
};


template<typename T>
struct Error{
	
};

template<typename T>
struct Reader {

};

template<typename T>
struct Writer {

};

template<typename T>
struct State{

};

template<typename T>
struct Cont{

};

template<typename T>
struct List{

};