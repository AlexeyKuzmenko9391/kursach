#include "matrix.h"


std::ostream& matrix::print(std::ostream& out) { return out; }

std::istream& matrix::read(std::istream& in) { return in; }

void matrix::Clear() {}

void matrix::Editing(uint16_t i, uint16_t j) {}

void matrix::SetNewMatrixSize(uint16_t size){}

matrix& matrix::operator=(const matrix& copied) { return *this; }

matrix& matrix::operator/(const matrix& obj) { return *this; }



uint16_t matrix::GetSize()
{
	return this->size;
}

void matrix::foutMatrix(std::string fileName) 
{
	std::ofstream fout(fileName);
	fout << *this;
	fout.close();
}

void matrix::finMatrix(std::string fileName)
{
	std::ifstream fin(fileName);
	this->Clear();
	fin >> *this;
	fin.close();
}

std::ostream& operator<<(std::ostream& out, matrix& object)
{
	return object.print(out);
}

std::istream& operator>>(std::istream& in, matrix& object)
{
	return object.read(in);
}



matrix::matrix()
{
	this->size = 0;
}

matrix::matrix(uint16_t size)
{
	this->size = size;
}

matrix::matrix(const matrix& copied)
{
	this->size = copied.size;
}

matrix::~matrix()
{

}


