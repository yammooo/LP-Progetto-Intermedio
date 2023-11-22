#include <algorithm>
#include <stdexcept>
#include "my_vector.h"

void MyVector::_resize(std::size_t new_capacity)
{
	double* new_elements = new double[new_capacity];
	std::copy(
			_elements,
			_elements+_virtual_size,
			new_elements
	);
	delete[] _elements;
	_capacity = new_capacity;
	_elements = new_elements;
}

void MyVector::_resize()
{
	if (_capacity == 0 ) _resize(1);
	else _resize(_capacity*2);
}

MyVector::MyVector()
	{
	}

MyVector::MyVector(std::size_t size) :
	_virtual_size {size},
	_capacity{size*2},
	_elements{new double[size*2]}
	{
		for(std::size_t index = 0; index < _virtual_size; index++)
		{
			_elements[index] = 0.0;
		}
	}

// Copy constructor
MyVector::MyVector(const MyVector& other) :
	_virtual_size{other._virtual_size},
	_capacity{other._capacity},
	_elements{new double[other._capacity]}
	{
		std::copy(
			other._elements,
			other._elements+other._virtual_size,
			this->_elements
		);
	}

// Copy assignment
MyVector& MyVector::operator=(const MyVector& other) {
	if (this != &other) {
		delete[] _elements;
		
		_virtual_size = other._virtual_size;
		_capacity = other._capacity;
		_elements = new double[other._capacity];
		std::copy(
			other._elements,
			other._elements+other._virtual_size,
			this->_elements
		);
	}

	return *this;
}

// Move constructor
MyVector::MyVector(MyVector&& other) :
	_virtual_size{other._virtual_size},
	_capacity{other._capacity},
	_elements{other._elements}
	{
		other._virtual_size = 0;
		other._capacity = 0;
		other._elements = nullptr;
	}

// Move assignment
MyVector& MyVector::operator=(MyVector&& other) {
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
MyVector::~MyVector() {
	delete[] _elements;
}

double& MyVector::operator[](std::size_t index) {
	return _elements[index];
}

const double& MyVector::operator[](std::size_t index) const {
	return _elements[index];
}

double& MyVector::at(std::size_t index) {
	if (index >= _virtual_size){
		throw std::out_of_range("Index out of range");
	}
	return _elements[index];
}

const double& MyVector::at(std::size_t index) const {
	if (index >= _virtual_size){
		throw std::out_of_range("Index out of range");
	}
	return _elements[index];
}

void MyVector::push_back(double element) {
	if (_virtual_size == _capacity) _resize();
	_elements[_virtual_size++] = element;
}

void MyVector::pop_back() {
	if (_virtual_size == 0) {
        throw std::out_of_range("pop_back on empty vector");
    }
	_virtual_size--;
}

void MyVector::reserve(std::size_t new_min_capacity){
	if(new_min_capacity > _capacity){
		_resize(new_min_capacity);
	}
}