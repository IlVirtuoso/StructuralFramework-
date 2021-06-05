#pragma once
#include<unordered_map>
#include<iostream>
#include <algorithm>
#include "ISerializable.hpp"
#include "Interfaces.hpp"

namespace Structural {

	namespace Collections {

		namespace Generic {

			template<typename T>
			class Array : public std::vector<T> {
			public:

				Array(const std::list<T> varargs) {
					for each (T e in varargs)
					{
						this->push_back(e);
					}
				}

				Array(){}

				void Insert(T elem) {
					this->push_back(elem);
				}

				bool Remove(int index) {
					if (index <0 || index > this->size()) return false;
					this->erase(this->begin() + index);
					return true;
				}

				int Find(Predicate<T> predicate) {
					for (register int i = 0; i < this->size(); i++)
						if (predicate(this->at(i)))
							return i;
					return -1;
				}

				Array<T> Select(Predicate<T> p) {
					Array<T> select{};
					for each (T var in *this)
					{
						if (p(var))
							select.Insert(var);
					}
					return select;
				}



				std::vector<T>::iterator begin() {
					return std::vector<T>::begin();
				}

				std::vector<T>::iterator end() {
					return std::vector<T>::end();
				}

				int IndexOf(T value) {
					for (register int i = 0; i < this->size(); i++)
						if (this->at(i) == value)
							return i;
					return -1;
				}

				Array<T> Sort(Structural::Func<int,T,T> sortDelegate) {
					Array<T> newArray{ *this };
					quicksort(&newArray, 0, newArray.size() - 1, sortDelegate);
					return newArray;
				}

				Array<T> Reverse() {
					Array<T> newArray{};
					for (int i = this->size() - 1; i >= 0; i--)
						newArray.push_back(this->at(i));
					return newArray;
				}

				

			private:

				static void quicksort(Array<T> * ar, int low, int high, Func<int,T,T> sortFunc) {
					if (low < high) {
						int pivot = ar->partition(ar, low, high,sortFunc);
						quicksort(ar,low , pivot,sortFunc);
						quicksort(ar, pivot + 1, high,sortFunc);
					}
				}

				static int partition(Array<T> * ar, int low, int high , Func<int, T, T> sortFunc) {
					T pivot = ar->at(high);
					int i = low - 1;
					int j = low;
					for (j; j < high; j++) {
						if (sortFunc(ar->at(j),pivot) <0) {
							i++;
							ar->swapelements(i, j);
						}
					}
					ar->swapelements(i+1, high);
					return i + 1;
				}

				void swapelements(int i1, int i2) {
					T e1 = this->at(i1);
					this->data()[i1] = this->data()[i2];
					this->data()[i2] = e1;
				}


			};


			template<typename K, typename V>
			class Dictionary : std::unordered_map<K,V> {
			private:
				Array<std::pair<K, V>*> pairs;
				

			public:

				void Insert(K key, V value) {
					std::pair<K, V> * pair = new std::pair<K,V>(key, value);
					std::unordered_map<K, V>::insert(*pair);
					pairs.Insert(pair);
				}

				Array<K> GetKeys() {
					Array<K> keys{};
					for each (std::pair<K,V>* elem in pairs)
					{
						keys.push_back(elem->first);
					}
					return keys;
				}

				Array<V> GetValues() {
					Array<V> values{};
					for each (auto elem in pairs)
					{
						values.push_back(elem->second);
					}
					return values;
				}

				void Remove(K key) {
					std::unordered_map<K, V>::erase(key);
					
				}
			};
			
		}
	}
}