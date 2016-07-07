#pragma once

template<class T>
  T mempty;

template<class T>
  T mappend(T, T);

template<class M>
  concept bool Monoid () {
  	return requires (M m) {
	    { mempty<M> } -> M;
  	    { mappend(m, m) } -> M;
  	};
  }

