#include <iostream>
#include <vector>
#include <locale>
#include <algorithm>
#include <fstream>

#include "DistationLeven.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");

	DistationLeven distationLeven;
	clock_t startRec = clock();
	std::cout << "���������������->����������������� = "
		<< distationLeven.GetDistationDinamic("���������������", strlen("���������������"), "�����������������", strlen("�����������������")) << std::endl;
	clock_t stopRec = clock();
	std::cout << "����� ����������: " << stopRec - startRec << std::endl;

	system("pause");
}