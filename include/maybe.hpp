#include <functional>
// Maybe monad
template<typename T>
struct Maybe {
  T _just;
  bool _nothing;
  // unit (return)
  Maybe() : _nothing(true) {}
  Maybe(T t) : _just(t), _nothing(false) {}
  // bind
  template<typename R>
  Maybe<R> bind(std::function<Maybe<R>(T)> f) const {
    return _nothing ? Maybe<R>() : Maybe<R>(f(_just));
  }
};

void foo(std::function<int(int)> f){
	
}