#pragma once
#include<unordered_map>
#include<iostream>
#include "ISerializable.hpp"
namespace Structural {

	namespace Collections {

		namespace Generic {

			template<typename T>
			class Array : public std::vector<T> {
			public:

				bool remove(int index) {
					
				}

				int indexOf(T value) {
					for (register int i = 0; i < this->size(); i++)
						if (this->at(i) == value)
							return i;
					return -1;
				}


			};


			template<typename K, typename V>
			class Dictionary : public std::unordered_map<K,V> {
			private:
				std::vector<K> * keys = new std::vector<K>();
				std::vector<V> * values = new std::vector<V>();
				

			public:

				void insert(K key, V value) {
					std::unordered_map<K, V>::insert(std::pair<K,V>(key,value));
					this->keys->push_back(key);
					this->values->push_back(value);
				}

				void remove(K key) {
					this->insert_or_assign(key, NULL);
					
				}
			};
			
		}
	}
}