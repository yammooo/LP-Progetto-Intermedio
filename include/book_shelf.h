#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#include <cstddef>
#include "book.h"

class BookShelf{
	private:
		std::size_t _virtual_size = 0;
		std::size_t _capacity = 0;
		Book* _elements = nullptr;

		void _resize(std::size_t index);
		void _resize();

	
	public:
		explicit BookShelf();
		explicit BookShelf(std::size_t size);
		
		BookShelf(const BookShelf& other); // Copy constructor
		BookShelf& operator=(const BookShelf& other); // Copy assignment
		
		BookShelf(BookShelf&& other); // Move constructor
		BookShelf& operator=(BookShelf&& other); // Move assignment
		
		~BookShelf(); // Destructor
		
		std::size_t size() {
			return _virtual_size;
		};

		Book& operator[](std::size_t index);
		const Book& operator[](std::size_t index) const;

		Book& at(std::size_t index);
		const Book& at(std::size_t index) const;

		void push_back(Book element);
		void pop_back();
		void reserve(std::size_t new_min_capacity);
};

#endif //MY_VECTOR_HPP