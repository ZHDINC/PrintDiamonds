#include<iostream>

int main()
{
	int rows_of_diamonds = 0;
	int columns_of_diamonds = 0;
	int num_of_hash = 1;
	int row_of_row = -1;
	bool firstrun = true;
	bool reverse = false;
	bool middlelinecheck = false;
	int max_diamond_size = 0;
	std::cout << "Enter the number of rows of diamonds you want: ";
	std::cin >> rows_of_diamonds;
	std::cout << "Enter the number of columns of diamonds you want: ";
	std::cin >> columns_of_diamonds;
	std::cout << "Enter the maximum diamond size you want (only odd values): ";
	std::cin >> max_diamond_size;
	int num_of_space = max_diamond_size - 2;
	int diamondstoprint = rows_of_diamonds * max_diamond_size - rows_of_diamonds + 1;
	for (auto x = 0; x < num_of_space; x += 2)
	{
		row_of_row++;
	}
	int middlelinehashmax = max_diamond_size * columns_of_diamonds;
	int actualhashstate = max_diamond_size - 1;
	int actualhashtracker = 0;
	for (auto x = 0; x < columns_of_diamonds; x++)
	{
		if (x == 0)
		{
			actualhashtracker = max_diamond_size; // Only on the first iteration do the number of hashes needed to print and printed hashes match.
		}
		else
		{
			actualhashtracker += actualhashstate;
		}
	}
	for (auto i = 0; i < diamondstoprint; i++)
	{
		if (num_of_hash >= max_diamond_size)
		{
			reverse = true;
			middlelinecheck = true;
		}
		/*
			This section only runs on lines that print both hashes and spaces because there is no overlap. 
			On middle lines, the loop for printing spaces doesn't even run and loop for printing of hashes iterates too many times.
		*/
		if (middlelinecheck == false)
		{
			for (auto l = 0; l < columns_of_diamonds; l++)
			{
				for (auto x = 0; x < num_of_space; x++)
				{
					if (firstrun) // In the event that it is the first column and less spaces needs to be printed
					{
						x += row_of_row;
						firstrun = false;
					}
					std::cout << " ";
				}
				for (auto y = 0; y < num_of_hash; y++)
				{
					std::cout << "#";
				}
			}
		}
		else
		{
			for (auto x = 0; x < actualhashtracker; x++)
			{
				std::cout << "#";
			}
		}
		middlelinecheck = false;
		if (!reverse)
		{
			num_of_hash += 2;
			num_of_space -= 2;
			row_of_row--;
		}
		else
		{
			num_of_hash -= 2;
			num_of_space += 2;
			row_of_row++;
			if (num_of_hash == 1)
			{
				reverse = false;
			}
		}
		std::cout << std::endl;
		firstrun = true;
	}
}