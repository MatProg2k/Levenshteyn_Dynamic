#include "DistationLeven.h"
#include <vector>
#include <map>

int DistationLeven::GetDistationDinamic(std::string str_1, int size_1, std::string str_2, int size_2)
{
	std::vector<std::vector<int>> temp(size_1 + 1, std::vector<int>(size_2 + 1));

	temp[0][0] = NULL;

	for (int i = 0; i < size_2; i++)
	{
		temp[0][i + 1] = temp[0][i] + 1;
	}

	for (int i = 0; i < size_1; i++)
	{
		temp[i + 1][0] = temp[i][0] + 1;
		for (int j = 0; j < size_2; j++)
		{
			temp[i + 1][j + 1] = this->Min(
				temp[i][j + 1] + 1,
				temp[i + 1][j] + 1,
				temp[i][j] + this->ReplaceCoast(str_1[i], str_2[j])
			);
		}
	}

	return temp[size_1][size_2];
}

int DistationLeven::ReplaceCoast(char first, char second)
{
	if (first == second)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int DistationLeven::Min(int value_1, int value_2, int value_3)
{
	if ((value_1 <= value_2) && (value_1 <= value_3))
		return value_1;
	else if ((value_2 <= value_1) && (value_2 <= value_3))
		return value_2;
	else
		return value_3;
}
