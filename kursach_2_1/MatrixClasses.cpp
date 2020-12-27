#include "MatrixClasses.h"


void Matrix::SetType(std::string type)
{
	if (this->mat){
		this->Clear();
	}

	if (type == "int" || type == "class matrix_int")
	{
		mat = new matrix_int(0);
	}
	else if (type == "float" || type == "class matrix_float")
	{
		mat = new matrix_float(0);
	}
	else if (type == "double" || type == "class matrix_double")
	{
		mat = new matrix_double(0);
	}
	else
	{
		mat = nullptr;
	}
}

uint16_t Matrix::GetSize()
{
	return this->mat->GetSize();
}

void Matrix::Clear()
{
	this->mat->Clear();
}

void Matrix::Editin(uint16_t i, uint16_t j)
{
	if (!this->GetSize())
	{
		std::cout << std::endl << "Матрица не введена!" << std::endl;
		return;
	}
	this->mat->Editing(i, j);
}

void Matrix::FileIn(std::string filename)
{
	this->mat->finMatrix(filename);
}

void Matrix::FileOut(std::string filename)
{
	this->mat->foutMatrix(filename);
}


Matrix& Matrix::operator=(const Matrix& copied)
{
	this->SetType(typeid(*copied.mat).name());
	*this->mat = *copied.mat;
	return *this;
}

Matrix& Matrix::operator/(const Matrix& obj)
{
	Matrix* NewObj = new Matrix;
	*NewObj = *this;
	*NewObj->mat = (*this->mat / *obj.mat);
	return *NewObj;
}

std::ostream& operator<<(std::ostream& out, Matrix& object)
{
	if (!object.mat) {
		out << "Матрица не введена!" << std::endl;
		return out;
	}
	out << *object.mat;
	return out;
}

std::istream& operator>>(std::istream& in, Matrix& object)
{
	in >> *object.mat;
	return in;
}



Matrix::Matrix()
{
	this->mat = nullptr;
}

Matrix::Matrix(std::string type)
{
	this->SetType(type);
}

Matrix::Matrix(int size, std::string type)
{
	this->SetType(type);
	this->mat->SetNewMatrixSize(size);
}

Matrix::Matrix(const Matrix& copied)
{
	*this = copied;
}

Matrix::~Matrix()
{
	if (this->mat) {
		delete this->mat;
	}
}


