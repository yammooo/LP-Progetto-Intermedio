#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#include <cstddef>

class MyVector{
	private:
		std::size_t _virtual_size = 0;
		std::size_t _capacity = 0;
		double* _elements = nullptr;

		void _resize(std::size_t index);
		void _resize();

	
	public:
		explicit MyVector();
		explicit MyVector(std::size_t size);
		
		MyVector(const MyVector& other); // Copy constructor
		MyVector& operator=(const MyVector& other); // Copy assignment
		
		MyVector(MyVector&& other); // Move constructor
		MyVector& operator=(MyVector&& other); // Move assignment
		
		~MyVector(); // Destructor
		
		std::size_t size() {
			return _virtual_size;
		};

		double& operator[](std::size_t index);
		const double& operator[](std::size_t index) const;

		double& at(std::size_t index);
		const double& at(std::size_t index) const;

		void push_back(double element);
		void pop_back();
		void reserve(std::size_t new_min_capacity);
};

#endif //MY_VECTOR_HPP