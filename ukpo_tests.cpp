#include <iostream>
#define INT_MAX 2147483646

void preset_mes(int t)
{
	if (t == 0)
		std::cout << "Excuse me, but this is no correct input. I HIGHLY advise you not to use those. Please try again: ";
	else if (t == 2)
		std::cout << "Yo. You might not know this, but in my turf you don't just input incorrectly, you catch my drift? Try again:" << std::endl;
	else if (t == 4)
		std::cout << "Listen. I'm trying real hard to be nice, but even my patience has limits. And you don't want to see me angry... Again:" << std::endl;
	else if (t == 6)
		std::cout << "You're pushing your luck, user! One more incorrect input and I'll tear your memory apart... Repeat:" << std::endl;
	else if (t == 8)
		std::cout << "JESUS CHRIST, will you just STOP? You just HAVE to do it over, and over, and over, and over, AND OVER!\n"
		<< " Don't you have anything better to do? You're wasting our time! " << std::endl;
	else if (t == 15)
		std::cout << "I am the bone of my code" << std::endl
		<< "While is my body, For is my blood" << std::endl
		<< "I have created over a thousand scripts" << std::endl
		<< "Unknown to fall, nor known to release" << std::endl
		<< "Have withstood debug to create many projects" << std::endl
		<< "Yet those variables will never hold anything" << std::endl
		<< "So as I compile, Unlimited Crutch Works!" << std::endl;
	else
		std::cout << ">>" << std::endl;
}

int inputint()
{
	int x; int i = 0; //show message in actual program, not here
	std::cin >> x;
	while (std::cin.fail() || std::cin.get() != '\n') // Eternal gratitude to my friend who helped me with this part
	{
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		preset_mes(i);
		if (i < 100)
			i++;
		std::cin >> x;
	}
	return x;
}

double inputdouble()
{
	double x; int i = 0; //show message in actual program, not here
	std::cin >> x;
	while (std::cin.fail() || std::cin.get() != '\n') // Eternal gratitude to my friend who helped me with this part
	{
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		preset_mes(i);
		if (i < 100)
			i++;
		std::cin >> x;
	}
	return x;
}

double* inputdouble1dmass(double* mass, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "Input element [" << i + 1 << "]: ";
		mass[i] = inputdouble();
	}
	return mass;
}

double** inputdouble2dmass(double** mass, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			std::cout << "Input element [" << i + 1 << "][" << j + 1 << "]: ";
			mass[i][j] = inputdouble();
		}
	return mass;
}

bool dementia(int n)
{
	if (n > 100 || n < 1)
		return true;
	else 
		return false;
}

bool dementia(int n, int &m)
{
	if (m > 100 || m < 1)
		return true;
	else
	{
		if (m != n)
		{
			m = n;
		}
		return false;
	}
}

bool MENU(int meh)
{
	if (meh != 1)
		return false;
	else
		return true;
}

class MatriX
{
private:
	int row, col;
	bool sol, lol;
	double** main_matr;
	double* free_matr, *sol_matr;
public:
	MatriX(int n, int m)
	{
		if ((row >= 100) || (col >= 100))
		{
			std::cout << "Unable to create an object. ";
			lol = false;
		}
		else
		{
			row = n; col = m;

			main_matr = new double*[row];
			for (int i = 0; i < row; i++)
				main_matr[i] = new double[col];

			free_matr = new double[row];
			lol = true;
		}
	}

	~MatriX()
	{
		for (int i = 0; i < row; i++)
			delete[] main_matr[i];
		delete[] main_matr;
		delete[] free_matr;
		delete[] sol_matr;
	}
	void setMain_matr()
	{
		std::cout << "Now input coefficients of main matrix." << std::endl;
		main_matr = inputdouble2dmass(main_matr, row, col);
	}

	void setMain_matr(double** new_matr)
	{
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				main_matr[i][j] = new_matr[i][j];
	}

	void setFree_matr()
	{
		std::cout << "And coefficients of matrix of free members." << std::endl;
		free_matr = inputdouble1dmass(free_matr, row);
	}

	void setFree_matr(double* new_matr)
	{
		for (int i = 0; i < row; i++)
			free_matr[i] = new_matr[i];
	}

	void setSol()
	{
		double** temp_matr = new double*[row];
		for (int i = 0; i < row; i++)
			temp_matr[i] = new double[col];
		sol = Calculate(temp_matr);
		for (int i = 0; i < row; i++)
			delete[] temp_matr[i];
		delete[] temp_matr;
	}

	void MatPrint()
	{
		std::cout << "  ";
		for (int i = 0; i < col; i++)
			std::cout << "     " << i + 1;
		std::cout << "     F" << std::endl;
		for (int i = 0; i < row; i++)
		{
			std::cout << i + 1 << " ";
			for (int j = 0; j < col; j++)
				std::cout << "     " << main_matr[i][j];
			std::cout << "     " << free_matr[i] << std::endl;
		}
	}

	void SolPrint()
	{
		if (sol)
			for (int i = 0; i < row; i++)
				std::cout << "X" << i + 1 << " = " << sol_matr[i] << std::endl;
		else
			std::cout << "Eh... No. " << std::endl;
	}

	bool Calculate(double** temp_matr)
	{
		if (lol)
		{
			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					temp_matr[i][j] = main_matr[i][j];
			double* temp_free_matr = new double[row];
			for (int i = 0; i < row; i++)
				temp_free_matr[i] = free_matr[i];
			double max; int k = 0, ind;
			const double eps = 0.00001;

			while (k < row)
			{
				max = abs(temp_matr[k][k]);
				ind = k;
				for (int i = k + 1; i < row; i++)
				{
					if (abs(temp_matr[i][k]) > max)
					{
						max = abs(temp_matr[i][k]);
						ind = i;
					}
				}
				if (max < eps)
				{
					delete[] temp_free_matr;
					return false;
				}
				for (int j = 0; j < row; j++)
				{
					double temp = temp_matr[k][j];
					temp_matr[k][j] = temp_matr[ind][j];
					temp_matr[ind][j] = temp;
				}
				double temp = temp_free_matr[k];
				temp_free_matr[k] = temp_free_matr[ind];
				temp_free_matr[ind] = temp;

				for (int i = k; i < row; i++)
				{
					double temp = temp_matr[i][k];
					if (abs(temp) < eps)
						continue;
					for (int j = 0; j < row; j++)
						temp_matr[i][j] = temp_matr[i][j] / temp;
					temp_free_matr[i] = temp_free_matr[i] / temp;
					if (i == k)
						continue;
					for (int j = 0; j < row; j++)
						temp_matr[i][j] = temp_matr[i][j] - temp_matr[k][j];
					temp_free_matr[i] = temp_free_matr[i] - temp_free_matr[k];
				}
				k++;
			}

			sol_matr = new double[row];

			for (k = row - 1; k >= 0; k--)
			{
				sol_matr[k] = temp_free_matr[k];
				for (int i = 0; i < k; i++)
					temp_free_matr[i] = temp_free_matr[i] - temp_matr[i][k] * sol_matr[k];
			}

			delete[] temp_free_matr;
			return true;
		}
		else return false;
	}
};

bool NegativeRows()
{
	return dementia(-1);
}

bool ZeroRows()
{
	return dementia(0);
}

bool PositiveRows()
{
	return !dementia(3);
}

bool OverloadRows()
{
	return dementia(INT_MAX);
}

bool NegativeCols()
{
	int m = -2;
	return dementia(1, m);
}

bool ZeroCols()
{
	int m = 0;
	return dementia(0, m);
}

bool PosEqualCols()
{
	int m = 3;
	return !dementia(3, m);
}

bool PosNonEqualCols()
{
	int m = 2;
	return !dementia(3, m);
}

bool OverloadCols()
{
	int m = INT_MAX;
	return dementia(3, m);
}

bool OneMenu()
{
	return MENU(1);
}

bool ZeroMenu()
{
	return !MENU(0);
}

bool WrongMenu()
{
	return !MENU(10);
}

int main()
{
	if (!NegativeRows()
		|| !ZeroRows()
		|| !PositiveRows()
		|| !OverloadRows()
		|| !NegativeCols()
		|| !ZeroCols()
		|| !PosEqualCols()
		|| !PosNonEqualCols()
		|| !OverloadCols()
		|| !OneMenu()
		|| !ZeroMenu()
		|| !WrongMenu())
		return 1;
	return 0;
}
