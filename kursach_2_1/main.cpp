#include "MatrixClasses.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	
	Matrix B(3, "int");
	Matrix C;

	
	cout << "�1-------�1" << endl; 
	cin >> B;
	cout << B;
	B.FileOut("out.txt");

	C.SetType("float");
	cin >> C;
	cout << C;

	Matrix A(C);
	cout << A;
	cout << "�1-------�1" << endl << endl;


	cout << "�2-------�2" << endl;
	A.SetType("int");
	A.FileIn("in.txt");
	cout << A;
	cout << "�2-------�2" << endl << endl;


	cout << "�3------�3" << endl;
	cout << B;
	B = A;
	cout << B;
	cout << "�3-------�3" << endl << endl;


	cout << "�4-------�4" << endl;
	cout << B;
	unsigned i, j;
	cin >> i >> j;
	B.Editin(i, j);
	cout << B;
	cout << "�4-------�4" << endl << endl;


	cout << "�5-------�5" << endl;
	cout << A;
	cout << C;

	A = C;

	cout << A;
	cout << C;
	cout << "�5-------�5" << endl << endl;


	cout << "�6-------�6" << endl;
	cout << A;
	cout << B;
	cout << C;

	B = (A / C);

	cout << A;
	cout << B;
	cout << C;
	cout << "�6-------�6" << endl << endl;
	
	return 0;
}


/*

	while (true)
	{
		cout << "�������� ����� ����: " << endl
			<< "1 - ����/����� � �������" << endl
			<< "2 - ��������� ����/�����" << endl
			<< "3 - ���������� ��� �������������� ��� ��� ������ ������" << endl
			<< "4 - ������������ �������" << endl
			<< "0 - ����� �� ���������" << endl;
		cin >> menu;

		if (!menu)
			break;

		switch (menu)
		{
		case 1:
		{
			cout << "�������� ����� ����: " << endl
				<< "1 - ���� �������" << endl
				<< "2 - ����� �������" << endl
				<< "3 - ��������� ��������" << endl;
			cin >> menu;

			switch (menu)
			{
			case 1:
			{
				char menu1;
				std::string typem;
				cout << "�������� �������: ";
				cin >> menu1;
				switch (menu1)
				{
				case 'A':
				{
					cout << "������� ���: ";
					cin >> typem;
					A.SetType(typem);
					cin >> A;
					break;
				}
				case 'B':
				{
					cout << "������� ���: ";
					cin >> typem;
					B.SetType(typem);
					cin >> B;
					break;
				}
				case 'C':
				{
					cout << "������� ���: ";
					cin >> typem;
					C.SetType(typem);
					cin >> C;
					break;
				}
				default:
					break;
				}
				break;
			}
			case 2:
			{
				char menu1;
				std::string typem;
				cout << "�������� �������: ";
				cin >> menu1;
				switch (menu1)
				{
				case 'A':
				{
					cout << A;
					break;
				}
				case 'B':
				{
					cout << B;
					break;
				}
				case 'C':
				{
					cout << C;
					break;
				}
				default:
					break;
				}
				break;
			}
			case 3:
			{

				break;
			}
			default:
				break;
			}

			break;
		}
		case 2:
		{

			break;
		}
		case 3:
		{

			break;
		}
		case 4:
		{

			break;
		}
		default:
			break;
		}
	}

*/