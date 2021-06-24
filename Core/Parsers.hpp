#pragma once
#include "Collections.hpp"
#include <iostream>
namespace Structural {
	using namespace Structural::Collections::Generic;
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
		Array<Token<T>> words{};
	public:

		Tokenizer(Array<char> skips, Dictionary<std::string,T> dictionary):dictionary{dictionary},skips{skips} {}

		void Read(std::string str) {
			int i = 0;
			std::string sub{};
			for (char c : str) {
				if (c != ' ')
					sub.push_back(c);
				else {
					i++;
					words.push_back(Token<T>{sub,dictionary[sub]});
					sub = "";
				}
			}
		}


		Token<T> Consume() {
			Token<T> v = words.at(0);
			words.erase(words.begin());
			return v;
		}
	};

	template <typename T>
	class Parser {

	};

}