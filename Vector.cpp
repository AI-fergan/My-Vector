#include "Vector.h"
#include <string>

/*
This method is a constructor to init the Vector.
input:
n - the size and the resize factor of the Vector.
*/
Vector::Vector(int n)
{
	this -> _size = 0;

//check if the size or the resize factor of the Vector,
//is smaller then 2.
	if (n < 2)
	{
		n = 2;
	}

//init the size and the resize factor of the Vector.
	this -> _resizeFactor = n;
	this -> _capacity = n;

//create the Vector
	this -> _elements = new int[Vector::capacity()];
}

/*
This method is a destructor to destruct the Vector.
*/
Vector::~Vector()
{
//delete the array of the Vector
	delete[] this -> _elements;
}

/*
This method return the size of the Vector.
output:
the size of the Vector.
*/
int Vector::size() const
{
	return this -> _size;
}

/*
This method return the capacity of the Vector.
output:
the capacity of the Vector.
*/
int Vector::Vector::capacity() const
{
	return this -> _capacity;
}

/*
This method return the resize factor of the Vector.
output:
the resize factor of the Vector.
*/
int Vector::resizeFactor() const
{
	return this -> _resizeFactor;
}

/*
This method return if the Vector is empty or not.
output:
if the Vector is empty or not.
*/
bool Vector::empty() const
{
	return this -> _size == 0;
}

/*
This method push new value organ into the array.
input:
val - the new value to push.
output:
NULL.
*/
void Vector::push_back(const int& val)
{
	int *elements = this -> _elements, *arr = NULL, i = 0;

//check if the size of the array is lower the the capacity of the array.
	if (Vector::size() < Vector::capacity())
	{

//add new value into the array
		elements[Vector::size()] = val;// + PREV_INDEX] = val;
		(this -> _size)++;
	}

//increase the capacity of the array,
//and create new array but with more organs then
//the last array and add the new value into the new array.
	else
	{

//increase the capacity of the array
		this -> _capacity += Vector::resizeFactor();
		arr = new int[Vector::capacity()];

//init the organs of the new array by the organs of the last array
		for (i = 0; i < Vector::size(); i++)
		{
			arr[i] = elements[i];
		}

//the th new value into the new array
		arr[Vector::size()] = val;

		this -> _elements = arr;

//delete the last array
		delete[] elements;

		(this -> _size)++;
		
	} 
	
}

/*
This method pop the last value of the array and return it.
output:
the last value in the array.
*/
int Vector::pop_back()
{
	int num = ERROR;

//check if the array size is zero
	if (Vector::size() != 0)
	{
		num = this -> _elements[Vector::size() + PREV_INDEX];
		(this -> _size) -= 1;
	}

//print and return ERROR if the size of the array is zero
	else
	{
		std::cout << "error: pop from empty";
	}

	return num;
}

/*
This method add more organs into the array, 
if 'n' is higher the array capa city.
input:
n - the new size to check the array capacity.
output:
NULL.
*/
void Vector::reserve(const int n)
{
	int *elements = this -> _elements, *arr = NULL, i = 0;

//check if 'n' is higher then array capacity
	if (Vector::capacity() < n)
	{

//add more organs into the array
		while (Vector::capacity() < n)
		{
			this -> _capacity += Vector::resizeFactor();
		}

		arr = elements;
		elements = new int[Vector::capacity()];

//init the new array organs value by the last organs array value
		for (i = 0; i < Vector::size(); i++)
		{
			elements[i] = arr[i];
		}

//delete the last array
		delete[] arr;

		this -> _elements = elements;
	}
}

/*
This method resize the array with new size ('n').
input:
n - the new size to resize the array.
output:
NULL.
*/
void Vector::resize(const int n)
{
	int* elements = this -> _elements, * arr = NULL, i = 0;

//check if 'n' is lower then the capacity of the array
	if (n < Vector::capacity())
	{

//add into the capacity more organs to the array
		while(Vector::capacity() - n > Vector::resizeFactor())
		{
			this -> _capacity -= Vector::resizeFactor();
		}
		arr = elements;
		elements = new int[Vector::capacity()];

//init the new array organs values, by the last array organs values.
		for (i = 0; i < Vector::size(); i++)
		{
			elements[i] = arr[i];
		}

		delete[] arr;

		this -> _elements = elements;
	}

//resize if 'n' higher the array capacity
	else
	{
		Vector::reserve(n);
	}
	
}

/*
This method init all the array organs.
input:
val - the value to init the  array organs.
output:
NULL.
*/
void Vector::assign(const int val)
{
	int i = 0;

//inti all the array
	for(i =  0; i < Vector::capacity(); i++)
	{
		this -> _elements[i] = val;
	}
}
/*
This method resize the Vector capacity and init all the array organs with 'val'.
input:
n - the new size of the array.
val - the value to init the organs of the array.
output:
NULL.
*/
void Vector::resize(const int n, const int& val)
{
	int i = 0;

//resize the array
	Vector::resize(n);

//init all the array organs
	for (i = Vector::size(); i < n; i++)
	{
		(this -> _size)++;
		this -> _elements[i] = val;
	}
}

/*
This operator is the equal operator that copy one item into another itme.
input:
other - the item to copy.
output:
the lsat item after the copy.
*/
Vector& Vector::operator=(const Vector& other)
{
	int i = 0;

//Shallow Copy
	this -> _capacity = other._capacity;
	this -> _resizeFactor = other._resizeFactor;
	this -> _size = other._size;
	delete[] this -> _elements;
	this -> _elements = new int[other._capacity];

//Deep Copy
	for(i = 0; i < Vector::size(); i++)
	{
		this -> _elements[i] = other._elements[i];
	}

	return *this;
}

/*
This method is a constructor that copy one item into another item.
input:
other - the item to copy.
*/
Vector::Vector(const Vector& other)
{
	*this = other;
}

/*
This operator return the organ in the 'n' index.
input:
n - the index of the organ to return.
output:
the organ in the 'n' index.
*/
int& Vector::operator[](int n) const
{
	int num;

//check if n is a proper index or not
	if (n < Vector::size() && n >= 0)
	{
		num = this -> _elements[n];
	}

//return the first organ in the array and return ERROR message
	else
	{
		num = this -> _elements[0];
		std::cout << "ERROR: 'n' is higher then the vector size." << std::endl;
	}

	return num;
}

/*
This operator add first vector into second vector.
input:
other - the first vector to add.
output:
the new vector after added.
*/
Vector& Vector::operator+=(const Vector& other)
{
	int i = 0;
//add all organs
	for (i = 0; i < Vector::size(); i++)
	{
		this -> _elements[i] += other._elements[i];
	}

	return *this;
}

/*
This operator subtraction first vector into second vector.
input:
other - the first vector to subtraction.
output:
the new vector after subtraction.
*/
Vector& Vector::operator-=(const Vector& other)
{
	int i = 0;

//subtraction all organs
	for (i = 0; i < Vector::size(); i++)
	{
		this->_elements[i] -= other._elements[i];
	}

	return *this;
}

/*
This operator subtraction first vector with second vector.
input:
other - the first vector to subtraction.
output:
the new vector after subtraction.
*/
Vector Vector::operator+(const Vector& other) const
{
	Vector vector = *this;
	vector += other;

	return vector;
}

/*
This operator add first vector with second vector.
input:
other - the first vector to add.
output:
the new vector after added.
*/
Vector Vector::operator-(const Vector& other) const
{
	Vector vector = *this;
	vector -= other;

	return vector;
}

/*
This operator print the vector data.
input:
os - the stream of the vector data.
v - the vector that the operator print.
output:
stream with the data of the vector.
*/
std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	int i = 0;

//capacity data
	os << "Vector info:\nCapacity is " << std::to_string(v._capacity) << std::endl;

//size data
	os << "Size is " << std::to_string(v._size) << std::endl;

//elements data
	os << "{";

//add all the elements of the vector into the stream
	for (i = 0; i < v._size; i++)
	{
		os << std::to_string(v._elements[i]);

//check if the index isn't the last index
		if (i != v._size + PREV_INDEX)
		{
			os << ",";
		}
	}
	os << "}" << std::endl;

	return os;
}
