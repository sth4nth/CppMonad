
template<typename T>
class Maybe {
  T* _data;
public:
  Maybe(): _data(nullptr) {};

  bool operator bool() {
    return _data == nullptr;
  }

  auto operator ()(){
    return *_data;
  }
};

template<typename From, typename To>
Maybe<To> operator>>=(Maybe<From> t, std::function<Maybe<To>(From)> f)
{


  t ? return f(t.data())
  if(t.valid == false)
  {        
    return_value.valid = false;
    return return_value;
  }
  else
  {        
    return f(t.data);
  }            
}