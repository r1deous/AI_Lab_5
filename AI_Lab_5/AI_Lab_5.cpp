#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void ADD(int omega[], const int num_selection[100][10], int column, int point) {
	for (int i = 1; i < column; i++) {
		if (num_selection[point][i] == 1) {
			omega[i] += 1;
		}
	}
	//cout << "+" << endl;
}
void SUB(int omega[], const int num_selection[100][10], int column, int point) {
	for (int i = 1; i < column; i++) {
		if (num_selection[point][i] == 1) {
			omega[i] -= 1;
		}
	}
	//cout << "-" << endl;
}

void Per_FUNC(const int num[100][10], int m_selection[10][10], const int column, const int rows, const int number) {

	vector<int> prer_err;
	int ret = 0;
	int err = 0;
restart:
	for (int point = 0; point < rows; point++) {
		bool flag = false;
		vector <int> weights = {}; //вектор полученных весов
		vector <int> number_weight = {}; //номер числа полученного веса

		for (int i = 0; i < number; i++) {
			int temp = 0;
			for (int j = 1; j < column; j++) {
				temp += m_selection[i][j] * num[point][j];
			}
			weights.push_back(temp);
		}

		int temp_max = *max_element(weights.begin(), weights.end());
		for (int i = 0; i < weights.size(); i++) {
			if (weights[i] >= temp_max) { number_weight.push_back(i); } //если пришли одиновые макс числа, то записываем их номер тоже
		}

		if (num[point][0] == number_weight[0] and number_weight.size() == 1) { flag = true; } //веса побранны
		else {
			err++;
			for (int iter = 0; iter < number_weight.size(); iter++) {
				int temp = number_weight[iter];
				for (int i = 1; i < column; i++) {
					if (num[point][i] == 1) {
						m_selection[temp][i]--;
					}
				}
			}
			int temp = num[point][0];
			for (int i = 1; i < column; i++) {
				if (num[point][i] == 1) {
					m_selection[temp][i]++;
				}
			}
		}
	}
	ret++;
	prer_err.push_back(err);
//	cout << ret << endl;
	//cout << "check_err = " << err << endl;
	if (ret < 2) { err = 0; goto restart; }

	if (prer_err[ret - 2] > prer_err[ret - 1]) {
		err = 0; goto restart;
	}

	cout << "Кол-во ошибок: " << (*min_element(prer_err.begin(), prer_err.end())) / 2 << endl;
}

int Neuro_Func(int teta, const int column, const int rows, const int nums[100][10], int omega[],
	vector<int> index, vector<int> index_skip, int errors[])
{
	errors[0] = {0};
	//vector<int>vec;
	for (int point = 0; point < rows; point++)
	{
		int weight = 0; 
		for (int i = 1; i < column; i++)
		{
			weight += omega[i] * nums[point][i];
		}

		const int key = nums[point][0];
		if (ranges::find(index_skip.begin(), index_skip.end(), key) != index_skip.end()) //проверка ненужных числел в выборке
		{
			if (weight > teta) //если вес меньше необходимого
			{
				SUB(omega, nums, column, point);
				errors[0]++;
			}
		}
		if (ranges::find(index.begin(), index.end(), key) != index.end())
		{

			if (weight <= teta) //если вес меньше необходимого
			{
				ADD(omega, nums, column, point);
				errors[0]++;
			}
		}
	}
	//vec.push_back(err);
	return errors[0];
}

void TreeOne(const int num_main[100][10], int teta, const int rows)
{
	const int column = 10;
	int errors_in_tree = 0;
	vector<int> errors_mass;
	int errors[1] = { 0 };
	int omega[column] = { 0,-1,0,11,12,1,2,7,14,5 };

	vector<int> index = { 1,3,5,7,9 }, index_skip = { 0,2,4,6,8 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size()*10));

	index = { 7,9 }, index_skip = { 1,3,5 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 7 }, index_skip = { 9 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 9 }, index_skip = { 7 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 1 }, index_skip = { 3,5 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 5 }, index_skip = { 3 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 3 }, index_skip = { 5 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 0,2 }, index_skip = { 4,6,8 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 0 }, index_skip = { 2 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 2 }, index_skip = { 0 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 4 }, index_skip = { 6,8 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 6 }, index_skip = { 8 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 8 }, index_skip = { 6 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	for(auto i : errors_mass)
	{
		if(i < 0)
		{
			errors_in_tree += ~i + 1;
		}
		else
		{
			errors_in_tree += i;
		}
	}

	cout << "Кол-во ошибок: " << errors_in_tree << endl;

	for (auto i : omega) {
		cout << i << " ";
	}cout << endl;
}

void TreeTwo(const int num_main[100][10], int teta, const int rows)
{
	const int column = 10;
	int errors_in_tree = 0;
	vector<int> index, index_skip;
	vector<int> errors_mass;
	int errors[1] = { 0 };
	int omega[column] = { 0,-1,0,11,12,1,2,7,14,5 };

	index = { 0,1,2,3,8,9 }, index_skip = { 4,5,6 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));;

	index = { 0,8,9 }, index_skip = { 1,2,3 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 9 }, index_skip = { 0,8 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 0 }, index_skip = { 8 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 8 }, index_skip = { 9 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 1 }, index_skip = { 2,3 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 2 }, index_skip = { 3 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 3 }, index_skip = { 2 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 5,6 }, index_skip = { 4,7 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 5 }, index_skip = { 6 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 6 }, index_skip = { 5 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 4 }, index_skip = { 7 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	index = { 7 }, index_skip = { 4 };
	Neuro_Func(teta, column, rows, num_main, omega, index, index_skip, errors);
	errors_mass.push_back(errors[0] - (index.size() * 10));

	for (auto i : errors_mass)
	{
		if (i < 0)
		{
			errors_in_tree += ~i + 1;
		}
		else
		{
			errors_in_tree += i;
		}
	}

	cout << "Кол-во ошибок: " << errors_in_tree << endl;
}

int main()
{
	//Код написал Иванов Данила

	setlocale(LC_ALL, "Russian");

	const int rows = 100, column = 10, teta = 35, number = 10;

	const int number_err_0[rows][column] = {
	{4,1,0,0,1,1,0,0,1,0},
	{2,0,1,0,1,0,0,1,0,1},
	{6,0,0,1,0,1,1,0,1,1},
	{3,0,1,1,0,1,0,1,0,0},
	{9,1,1,0,1,1,0,1,0,0},
	{1,0,0,1,1,0,0,0,1,0},
	{7,0,1,1,0,0,1,0,0,0},
	{0,1,1,0,1,0,1,0,1,1},
	{5,1,1,0,0,1,0,0,1,1},
	{8,1,1,0,1,1,1,0,1,1},
	{9,1,1,0,1,1,0,1,0,0},
	{0,1,1,0,1,0,1,0,1,1},
	{5,1,1,0,0,1,0,0,1,1},
	{1,0,0,1,1,0,0,0,1,0},
	{2,0,1,0,1,0,0,1,0,1},
	{8,1,1,0,1,1,1,0,1,1},
	{7,0,1,1,0,0,1,0,0,0},
	{4,1,0,0,1,1,0,0,1,0},
	{6,0,0,1,0,1,1,0,1,1},
	{3,0,1,1,0,1,0,1,0,0},
	{9,1,1,0,1,1,0,1,0,0},
	{3,0,1,1,0,1,0,1,0,0},
	{7,0,1,1,0,0,1,0,0,0},
	{1,0,0,1,1,0,0,0,1,0},
	{5,1,1,0,0,1,0,0,1,1},
	{2,0,1,0,1,0,0,1,0,1},
	{4,1,0,0,1,1,0,0,1,0},
	{0,1,1,0,1,0,1,0,1,1},
	{6,0,0,1,0,1,1,0,1,1},
	{8,1,1,0,1,1,1,0,1,1},
	{0,1,1,0,1,0,1,0,1,1},
	{7,0,1,1,0,0,1,0,0,0},
	{6,0,0,1,0,1,1,0,1,1},
	{8,1,1,0,1,1,1,0,1,1},
	{2,0,1,0,1,0,0,1,0,1},
	{4,1,0,0,1,1,0,0,1,0},
	{9,1,1,0,1,1,0,1,0,0},
	{1,0,0,1,1,0,0,0,1,0},
	{5,1,1,0,0,1,0,0,1,1},
	{3,0,1,1,0,1,0,1,0,0},
	{3,0,1,1,0,1,0,1,0,0},
	{6,0,0,1,0,1,1,0,1,1},
	{0,1,1,0,1,0,1,0,1,1},
	{9,1,1,0,1,1,0,1,0,0},
	{1,0,0,1,1,0,0,0,1,0},
	{2,0,1,0,1,0,0,1,0,1},
	{8,1,1,0,1,1,1,0,1,1},
	{7,0,1,1,0,0,1,0,0,0},
	{4,1,0,0,1,1,0,0,1,0},
	{5,1,1,0,0,1,0,0,1,1},
	{5,1,1,0,0,1,0,0,1,1},
	{1,0,0,1,1,0,0,0,1,0},
	{6,0,0,1,0,1,1,0,1,1},
	{3,0,1,1,0,1,0,1,0,0},
	{8,1,1,0,1,1,1,0,1,1},
	{2,0,1,0,1,0,0,1,0,1},
	{7,0,1,1,0,0,1,0,0,0},
	{4,1,0,0,1,1,0,0,1,0},
	{9,1,1,0,1,1,0,1,0,0},
	{0,1,1,0,1,0,1,0,1,1},
	{1,0,0,1,1,0,0,0,1,0},
	{4,1,0,0,1,1,0,0,1,0},
	{0,1,1,0,1,0,1,0,1,1},
	{9,1,1,0,1,1,0,1,0,0},
	{6,0,0,1,0,1,1,0,1,1},
	{8,1,1,0,1,1,1,0,1,1},
	{3,0,1,1,0,1,0,1,0,0},
	{5,1,1,0,0,1,0,0,1,1},
	{7,0,1,1,0,0,1,0,0,0},
	{2,0,1,0,1,0,0,1,0,1},
	{9,1,1,0,1,1,0,1,0,0},
	{2,0,1,0,1,0,0,1,0,1},
	{7,0,1,1,0,0,1,0,0,0},
	{4,1,0,0,1,1,0,0,1,0},
	{5,1,1,0,0,1,0,0,1,1},
	{3,0,1,1,0,1,0,1,0,0},
	{1,0,0,1,1,0,0,0,1,0},
	{0,1,1,0,1,0,1,0,1,1},
	{8,1,1,0,1,1,1,0,1,1},
	{6,0,0,1,0,1,1,0,1,1},
	{7,0,1,1,0,0,1,0,0,0},
	{9,1,1,0,1,1,0,1,0,0},
	{6,0,0,1,0,1,1,0,1,1},
	{8,1,1,0,1,1,1,0,1,1},
	{0,1,1,0,1,0,1,0,1,1},
	{1,0,0,1,1,0,0,0,1,0},
	{3,0,1,1,0,1,0,1,0,0},
	{5,1,1,0,0,1,0,0,1,1},
	{2,0,1,0,1,0,0,1,0,1},
	{4,1,0,0,1,1,0,0,1,0},
	{6,0,0,1,0,1,1,0,1,1},
	{5,1,1,0,0,1,0,0,1,1},
	{1,0,0,1,1,0,0,0,1,0},
	{3,0,1,1,0,1,0,1,0,0},
	{0,1,1,0,1,0,1,0,1,1},
	{7,0,1,1,0,0,1,0,0,0},
	{9,1,1,0,1,1,0,1,0,0},
	{4,1,0,0,1,1,0,0,1,0},
	{2,0,1,0,1,0,0,1,0,1},
	{8,1,1,0,1,1,1,0,1,1},
	};
	const int number_err_3[rows][column] = {
	{4, 1, 1, 1, 1, 1, 0, 1, 1, 0 },
	{2, 0, 0, 1, 1, 0, 1, 1, 0, 1 },
	{6, 1, 0, 1, 1, 1, 1, 0, 1, 0 },
	{3, 1, 1, 1, 0, 1, 1, 1, 0, 1 },
	{9, 1, 0, 0, 0, 1, 0, 1, 1, 0 },
	{1, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
	{7, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
	{0, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
	{5, 0, 1, 0, 0, 1, 1, 1, 1, 1 },
	{8, 1, 1, 1, 1, 0, 0, 0, 1, 1 },
	{9, 1, 1, 0, 0, 1, 1, 1, 0, 1 },
	{0, 1, 0, 0, 1, 0, 1, 0, 0, 0 },
	{5, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
	{1, 0, 0, 1, 0, 1, 1, 0, 1, 0 },
	{2, 0, 1, 1, 0, 0, 1, 1, 0, 1 },
	{8, 0, 1, 0, 0, 1, 1, 1, 1, 1 },
	{7, 0, 1, 0, 0, 0, 1, 1, 0, 1 },
	{4, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
	{6, 1, 1, 1, 0, 1, 1, 0, 0, 1 },
	{3, 0, 1, 0, 0, 0, 0, 1, 1, 0 },
	{9, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
	{3, 0, 1, 0, 0, 1, 0, 1, 1, 1 },
	{7, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
	{1, 0, 0, 1, 0, 0, 0, 1, 1, 1 },
	{5, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
	{2, 0, 1, 1, 0, 0, 1, 1, 0, 1 },
	{4, 0, 0, 0, 1, 0, 1, 0, 1, 0 },
	{0, 1, 1, 1, 1, 1, 0, 0, 1, 1 },
	{6, 0, 0, 0, 1, 1, 0, 0, 1, 1 },
	{8, 0, 0, 0, 1, 1, 1, 0, 1, 0 },
	{0, 1, 1, 0, 0, 0, 0, 0, 1, 0 },
	{7, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{6, 0, 0, 1, 1, 1, 0, 0, 0, 1 },
	{8, 1, 1, 0, 0, 1, 0, 1, 1, 1 },
	{2, 0, 1, 0, 1, 0, 1, 1, 1, 0 },
	{4, 1, 0, 0, 1, 0, 1, 1, 1, 0 },
	{9, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
	{1, 0, 0, 0, 0, 0, 0, 1, 1, 0 },
	{5, 1, 0, 1, 0, 1, 0, 0, 0, 1 },
	{3, 0, 1, 0, 0, 1, 1, 1, 0, 1 },
	{3, 0, 1, 0, 0, 0, 0, 1, 1, 0 },
	{6, 0, 1, 1, 1, 1, 1, 0, 0, 1 },
	{0, 1, 1, 0, 1, 1, 1, 1, 1, 0 },
	{9, 1, 1, 0, 0, 0, 0, 1, 0, 1 },
	{1, 1, 0, 1, 1, 0, 1, 1, 1, 0 },
	{2, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{8, 1, 1, 0, 1, 1, 1, 1, 0, 0 },
	{7, 0, 1, 1, 0, 0, 0, 1, 1, 0 },
	{4, 1, 0, 1, 0, 1, 0, 1, 1, 0 },
	{5, 1, 0, 1, 0, 1, 1, 0, 1, 1 },
	{5, 1, 1, 0, 0, 1, 1, 1, 0, 1 },
	{1, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
	{6, 0, 1, 1, 1, 1, 1, 0, 1, 0 },
	{3, 0, 1, 0, 0, 1, 1, 1, 1, 0 },
	{8, 1, 0, 0, 1, 1, 0, 0, 0, 1 },
	{2, 0, 1, 0, 0, 0, 1, 1, 0, 0 },
	{7, 0, 1, 1, 1, 0, 0, 0, 0, 1 },
	{4, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
	{9, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
	{0, 0, 1, 0, 1, 0, 0, 0, 1, 0 },
	{1, 0, 0, 0, 1, 1, 1, 0, 1, 0 },
	{4, 0, 1, 0, 1, 1, 1, 0, 1, 0 },
	{0, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
	{9, 1, 1, 0, 1, 0, 0, 1, 1, 1 },
	{6, 0, 1, 1, 0, 1, 0, 0, 1, 0 },
	{8, 1, 1, 0, 0, 1, 0, 0, 0, 1 },
	{3, 1, 1, 1, 0, 0, 0, 1, 0, 1 },
	{5, 0, 1, 0, 1, 1, 0, 0, 1, 0 },
	{7, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
	{2, 0, 0, 0, 1, 0, 1, 0, 0, 1 },
	{9, 1, 1, 0, 1, 0, 1, 1, 1, 0 },
	{2, 1, 1, 0, 1, 0, 1, 0, 0, 1 },
	{7, 1, 1, 1, 0, 0, 1, 1, 1, 0 },
	{4, 1, 1, 1, 1, 1, 0, 0, 1, 1 },
	{5, 0, 0, 0, 0, 1, 0, 1, 1, 1 },
	{3, 0, 1, 1, 0, 0, 1, 1, 0, 1 },
	{1, 0, 1, 1, 1, 1, 1, 0, 1, 0 },
	{0, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
	{8, 1, 1, 1, 1, 0, 0, 0, 1, 1 },
	{6, 1, 0, 1, 1, 0, 1, 0, 1, 1 },
	{7, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
	{9, 0, 1, 0, 1, 0, 0, 1, 0, 1 },
	{6, 1, 0, 1, 0, 1, 0, 0, 0, 1 },
	{8, 1, 1, 0, 0, 0, 1, 1, 1, 1 },
	{0, 0, 1, 0, 1, 1, 0, 0, 1, 1 },
	{1, 0, 0, 0, 1, 0, 1, 1, 1, 0 },
	{3, 0, 1, 0, 1, 1, 0, 1, 1, 0 },
	{5, 0, 1, 0, 0, 1, 0, 0, 0, 0 },
	{2, 0, 0, 0, 1, 0, 1, 0, 0, 1 },
	{4, 1, 1, 1, 1, 1, 1, 0, 1, 0 },
	{6, 0, 1, 1, 0, 1, 1, 0, 0, 0 },
	{5, 1, 0, 1, 0, 1, 1, 0, 1, 1 },
	{1, 0, 0, 1, 1, 0, 1, 0, 0, 1 },
	{3, 1, 1, 0, 0, 0, 0, 1, 0, 0 },
	{0, 0, 0, 0, 1, 0, 0, 0, 1, 1 },
	{7, 0, 1, 1, 1, 1, 1, 0, 0, 1 },
	{9, 1, 1, 0, 1, 0, 1, 1, 1, 0 },
	{4, 1, 1, 0, 0, 1, 0, 1, 1, 0 },
	{2, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
	{8, 0, 1, 0, 1, 0, 0, 0, 1, 1 },
	};
	const int number_err_4[rows][column] = {
		{4, 1, 1, 1, 0, 1, 0, 1, 1, 0 },
		{2, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
		{6, 1, 0, 1, 1, 0, 1, 0, 1, 0 },
		{3, 1, 1, 1, 0, 1, 1, 0, 0, 1 },
		{9, 0, 0, 0, 0, 1, 0, 1, 1, 0 },
		{1, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
		{7, 0, 1, 0, 0, 0, 0, 0, 1, 1 },
		{0, 1, 0, 1, 1, 0, 0, 0, 0, 1 },
		{5, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
		{8, 0, 1, 1, 1, 0, 0, 0, 1, 1 },
		{9, 1, 0, 0, 0, 1, 1, 1, 0, 1 },
		{0, 1, 0, 0, 1, 0, 0, 0, 0, 0 },
		{5, 0, 0, 1, 0, 0, 0, 0, 1, 1 },
		{1, 0, 0, 1, 0, 1, 1, 0, 1, 1 },
		{2, 0, 1, 1, 0, 0, 1, 1, 1, 1 },
		{8, 0, 1, 0, 0, 1, 1, 1, 0, 1 },
		{7, 0, 1, 0, 1, 0, 1, 1, 0, 1 },
		{4, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
		{6, 1, 1, 1, 0, 1, 1, 1, 0, 1 },
		{3, 1, 1, 0, 0, 0, 0, 1, 1, 0 },
		{9, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{3, 0, 0, 0, 0, 1, 0, 1, 1, 1 },
		{7, 0, 0, 0, 0, 0, 1, 1, 0, 1 },
		{1, 0, 1, 1, 0, 0, 0, 1, 1, 1 },
		{5, 1, 1, 0, 0, 0, 0, 1, 0, 0 },
		{2, 0, 1, 1, 0, 0, 1, 1, 1, 1 },
		{4, 0, 0, 1, 1, 0, 1, 0, 1, 0 },
		{0, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
		{6, 1, 0, 0, 1, 1, 0, 0, 1, 1 },
		{8, 0, 0, 0, 1, 1, 0, 0, 1, 0 },
		{0, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
		{7, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
		{6, 0, 1, 1, 1, 1, 0, 0, 0, 1 },
		{8, 1, 1, 0, 0, 1, 0, 1, 0, 1 },
		{2, 0, 0, 0, 1, 0, 1, 1, 1, 0 },
		{4, 1, 0, 0, 1, 0, 1, 1, 0, 0 },
		{9, 0, 1, 0, 1, 1, 1, 0, 1, 0 },
		{1, 0, 1, 0, 0, 0, 0, 1, 1, 0 },
		{5, 1, 0, 1, 1, 1, 0, 0, 0, 0 },
		{3, 0, 1, 0, 0, 0, 1, 1, 0, 1 },
		{3, 0, 0, 0, 0, 0, 0, 1, 1, 0 },
		{6, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
		{0, 1, 1, 0, 1, 1, 1, 1, 0, 0 },
		{9, 0, 1, 0, 0, 0, 0, 1, 0, 1 },
		{1, 1, 0, 1, 0, 0, 1, 1, 1, 0 },
		{2, 0, 0, 0, 0, 0, 1, 0, 0, 1 },
		{8, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
		{7, 0, 1, 1, 0, 0, 0, 1, 1, 1 },
		{4, 1, 1, 1, 0, 1, 0, 1, 1, 0 },
		{5, 1, 0, 1, 0, 1, 1, 0, 0, 1 },
		{5, 1, 1, 1, 0, 1, 1, 1, 0, 1 },
		{1, 1, 1, 1, 1, 0, 1, 0, 0, 0 },
		{6, 0, 1, 1, 1, 1, 1, 0, 0, 0 },
		{3, 0, 1, 0, 0, 1, 1, 0, 1, 0 },
		{8, 1, 0, 0, 1, 1, 0, 1, 0, 1 },
		{2, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
		{7, 0, 1, 1, 1, 0, 0, 1, 0, 1 },
		{4, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
		{9, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
		{0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
		{1, 0, 1, 0, 1, 1, 1, 0, 1, 0 },
		{4, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
		{0, 1, 0, 0, 1, 1, 1, 1, 0, 1 },
		{9, 1, 1, 0, 0, 0, 0, 1, 1, 1 },
		{6, 1, 1, 1, 0, 1, 0, 0, 1, 0 },
		{8, 0, 1, 0, 0, 1, 0, 0, 0, 1 },
		{3, 1, 1, 1, 0, 0, 1, 1, 0, 1 },
		{5, 0, 1, 0, 1, 1, 0, 1, 1, 0 },
		{7, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
		{2, 0, 0, 1, 1, 0, 1, 0, 0, 1 },
		{9, 1, 1, 1, 1, 0, 1, 1, 1, 0 },
		{2, 1, 0, 0, 1, 0, 1, 0, 0, 1 },
		{7, 1, 1, 1, 0, 1, 1, 1, 1, 0 },
		{4, 1, 1, 1, 1, 1, 1, 0, 1, 1 },
		{5, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
		{3, 0, 1, 0, 0, 0, 1, 1, 0, 1 },
		{1, 1, 1, 1, 1, 1, 1, 0, 1, 0 },
		{0, 1, 0, 0, 0, 0, 0, 1, 1, 1 },
		{8, 1, 0, 1, 1, 0, 0, 0, 1, 1 },
		{6, 1, 0, 0, 1, 0, 1, 0, 1, 1 },
		{7, 1, 1, 1, 1, 0, 1, 1, 0, 1 },
		{9, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
		{6, 1, 0, 1, 1, 1, 0, 0, 0, 1 },
		{8, 1, 1, 0, 0, 0, 1, 1, 0, 1 },
		{0, 0, 1, 0, 1, 1, 0, 1, 1, 1 },
		{1, 1, 0, 0, 1, 0, 1, 1, 1, 0 },
		{3, 0, 1, 0, 1, 1, 0, 1, 1, 1 },
		{5, 0, 1, 0, 0, 1, 1, 0, 0, 0 },
		{2, 0, 0, 0, 1, 0, 1, 0, 0, 0 },
		{4, 0, 1, 1, 1, 1, 1, 0, 1, 0 },
		{6, 0, 1, 1, 0, 1, 1, 1, 0, 0 },
		{5, 1, 0, 1, 0, 0, 1, 0, 1, 1 },
		{1, 0, 1, 1, 1, 0, 1, 0, 0, 1 },
		{3, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
		{0, 0, 0, 0, 1, 0, 0, 1, 1, 1 },
		{7, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
		{9, 1, 1, 1, 1, 0, 1, 1, 1, 0 },
		{4, 1, 1, 0, 0, 0, 0, 1, 1, 0 },
		{2, 0, 0, 0, 0, 0, 0, 1, 1, 0 },
		{8, 0, 0, 0, 1, 0, 0, 0, 1, 1 },
	};
	const int number_err_5[rows][column] = {
		{4, 1, 1, 1, 0, 1, 1, 1, 1, 0, },
		{2, 1, 0, 1, 1, 0, 1, 1, 0, 0, },
		{6, 1, 0, 1, 1, 0, 1, 1, 1, 0, },
		{3, 1, 1, 0, 0, 1, 1, 0, 0, 1, },
		{9, 0, 0, 0, 0, 0, 0, 1, 1, 0, },
		{1, 0, 1, 0, 1, 0, 1, 1, 0, 0, },
		{7, 0, 0, 0, 0, 0, 0, 0, 1, 1, },
		{0, 1, 0, 1, 1, 1, 0, 0, 0, 1, },
		{5, 0, 0, 0, 0, 0, 1, 1, 1, 1, },
		{8, 0, 0, 1, 1, 0, 0, 0, 1, 1, },
		{9, 1, 0, 0, 0, 1, 1, 0, 0, 1, },
		{0, 1, 0, 1, 1, 0, 0, 0, 0, 0, },
		{5, 0, 0, 1, 0, 0, 0, 1, 1, 1, },
		{1, 0, 0, 0, 0, 1, 1, 0, 1, 1, },
		{2, 0, 1, 1, 0, 0, 1, 1, 1, 0, },
		{8, 0, 1, 0, 0, 0, 1, 1, 0, 1, },
		{7, 0, 0, 0, 1, 0, 1, 1, 0, 1, },
		{4, 0, 1, 1, 1, 0, 0, 0, 0, 0, },
		{6, 1, 1, 1, 0, 0, 1, 1, 0, 1, },
		{3, 1, 1, 0, 1, 0, 0, 1, 1, 0, },
		{9, 0, 1, 1, 1, 0, 0, 1, 1, 1, },
		{3, 0, 0, 0, 0, 0, 0, 1, 1, 1, },
		{7, 0, 0, 0, 0, 0, 0, 1, 0, 1, },
		{1, 0, 1, 1, 0, 0, 1, 1, 1, 1, },
		{5, 0, 1, 0, 0, 0, 0, 1, 0, 0, },
		{2, 1, 1, 1, 0, 0, 1, 1, 1, 1, },
		{4, 0, 0, 1, 1, 0, 1, 0, 0, 0, },
		{0, 1, 0, 1, 1, 1, 0, 1, 1, 1, },
		{6, 1, 0, 0, 1, 1, 0, 0, 1, 0, },
		{8, 0, 0, 0, 1, 1, 0, 0, 0, 0, },
		{0, 0, 1, 0, 0, 0, 0, 1, 1, 0, },
		{7, 0, 0, 0, 0, 1, 0, 1, 0, 0, },
		{6, 0, 1, 0, 1, 1, 0, 0, 0, 1, },
		{8, 0, 1, 0, 0, 1, 0, 1, 0, 1, },
		{2, 0, 0, 1, 1, 0, 1, 1, 1, 0, },
		{4, 1, 0, 1, 1, 0, 1, 1, 0, 0, },
		{9, 0, 1, 0, 1, 1, 1, 0, 1, 1, },
		{1, 0, 1, 0, 0, 0, 0, 1, 0, 0, },
		{5, 1, 0, 1, 1, 1, 1, 0, 0, 1, },
		{3, 0, 1, 0, 1, 0, 1, 1, 0, 1, },
		{3, 0, 0, 0, 0, 0, 0, 0, 1, 0, },
		{6, 0, 1, 1, 1, 1, 0, 1, 0, 1, },
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, },
		{9, 0, 0, 0, 0, 0, 0, 1, 0, 1, },
		{1, 1, 1, 1, 0, 0, 1, 1, 1, 0, },
		{2, 0, 0, 0, 0, 0, 1, 0, 1, 1, },
		{8, 0, 1, 1, 1, 1, 1, 1, 0, 0, },
		{7, 0, 0, 1, 0, 0, 0, 1, 1, 1, },
		{4, 1, 1, 1, 0, 0, 0, 1, 1, 0, },
		{5, 0, 0, 1, 0, 1, 1, 0, 0, 1, },
		{5, 1, 1, 1, 1, 1, 1, 1, 0, 1, },
		{1, 1, 1, 0, 1, 0, 1, 0, 0, 0, },
		{6, 0, 1, 1, 1, 0, 1, 0, 0, 0, },
		{3, 1, 1, 0, 0, 1, 1, 0, 1, 0, },
		{8, 1, 0, 0, 1, 0, 0, 1, 0, 1, },
		{2, 0, 1, 1, 0, 0, 1, 1, 1, 0, },
		{7, 0, 1, 1, 1, 1, 0, 1, 0, 1, },
		{4, 0, 0, 1, 0, 0, 0, 0, 0, 0, },
		{9, 0, 0, 0, 1, 0, 1, 1, 0, 1, },
		{0, 0, 1, 0, 1, 0, 0, 1, 0, 0, },
		{1, 0, 1, 0, 1, 1, 1, 0, 1, 1, },
		{4, 0, 1, 0, 1, 0, 1, 0, 1, 1, },
		{0, 1, 0, 0, 1, 1, 1, 1, 0, 0, },
		{9, 1, 1, 0, 0, 0, 0, 0, 1, 1, },
		{6, 1, 1, 1, 0, 1, 0, 0, 0, 0, },
		{8, 0, 0, 0, 0, 1, 0, 0, 0, 1, },
		{3, 1, 1, 1, 0, 0, 1, 0, 0, 1, },
		{5, 0, 1, 1, 1, 1, 0, 1, 1, 0, },
		{7, 0, 0, 0, 1, 0, 0, 1, 0, 0, },
		{2, 0, 0, 1, 1, 0, 1, 0, 1, 1, },
		{9, 1, 1, 1, 0, 0, 1, 1, 1, 0, },
		{2, 1, 0, 0, 1, 0, 1, 0, 1, 1, },
		{7, 1, 1, 1, 0, 1, 1, 1, 1, 1, },
		{4, 0, 1, 1, 1, 1, 1, 0, 1, 1, },
		{5, 0, 0, 0, 0, 0, 0, 1, 0, 1, },
		{3, 0, 0, 0, 0, 0, 1, 1, 0, 1, },
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, },
		{0, 1, 0, 1, 0, 0, 0, 1, 1, 1, },
		{8, 1, 0, 1, 1, 0, 0, 0, 1, 0, },
		{6, 1, 0, 0, 1, 0, 0, 0, 1, 1, },
		{7, 1, 0, 1, 1, 0, 1, 1, 0, 1, },
		{9, 0, 0, 0, 1, 0, 0, 1, 1, 1, },
		{6, 1, 0, 1, 1, 1, 0, 1, 0, 1, },
		{8, 1, 1, 1, 0, 0, 1, 1, 0, 1, },
		{0, 0, 1, 1, 1, 1, 0, 1, 1, 1, },
		{1, 1, 0, 0, 0, 0, 1, 1, 1, 0, },
		{3, 0, 1, 0, 1, 0, 0, 1, 1, 1, },
		{5, 0, 1, 0, 0, 0, 1, 0, 0, 0, },
		{2, 0, 0, 0, 0, 0, 1, 0, 0, 0, },
		{4, 0, 1, 1, 1, 1, 1, 1, 1, 0, },
		{6, 0, 1, 1, 0, 0, 1, 1, 0, 0, },
		{5, 1, 0, 1, 0, 0, 1, 1, 1, 1, },
		{1, 0, 1, 0, 1, 0, 1, 0, 0, 1, },
		{3, 1, 0, 0, 0, 0, 0, 1, 1, 0, },
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, },
		{7, 0, 1, 1, 1, 1, 0, 1, 0, 1, },
		{9, 1, 1, 1, 1, 0, 1, 1, 1, 1, },
		{4, 0, 1, 0, 0, 0, 0, 1, 1, 0, },
		{2, 1, 0, 0, 0, 0, 0, 1, 1, 0, },
		{8, 0, 0, 0, 0, 0, 0, 0, 1, 1, },
	};

	int main_selection[number][column] = {
		{0, 5,5,3,4,10,5,10,9,9},
		{1, 2,3,5,10,6,7,8,14,10},
		{2, 0,9,5,11,6,5,17,7,16},
		{3, 2,11,12,4,13,6,18,7,9},
		{4, 8,4,5,4,10,7,11,13,9},
		{5, 100,9,8,4,14,1,6,10,16},
		{6, 4,5,12,7,12,12,13,1,15},
		{7, 6,12,11,5,8,16,14,100,7},
		{8, 5,13,1,0,9,20,27,10,3},
		{9, 5,7,5,3,9,8,10,9,6},
	};

	cout << "Персептрон" << endl;
	cout << "0 помех: " << endl;
	Per_FUNC(number_err_0, main_selection, column, rows, number);
	cout << " 3 помехи: " << endl;
	Per_FUNC(number_err_3, main_selection, column, rows, number);
	cout << " 4 помехи: " << endl;
	Per_FUNC(number_err_4, main_selection, column, rows, number);
	cout << " 5 помехи: " << endl;
	Per_FUNC(number_err_5, main_selection, column, rows, number);

	///////////////////////////////////
	cout << endl;
	cout << "Первое дерево"<<endl;
	cout << " 0 помех:" << endl;
	cout << "Кол-во ошибок: 0" << endl;
	cout<<" 3 помехи: " << endl;
	TreeOne(number_err_3, teta, rows);
	cout << " 4 помехи: " << endl;
	TreeOne(number_err_4, teta, rows);
	cout << " 5 помех: " << endl;
	TreeOne(number_err_5, teta, rows);
	////////////////////////////////////
	cout << endl;
	cout << "Второе дерево" << endl;
	cout << " 0 помех:" << endl;
	cout << "Кол-во ошибок: 0" << endl;
	cout<<" 3 помехи: " << endl;
	TreeTwo(number_err_3, teta, rows);
	cout << " 4 помехи: " << endl;
	TreeTwo(number_err_4, teta, rows);
	cout << " 5 помех: " << endl;
	TreeTwo(number_err_5, teta, rows);

}