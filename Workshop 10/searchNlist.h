#include "Collection.h"


namespace sdds {
	template <typename type1, typename type2>
	bool search(Collection<type1>& collection, type1* t, int noOfElements, type2 key) {
		bool result = false;
		for (int i = 0; i < noOfElements; i++) {
			if (t[i] == key) {
				collection.add(t[i]);
				result = true;
			}
		}
		return result;
	}

	template <typename T>
	void listArrayElements(const char* title, T* t, int noOfElements) {
		std::cout << title << std::endl;
		for (int i = 0; i < noOfElements; i++) {
			std::cout << i + 1 << ": ";
			std::cout << t[i] << std::endl;
		}
	}
}