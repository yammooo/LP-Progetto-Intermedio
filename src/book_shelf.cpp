#include <algorithm>
#include <stdexcept>
#include "../include/book_shelf.h"

void BookShelf::Resize_(std::size_t new_capacity)
{
	Book* new_elements = new Book[new_capacity];
	std::copy(
			elements_,
			elements_+virtual_size_,
			new_elements
	);
	delete[] elements_;
	capacity_ = new_capacity;
	elements_ = new_elements;
}

void BookShelf::Resize_()
{
	if (capacity_ == 0 ) Resize_(1);
	else Resize_(capacity_*2);
}

BookShelf::BookShelf()
	{
	}

BookShelf::BookShelf(std::size_t size) :
	virtual_size_ {size},
	capacity_{size*2},
	elements_{new Book[size*2]}
	{
	}

// Copy constructor
BookShelf::BookShelf(const BookShelf& other) :
	virtual_size_{other.virtual_size_},
	capacity_{other.capacity_},
	elements_{new Book[other.capacity_]}
	{
		std::copy(
			other.elements_,
			other.elements_+other.virtual_size_,
			this->elements_
		);
	}

// Copy assignment
BookShelf& BookShelf::operator=(const BookShelf& other)
{
	if (this != &other) {
		delete[] elements_;
		
		virtual_size_ = other.virtual_size_;
		capacity_ = other.capacity_;
		elements_ = new Book[other.capacity_];
		std::copy(
			other.elements_,
			other.elements_+other.virtual_size_,
			this->elements_
		);
	}

	return *this;
}

// Move constructor
BookShelf::BookShelf(BookShelf&& other) :
	virtual_size_{other.virtual_size_},
	capacity_{other.capacity_},
	elements_{other.elements_}
	{
		other.virtual_size_ = 0;
		other.capacity_ = 0;
		other.elements_ = nullptr;
	}

// Move assignment
BookShelf& BookShelf::operator=(BookShelf&& other)
{
	if (this != &other) {
		delete[] elements_;

		virtual_size_ = other.virtual_size_;
		capacity_ = other.capacity_;
		elements_ = other.elements_;

		other.virtual_size_ = 0;
		other.capacity_ = 0;
		other.elements_ = nullptr;
	}

	return *this;
}

// Destructor
BookShelf::~BookShelf()
{
	delete[] elements_;
}

Book& BookShelf::operator[](std::size_t index)
{
	return elements_[index];
}

const Book& BookShelf::operator[](std::size_t index) const
{
	return elements_[index];
}

Book& BookShelf::At(std::size_t index)
{
	if (index >= virtual_size_){
		throw std::out_of_range("Index out of range");
	}
	return elements_[index];
}

const Book& BookShelf::At(std::size_t index) const
{
	if (index >= virtual_size_){
		throw std::out_of_range("Index out of range");
	}
	return elements_[index];
}

void BookShelf::PushBack(Book element)
{
	if (virtual_size_ == capacity_) Resize_();
	elements_[virtual_size_++] = element;
}

void BookShelf::PopBack()
{
	if (virtual_size_ == 0) {
        throw std::out_of_range("pop_back on empty vector");
    }
	virtual_size_--;
}

void BookShelf::Reserve(std::size_t new_min_capacity)
{
	if(new_min_capacity > capacity_){
		Resize_(new_min_capacity);
	}
}