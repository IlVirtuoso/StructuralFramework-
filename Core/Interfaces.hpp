#pragma once
#include<functional>
namespace Structural {

	template<typename T = void,typename...Args>
	class Func {
	private:
		std::function<T(Args...)> func;
	public:
		
		Func(std::function<T(Args...)> lambda) {
			this->func = lambda;
		}

		T operator()(Args...a) {
			return this->func(a...);
		}
	};

	template <typename T>
	class Predicate {
	private:
		std::function<bool(T)> func;

	public:
		Predicate(std::function<bool(T)> lambda) {
			this->func = lambda;
		}

		bool operator()(T arg) {
			return this->func(arg) == true;
		}
	};
}