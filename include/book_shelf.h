#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#include <cstddef>
#include "book.h"

class BookShelf{
	private:
		std::size_t virtual_size_ = 0;
		std::size_t capacity_ = 0;
		Book* elements_ = nullptr;

		void Resize_(std::size_t index);
		void Resize_();

	
	public:
		explicit BookShelf();
		explicit BookShelf(std::size_t size);
		
		BookShelf(const BookShelf& other); // Copy constructor
		BookShelf& operator=(const BookShelf& other); // Copy assignment
		
		BookShelf(BookShelf&& other); // Move constructor
		BookShelf& operator=(BookShelf&& other); // Move assignment
		
		~BookShelf(); // Destructor
		
		std::size_t Size() {
			return virtual_size_;
		};

		Book& operator[](std::size_t index);
		const Book& operator[](std::size_t index) const;

		Book& At(std::size_t index);
		const Book& At(std::size_t index) const;

		void PushBack(Book element);
		void PopBack();
		void Reserve(std::size_t new_min_capacity);
};

#endif //MY_VECTOR_HPP