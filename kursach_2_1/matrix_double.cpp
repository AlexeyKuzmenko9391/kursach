#include "matrix_double.h"


std::ostream& matrix_double::print(std::ostream& out)
{
	out << std::endl;
	out << "Size: " << this->size << std::endl;
	out << "Matrix type: double" << std::endl;
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

std::istream& matrix_double::read(std::istream& in)
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


void matrix_double::Clear()
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

void matrix_double::Editing(uint16_t i, uint16_t j)
{
	if (i >= this->size || j >= this->size)
	{
		std::cout << "Элемента с данным индексом не существует!" << std::endl;
		return;
	}

	std::cout << "Введите значение: ";
	std::cin >> this->value[i][j];
}

void matrix_double::SetNewMatrixSize(uint16_t size)
{
	this->Clear();
	if (size)
	{
		this->size = size;
		this->value = new double* [size];
		for (unsigned i = 0; i < size; i++)
		{
			this->value[i] = new double[size] {};
		}
	}
}


matrix& matrix_double::operator=(const matrix& obj)
{
	if (typeid(obj).name() == (std::string)"class matrix_double")
	{
		return operator=(dynamic_cast<matrix_double&>(const_cast<matrix&>(obj)));
	}
	else
	{
		std::cout << std::endl << "Матрицы имеют разный или не совместимый тип данных!" << std::endl;
		return *this;
	}
}

matrix_double& matrix_double::operator=(const matrix_double& copied)
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

matrix& matrix_double::operator/(const matrix& obj)
{
	matrix_double Obj(obj);
	if (this->size == Obj.size)
	{
		matrix_double* NewObj = new matrix_double;
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


matrix_double::matrix_double() : matrix()
{
	this->value = nullptr;
}

matrix_double::matrix_double(uint16_t size) : matrix(size)
{
	this->value = new double* [size];
	for (unsigned i = 0; i < size; i++)
	{
		this->value[i] = new double[size] {};
	}
}

matrix_double::matrix_double(const matrix& copied) : matrix(copied)
{
	if (typeid(copied).name() == (std::string)"class matrix_double")
	{
		*this = dynamic_cast<matrix_double&>(const_cast<matrix&>(copied));
	}
	else
	{
		std::cout << std::endl << "Матрицы имеют разный или не совместимый тип данных!" << std::endl;
		this->~matrix_double();
	}
}

matrix_double::~matrix_double()
{
	this->Clear();
}
