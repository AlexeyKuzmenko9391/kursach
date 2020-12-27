#include "matrix_float.h"


std::ostream& matrix_float::print(std::ostream& out)
{
	out << std::endl;
	out << "Size: " << this->size << std::endl;
	out << "Matrix type: float" << std::endl;
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

std::istream& matrix_float::read(std::istream& in)
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


void matrix_float::Clear()
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

void matrix_float::Editing(uint16_t i, uint16_t j)
{
	if (i >= this->size || j >= this->size)
	{
		std::cout << "Элемента с данным индексом не существует!" << std::endl;
		return;
	}

	std::cout << "Введите значение: ";
	std::cin >> this->value[i][j];
}

void matrix_float::SetNewMatrixSize(uint16_t size)
{
	this->Clear();
	if (size)
	{
		this->size = size;
		this->value = new float* [size];
		for (unsigned i = 0; i < size; i++)
		{
			this->value[i] = new float[size] {};
		}
	}
}


matrix& matrix_float::operator=(const matrix& obj)
{
	if (typeid(obj).name() == (std::string)"class matrix_float")
	{
		return operator=(dynamic_cast<matrix_float&>(const_cast<matrix&>(obj)));
	}
	else
	{
		std::cout << std::endl << "Матрицы имеют разный или не совместимый тип данных!" << std::endl;
		return *this;
	}
}

matrix_float& matrix_float::operator=(const matrix_float& copied)
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

matrix& matrix_float::operator/(const matrix& obj)
{
	matrix_float Obj(obj);
	if (this->size == Obj.size)
	{
		matrix_float* NewObj = new matrix_float;
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


matrix_float::matrix_float() : matrix()
{
	this->value = nullptr;
}

matrix_float::matrix_float(uint16_t size) : matrix(size)
{
	this->value = new float* [size];
	for (unsigned i = 0; i < size; i++)
	{
		this->value[i] = new float[size] {};
	}
}

matrix_float::matrix_float(const matrix& copied) : matrix(copied)
{
	if (typeid(copied).name() == (std::string)"class matrix_float")
	{
		*this = dynamic_cast<matrix_float&>(const_cast<matrix&>(copied));
	}
	else
	{
		std::cout << std::endl << "Матрицы имеют разный или не совместимый тип данных!" << std::endl;
		this->~matrix_float();
	}
}

matrix_float::~matrix_float()
{
	this->Clear();
}

