#include "matrix_int.h"


std::ostream& matrix_int::print(std::ostream& out)
{
	out << std::endl;
	out << "Size: " << this->size << std::endl;
	out << "Matrix type: int" << std::endl;
	out << "Matrix value: " << std::endl;

	if (!this->value)
	{
		out << "no values!" << std::endl;
		return out;
	}

	for (unsigned i = 0; i < this->size; i++) {
		for (unsigned j = 0; j < this->size; j++) {
			out << this->value[i][j] << " ";
		}
		out << std::endl;
	}
	return out;
}

std::istream& matrix_int::read(std::istream& in)
{
	if (this->size)
	{
		for (unsigned i = 0; i < this->size; i++) {
			for (unsigned j = 0; j < this->size; j++) {
				in >> this->value[i][j];
			}
		}
		return in;
	}
	else
	{
		uint16_t a;
		in >> a;
		this->SetNewMatrixSize(a);

		for (unsigned i = 0; i < this->size; i++) {
			for (unsigned j = 0; j < this->size; j++) {
				in >> this->value[i][j];
			}
		}
		return in;
	}
}


void matrix_int::Clear()
{
	if (this->value)
	{
		for (unsigned i = 0; i < this->size; i++) {
			delete[] this->value[i];
		}
		delete[] this->value;
		this->value = nullptr;
		this->size = 0;
	}
}

void matrix_int::Editing(uint16_t i, uint16_t j)
{
	if (i >= this->size || j >= this->size)
	{
		std::cout << "Элемента с данным индексом не существует!" << std::endl;
		return;
	}

	std::cout << "Введите целочисленное значение: ";
	std::cin >> this->value[i][j];
}

void matrix_int::SetNewMatrixSize(uint16_t size)
{
	this->Clear();
	if (size)
	{
		this->size = size;
		this->value = new int* [size];
		for (unsigned i = 0; i < size; i++)
		{
			this->value[i] = new int[size] {};
		}
	}
}


matrix& matrix_int::operator=(const matrix& obj)
{
	if (typeid(obj).name() == (std::string)"class matrix_int")
	{
		return operator=(dynamic_cast<matrix_int&>(const_cast<matrix&>(obj)));
	}
	else 
	{
		std::cout << std::endl << "Матрицы имеют разный или не совместимый тип данных!" << std::endl;
		return *this;
	}
}

matrix_int& matrix_int::operator=(const matrix_int& copied)
{
	this->Clear();
	this->SetNewMatrixSize(copied.size);
	for (unsigned i = 0; i < this->size; i++) {
		for (unsigned j = 0; j < this->size; j++) {
			this->value[i][j] = copied.value[i][j];
		}
	}
	return *this;
}

matrix& matrix_int::operator/(const matrix& obj)
{
	matrix_int Obj(obj);
	if (this->size == Obj.size && this->size != 0) 
	{
		matrix_int* NewObj = new matrix_int();
		*NewObj = *this;
		int max = Obj.value[0][0];

		for (unsigned i = 0; i < this->size; i++)
		{
			for (unsigned j = 0; j < this->size; j++)
			{
				if (max < Obj.value[i][j]) {
					max = Obj.value[i][j];
				}
			}

			for (unsigned k = 0; k < this->size; k++)
			{
				NewObj->value[i][k] = max ? (value[i][k] / max) : 0;
			}
		}
		return *NewObj;
	}
	else
	{
		return *this;
	}
}


matrix_int::matrix_int() : matrix()
{
	this->value = nullptr;
}

matrix_int::matrix_int(uint16_t size) : matrix(size)
{
	this->value = new int* [size];
	for (unsigned i = 0; i < size; i++)
	{
		this->value[i] = new int[size] {};
	}
}

matrix_int::matrix_int(const matrix& copied) : matrix(copied)
{
	if (typeid(copied).name() == (std::string)"class matrix_int")
	{
		*this = dynamic_cast<matrix_int&>(const_cast<matrix&>(copied));
	}
	else
	{
		std::cout << std::endl << "Матрицы имеют разный или не совместимый тип данных!" << std::endl;
		this->~matrix_int();
	}
}

matrix_int::~matrix_int()
{
	this->Clear();
}
