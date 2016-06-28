

// Continuation monad as object. cont.bind(func) -> cont'
template<typename T>
class Continuation {

public:
	Continuation() {  

	}

	template<typename Args>
	auto operator()(Args const& args) {
		return 0;
	}
};


template<class Monad, class To, class From>
Monad<To> _bind(Monad<From> m, std::function<Monad<To>(From)> f);

template<class Monad, class T>
Monad<T> _return(T v);