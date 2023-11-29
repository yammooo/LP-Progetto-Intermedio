#ifndef LP_INCLUDE_MY_VECTOR_H_
#define LP_INCLUDE_MY_VECTOR_H_

#include <cstddef>
#include "book.h"

class BookShelf{
	private:
		std::size_t virtual_size_ = 0; // This variable keeps track of the actual number of books that the bookshelf is currently holding
		std::size_t capacity_ = 0; // This variable represents the total number of books that the bookshelf can hold before it needs to resize
		Book* elements_ = nullptr;

		void Resize_(std::size_t index); // This method resizes the bookshelf to a new capacity
		void Resize_(); // This method doubles the capacity of the bookshelf
	
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

		void PushBack(Book element); // This method adds a new book to the end of the bookshelf
		void PopBack(); // This method removes the last book from the bookshelf
		void Reserve(std::size_t new_min_capacity); // This method increases the capacity of the bookshelf to at least new_min_capacity
};

#endif // LP_INCLUDE_MY_VECTOR_H_