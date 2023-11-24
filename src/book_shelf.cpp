#include <algorithm>
#include <stdexcept>
#include "../include/book_shelf.h"

void BookShelf::_resize(std::size_t new_capacity)
{
	Book* new_elements = new Book[new_capacity];
	std::copy(
			_elements,
			_elements+_virtual_size,
			new_elements
	);
	delete[] _elements;
	_capacity = new_capacity;
	_elements = new_elements;
}

void BookShelf::_resize()
{
	if (_capacity == 0 ) _resize(1);
	else _resize(_capacity*2);
}

BookShelf::BookShelf()
	{
	}

BookShelf::BookShelf(std::size_t size) :
	_virtual_size {size},
	_capacity{size*2},
	_elements{new Book[size*2]}
	{
	}

// Copy constructor
BookShelf::BookShelf(const BookShelf& other) :
	_virtual_size{other._virtual_size},
	_capacity{other._capacity},
	_elements{new Book[other._capacity]}
	{
		std::copy(
			other._elements,
			other._elements+other._virtual_size,
			this->_elements
		);
	}

// Copy assignment
BookShelf& BookShelf::operator=(const BookShelf& other) {
	if (this != &other) {
		delete[] _elements;
		
		_virtual_size = other._virtual_size;
		_capacity = other._capacity;
		_elements = new Book[other._capacity];
		std::copy(
			other._elements,
			other._elements+other._virtual_size,
			this->_elements
		);
	}

	return *this;
}

// Move constructor
BookShelf::BookShelf(BookShelf&& other) :
	_virtual_size{other._virtual_size},
	_capacity{other._capacity},
	_elements{other._elements}
	{
		other._virtual_size = 0;
		other._capacity = 0;
		other._elements = nullptr;
	}

// Move assignment
BookShelf& BookShelf::operator=(BookShelf&& other) {
	if (this != &other) {
		delete[] _elements;

		_virtual_size = other._virtual_size;
		_capacity = other._capacity;
		_elements = other._elements;

		other._virtual_size = 0;
		other._capacity = 0;
		other._elements = nullptr;
	}

	return *this;
}

// Destructor
BookShelf::~BookShelf() {
	delete[] _elements;
}

Book& BookShelf::operator[](std::size_t index) {
	return _elements[index];
}

const Book& BookShelf::operator[](std::size_t index) const {
	return _elements[index];
}

Book& BookShelf::at(std::size_t index) {
	if (index >= _virtual_size){
		throw std::out_of_range("Index out of range");
	}
	return _elements[index];
}

const Book& BookShelf::at(std::size_t index) const {
	if (index >= _virtual_size){
		throw std::out_of_range("Index out of range");
	}
	return _elements[index];
}

void BookShelf::push_back(Book element) {
	if (_virtual_size == _capacity) _resize();
	_elements[_virtual_size++] = element;
}

void BookShelf::pop_back() {
	if (_virtual_size == 0) {
        throw std::out_of_range("pop_back on empty vector");
    }
	_virtual_size--;
}

void BookShelf::reserve(std::size_t new_min_capacity){
	if(new_min_capacity > _capacity){
		_resize(new_min_capacity);
	}
}