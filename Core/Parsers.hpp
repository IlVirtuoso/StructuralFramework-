#pragma once
#include "Collections.hpp"
#include "Streams.hpp"
#include <iostream>
namespace Structural {
	using namespace Structural::Collections::Generic;
	using namespace Streams;
	template <typename T>
	class Token {
	public:
		std::string string;
		T token;
		Token(std::string string, T token) : string{string},token{token}{}
	};

	template <typename T>
	class Tokenizer {
		Dictionary<std::string, T> dictionary;
		Array<char> skips;
		Array<Token<T>> words;
	public:

		Tokenizer(Array<char> skips, Dictionary<std::string,T> dictionary):dictionary{dictionary},skips{skips} {}

		void Read(Reader reader);
		void Read(std::string string);






	};

	template <typename T>
	class Parser {

	};

}