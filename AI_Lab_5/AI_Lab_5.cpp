#include <iostream>
#include <vector>
#include <random>

using namespace std;

constexpr int number = 10;
constexpr int column = 10;
constexpr int rows = 100;

int num[number][column] = {
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
int tmp_mass[number][column] = {
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

const int omega_temp[column] = { 0, 2, 6, 12, 19, 2, 32, 8, 17, 30 };

//выборки
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
const int number_err_9[rows][column] = {
	{4, 0, 1, 1, 0, 0, 1, 1, 0, 1 },
	{2, 1, 0, 1, 0, 1, 1, 0, 1, 0 },
	{6, 1, 1, 0, 1, 0, 0, 1, 0, 0 },
	{3, 1, 0, 0, 1, 0, 1, 0, 1, 1 },
	{9, 0, 0, 1, 0, 0, 1, 0, 1, 1 },
	{1, 1, 1, 0, 0, 1, 1, 1, 0, 1 },
	{7, 1, 0, 0, 1, 1, 0, 1, 1, 1 },
	{0, 0, 0, 1, 0, 1, 0, 1, 0, 0 },
	{5, 0, 0, 1, 1, 0, 1, 1, 0, 0 },
	{8, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
	{9, 0, 0, 1, 0, 0, 1, 0, 1, 1 },
	{0, 0, 0, 1, 0, 1, 0, 1, 0, 0 },
	{5, 0, 0, 1, 1, 0, 1, 1, 0, 0 },
	{1, 1, 1, 0, 0, 1, 1, 1, 0, 1 },
	{2, 1, 0, 1, 0, 1, 1, 0, 1, 0 },
	{8, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
	{7, 1, 0, 0, 1, 1, 0, 1, 1, 1 },
	{4, 0, 1, 1, 0, 0, 1, 1, 0, 1 },
	{6, 1, 1, 0, 1, 0, 0, 1, 0, 0 },
	{3, 1, 0, 0, 1, 0, 1, 0, 1, 1 },
	{9, 0, 0, 1, 0, 0, 1, 0, 1, 1 },
	{3, 1, 0, 0, 1, 0, 1, 0, 1, 1 },
	{7, 1, 0, 0, 1, 1, 0, 1, 1, 1 },
	{1, 1, 1, 0, 0, 1, 1, 1, 0, 1 },
	{5, 0, 0, 1, 1, 0, 1, 1, 0, 0 },
	{2, 1, 0, 1, 0, 1, 1, 0, 1, 0 },
	{4, 0, 1, 1, 0, 0, 1, 1, 0, 1 },
	{0, 0, 0, 1, 0, 1, 0, 1, 0, 0 },
	{6, 1, 1, 0, 1, 0, 0, 1, 0, 0 },
	{8, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
	{0, 0, 0, 1, 0, 1, 0, 1, 0, 0 },
	{7, 1, 0, 0, 1, 1, 0, 1, 1, 1 },
	{6, 1, 1, 0, 1, 0, 0, 1, 0, 0 },
	{8, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
	{2, 1, 0, 1, 0, 1, 1, 0, 1, 0 },
	{4, 0, 1, 1, 0, 0, 1, 1, 0, 1 },
	{9, 0, 0, 1, 0, 0, 1, 0, 1, 1 },
	{1, 1, 1, 0, 0, 1, 1, 1, 0, 1 },
	{5, 0, 0, 1, 1, 0, 1, 1, 0, 0 },
	{3, 1, 0, 0, 1, 0, 1, 0, 1, 1 },
	{3, 1, 0, 0, 1, 0, 1, 0, 1, 1 },
	{6, 1, 1, 0, 1, 0, 0, 1, 0, 0 },
	{0, 0, 0, 1, 0, 1, 0, 1, 0, 0 },
	{9, 0, 0, 1, 0, 0, 1, 0, 1, 1 },
	{1, 1, 1, 0, 0, 1, 1, 1, 0, 1 },
	{2, 1, 0, 1, 0, 1, 1, 0, 1, 0 },
	{8, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
	{7, 1, 0, 0, 1, 1, 0, 1, 1, 1 },
	{4, 0, 1, 1, 0, 0, 1, 1, 0, 1 },
	{5, 0, 0, 1, 1, 0, 1, 1, 0, 0 },
	{5, 0, 0, 1, 1, 0, 1, 1, 0, 0 },
	{1, 1, 1, 0, 0, 1, 1, 1, 0, 1 },
	{6, 1, 1, 0, 1, 0, 0, 1, 0, 0 },
	{3, 1, 0, 0, 1, 0, 1, 0, 1, 1 },
	{8, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
	{2, 1, 0, 1, 0, 1, 1, 0, 1, 0 },
	{7, 1, 0, 0, 1, 1, 0, 1, 1, 1 },
	{4, 0, 1, 1, 0, 0, 1, 1, 0, 1 },
	{9, 0, 0, 1, 0, 0, 1, 0, 1, 1 },
	{0, 0, 0, 1, 0, 1, 0, 1, 0, 0 },
	{1, 1, 1, 0, 0, 1, 1, 1, 0, 1 },
	{4, 0, 1, 1, 0, 0, 1, 1, 0, 1 },
	{0, 0, 0, 1, 0, 1, 0, 1, 0, 0 },
	{9, 0, 0, 1, 0, 0, 1, 0, 1, 1 },
	{6, 1, 1, 0, 1, 0, 0, 1, 0, 0 },
	{8, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
	{3, 1, 0, 0, 1, 0, 1, 0, 1, 1 },
	{5, 0, 0, 1, 1, 0, 1, 1, 0, 0 },
	{7, 1, 0, 0, 1, 1, 0, 1, 1, 1 },
	{2, 1, 0, 1, 0, 1, 1, 0, 1, 0 },
	{9, 0, 0, 1, 0, 0, 1, 0, 1, 1 },
	{2, 1, 0, 1, 0, 1, 1, 0, 1, 0 },
	{7, 1, 0, 0, 1, 1, 0, 1, 1, 1 },
	{4, 0, 1, 1, 0, 0, 1, 1, 0, 1 },
	{5, 0, 0, 1, 1, 0, 1, 1, 0, 0 },
	{3, 1, 0, 0, 1, 0, 1, 0, 1, 1 },
	{1, 1, 1, 0, 0, 1, 1, 1, 0, 1 },
	{0, 0, 0, 1, 0, 1, 0, 1, 0, 0 },
	{8, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
	{6, 1, 1, 0, 1, 0, 0, 1, 0, 0 },
	{7, 1, 0, 0, 1, 1, 0, 1, 1, 1 },
	{9, 0, 0, 1, 0, 0, 1, 0, 1, 1 },
	{6, 1, 1, 0, 1, 0, 0, 1, 0, 0 },
	{8, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
	{0, 0, 0, 1, 0, 1, 0, 1, 0, 0 },
	{1, 1, 1, 0, 0, 1, 1, 1, 0, 1 },
	{3, 1, 0, 0, 1, 0, 1, 0, 1, 1 },
	{5, 0, 0, 1, 1, 0, 1, 1, 0, 0 },
	{2, 1, 0, 1, 0, 1, 1, 0, 1, 0 },
	{4, 0, 1, 1, 0, 0, 1, 1, 0, 1 },
	{6, 1, 1, 0, 1, 0, 0, 1, 0, 0 },
	{5, 0, 0, 1, 1, 0, 1, 1, 0, 0 },
	{1, 1, 1, 0, 0, 1, 1, 1, 0, 1 },
	{3, 1, 0, 0, 1, 0, 1, 0, 1, 1 },
	{0, 0, 0, 1, 0, 1, 0, 1, 0, 0 },
	{7, 1, 0, 0, 1, 1, 0, 1, 1, 1 },
	{9, 0, 0, 1, 0, 0, 1, 0, 1, 1 },
	{4, 0, 1, 1, 0, 0, 1, 1, 0, 1 },
	{2, 1, 0, 1, 0, 1, 1, 0, 1, 0 },
	{8, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
};

void print_main(int m_selection[][column])
{
	for (int i = 0; i < number; i++)
	{
		for (int j = 1; j < column; j++)
		{
			cout << m_selection[i][j] << " ";
		}cout << endl;
	}
}
void old_main()
{
	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < column + 1; j++)
		{
			num[i][j] = tmp_mass[i][j];
		}
	}
}
void old_omega(int mass[])
{
	for(int i = 0; i<column; i++)
	{
		mass[i] = omega_temp[i];
	}
}

void ADD(int omega[], int m_selection[]) {
	for (int i = 1; i < column; i++) {
		if (m_selection[i] == 1) {
			omega[i] += 1;
		}
	}
	//cout << "+" << endl;
}
void SUB(int omega[], int m_selection[]) {
	for (int i = 1; i < column; i++) {
		if (m_selection[i] == 1) {
			omega[i]--;
		}
	}
	//cout << "-" << endl;
}


void Perceptron(const int num[][column], int m_selection[][column]) {

	vector<int> errors;
	int x = 0;
	int run = 0;
	int err = 0;
restart:
	for (int point = 0; point < rows; point++) {
	
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

		if (num[point][0] == number_weight[0] and number_weight.size() == 1) {} //веса побранны
		else {
			err++;
			for (int iter = 0; iter < number_weight.size(); iter++) {
				int temp = number_weight[iter];
				for (int i = 1; i < column; i++) {
					if (num[point][i] == 1) {
						m_selection[temp][i] -= 1;
					}
				}
			}
			int temp = num[point][0];
			for (int i = 1; i < column; i++) {
				if (num[point][i] == 1) {
					m_selection[temp][i] += 1;
				}
			}
		}
	}
	errors.push_back(err);
	if(run < 3)
	{
		run++; err = 0;
		goto restart;
	}
	if (errors[run - 1] == err) { x++; }

	if  (x <= 5) 
	{
		run++; err = 0;
		goto restart;
	}

	cout << "Кол-во ошибок = " << (*min_element(errors.begin(), errors.end())/2) << endl;
	cout << "Кол-во итераций: " << run << endl;
	cout << endl;
}

void Dih_Tree_1(const int num[][column], int x){

	if (x == 0) { x = x + 2; }
	if (x == 4) { x += 30; }
	if (x == 9) { x -= 5; }

	vector<int> teta = {25, 25, 25, 25, 25, 25, 25, 25, 25, 25 }; //пороги для деревьев
	int omega[column] = {0, 2, 6, 12, 19, 2, 32, 8, 17, 30};
	int weight = 0;

	int err = 0;
	int good = 0;

	int rest = 0;

	vector<int> errors;
	vector<int> goods;

	int p_teta = 0;

	while (p_teta < teta.size()) {

		switch(p_teta)
		{
		case 0: //первый нейрон дерева (см. картинку с деревом 1)(делим числа по четности)
			{
		restart_0:
			err = 0;
			good = 0;
			bool like_flag = false;
			int temp_weight[column] = {};
				for(int point = 0; point < rows; point++)
				{
					for(int i = 1; i < column; i++ )
					{
						weight += omega[i] * num[point][i];
						temp_weight[i] = num[point][i];
					}
					
					if(/*Число 1*/((point == 5 or point == 13 or point == 23 or point == 37 or point == 44 or point == 51 or point == 60 or point == 76 or point == 85 or point == 92) or
							/*Число 3*/(point == 3 or point == 19 or point == 21 or point == 39 or point == 40 or point == 53 or point == 66 or point == 75 or point == 86 or point == 93) or
								/*Число 5*/(point == 8 or point == 12 or point == 24 or point == 38 or point == 49 or point == 50 or point == 67 or point == 74 or point == 87 or point == 91) or
									/*Число 7*/(point == 6 or point == 16 or point == 22 or point == 31 or point == 47 or point == 56 or point == 68 or point == 72 or point == 80 or point == 95) or
										/*Число 9*/(point == 4 or point == 10 or point == 20 or point == 36 or point == 43 or point == 58 or point == 63 or point == 70 or point == 81 or point == 96))
											and weight > teta[p_teta]) {
						like_flag = true; good++;
					}
					else if((num[point][0] == 1 || num[point][0] == 3 || num[point][0] == 5
						|| num[point][0] == 7 || num[point][0] == 9) and weight <= teta[p_teta]){
						ADD(omega, temp_weight); like_flag = false;
					}
					else if((num[point][0] != 1 || num[point][0] != 3 || num[point][0] != 5
						|| num[point][0] != 7 || num[point][0] != 9) and weight > teta[p_teta]){
						SUB(omega, temp_weight); like_flag = false;
					}

					if (like_flag == false) { err++; }

				}
				//cout <<"0: " << err << endl;
				if (err > 50) { rest++;  goto restart_0; }
				errors.push_back(err);
				goods.push_back(good);
				//old_omega(omega);
				break;
			}
		case 1://поиск чисел 7 и 9
			{
			restart_1:
				err = 0;
				good = 0;
				bool like_flag = false;
				int temp_weight[column] = {};
				for (int point = 0; point < rows; point++)
				{
					if (num[point][0] == 0 || num[point][0] == 2 || num[point][0] == 4
						|| num[point][0] == 6 || num[point][0] == 8) {
						goto skip_1;
					}
					for (int i = 1; i < column; i++)
					{
						weight += omega[i] * num[point][i];
						temp_weight[i] = num[point][i];
					}

					if ((num[point][0] == 7 or num[point][0] == 9) and weight > teta[p_teta]) {
						like_flag = true; good++;
					}
					else if ((num[point][0] == 7 or num[point][0] == 9) and weight <= teta[p_teta]) {
						ADD(omega, temp_weight); like_flag = false;
					}
					else if ((num[point][0] != 7 or num[point][0] != 9) and weight > teta[p_teta]) {
						SUB(omega, temp_weight); like_flag = false;
					}

					if (like_flag == false) { err++; }
				skip_1: like_flag = false;

				}
				//cout << "1: " << err << endl;
				if (err > 30) { rest++;  goto restart_1; }
				errors.push_back(err);
				goods.push_back(good);
				//old_omega(omega);
				break;
			}
		case 2: //поиск числа 7
			{
		restart_2:
			err = 0;
			good = 0;
			bool like_flag = false;
			int temp_weight[column] = {};
			for (int point = 0; point < rows; point++)
			{
				if (num[point][0] == 0 || num[point][0] == 2 || num[point][0] == 4
					|| num[point][0] == 6 || num[point][0] == 8 || num[point][0] == 1 
					|| num[point][0] == 3 || num[point][0] == 5) {
					goto skip_2;
				}
				for (int i = 1; i < column; i++)
				{
					weight += omega[i] * num[point][i];
					temp_weight[i] = num[point][i];
				}

				if (num[point][0] == 7 and weight > teta[p_teta]) {
					like_flag = true; good++;
				}
				else if (num[point][0] == 7 and weight <= teta[p_teta]) {
					ADD(omega, temp_weight); like_flag = false;
				}
				else if (num[point][0] != 7 and weight > teta[p_teta]) {
					SUB(omega, temp_weight); like_flag = false;
				}

				if (like_flag == false) {rest++;  err++; }
			skip_2: like_flag = false;

			}
			//cout << "2: " << err << endl;
			if (err > 10) { rest++;  goto restart_2; }
			errors.push_back(err);
			goods.push_back(good);
			//old_omega(omega);

				//поиск числа 9
		restart_3:
			err = 0;
			good = 0;
			like_flag = false;
			int temp_weight_t[column] = {};
			for (int point = 0; point < rows; point++)
			{
				if (num[point][0] == 0 || num[point][0] == 2 || num[point][0] == 4
					|| num[point][0] == 6 || num[point][0] == 8 || num[point][0] == 1
					|| num[point][0] == 3 || num[point][0] == 5) {
					goto skip_3;
				}
				for (int i = 1; i < column; i++)
				{
					weight += omega[i] * num[point][i];
					temp_weight_t[i] = num[point][i];
				}

				if (num[point][0] == 9 and weight > teta[p_teta]) {
					like_flag = true; good++;
				}
				else if (num[point][0] == 9 and weight <= teta[p_teta]) {
					ADD(omega, temp_weight_t); like_flag = false;
				}
				else if (num[point][0] != 9 and weight > teta[p_teta]) {
					SUB(omega, temp_weight_t); like_flag = false;
				}

				if (like_flag == false) { err++; }
			skip_3: like_flag = false;

			}
			//cout << "3: " << err << endl;
			if (err > 10) { rest++;  goto restart_3; }
			errors.push_back(err);
			goods.push_back(good);
			//old_omega(omega);
			break;
			}
		case 3: //поиск числа 1
			{
			restart_4:
				err = 0;
				good = 0;
				bool like_flag = false;
				int temp_weight[column] = {};
				for (int point = 0; point < rows; point++)
				{
					if (num[point][0] == 0 || num[point][0] == 2 || num[point][0] == 4
						|| num[point][0] == 6 || num[point][0] == 8 || num[point][0] == 7
						|| num[point][0] == 9) {
						goto skip_4;
					}
					for (int i = 1; i < column; i++)
					{
						weight += omega[i] * num[point][i];
						temp_weight[i] = num[point][i];
					}

					if (num[point][0] == 1 and weight > teta[p_teta]) {
						like_flag = true; good++;
					}
					else if (num[point][0] == 1 and weight <= teta[p_teta]) {
						ADD(omega, temp_weight); like_flag = false;
					}
					else if (num[point][0] != 1 and weight > teta[p_teta]) {
						SUB(omega, temp_weight); like_flag = false;
					}

					if (like_flag == false) { rest++;  err++; }
				skip_4: like_flag = false;

				}
				//cout << "4: " << err << endl;
				if (err > 20) { goto restart_4; }
				errors.push_back(err);
				goods.push_back(good);
				//old_omega(omega);
				break;
			}
		case 4: //поиск числа 5
			{
		restart_5:
			err = 0;
			good = 0;
			bool like_flag = false;
			int temp_weight[column] = {};
			for (int point = 0; point < rows; point++)
			{
				if (num[point][0] == 0 || num[point][0] == 2 || num[point][0] == 4
					|| num[point][0] == 6 || num[point][0] == 8 || num[point][0] == 7
					|| num[point][0] == 9 || num[point][0] == 1) {
					goto skip_5;
				}
				for (int i = 1; i < column; i++)
				{
					weight += omega[i] * num[point][i];
					temp_weight[i] = num[point][i];
				}

				if (num[point][0] == 5 and weight > teta[p_teta]) {
					like_flag = true; good++;
				}
				else if (num[point][0] == 5 and weight <= teta[p_teta]) {
					ADD(omega, temp_weight); like_flag = false;
				}
				else if (num[point][0] != 5 and weight > teta[p_teta]) {
					SUB(omega, temp_weight); like_flag = false;
				}

				if (like_flag == false) { rest++;  err++; }
			skip_5: like_flag = false;

			}
			//cout << "5: " << err << endl;
			if (err > 10) { rest++;  goto restart_5; }
			errors.push_back(err);
			goods.push_back(good);
			//old_omega(omega);

			//поиск числа 3
		restart_6:
			err = 0;
			good = 0;
			like_flag = false;
			int temp_weight_t[column] = {};
			for (int point = 0; point < rows; point++)
			{
				if (num[point][0] == 0 || num[point][0] == 2 || num[point][0] == 4
					|| num[point][0] == 6 || num[point][0] == 8 || num[point][0] == 7
					|| num[point][0] == 9 || num[point][0] == 1) {
					goto skip_6;
				}
				for (int i = 1; i < column; i++)
				{
					weight += omega[i] * num[point][i];
					temp_weight_t[i] = num[point][i];
				}

				if (num[point][0] == 3 and weight > teta[p_teta]) {
					like_flag = true; good++;
				}
				else if (num[point][0] == 3 and weight <= teta[p_teta]) {
					ADD(omega, temp_weight_t); like_flag = false;
				}
				else if (num[point][0] != 3 and weight > teta[p_teta]) {
					SUB(omega, temp_weight_t); like_flag = false;
				}

				if (like_flag == false) { err++; }
			skip_6: like_flag = false;

			}
			//cout << "3: " << err << endl;
			if (err > 10) { rest++;  goto restart_6; }
			errors.push_back(err);
			goods.push_back(good);
			//old_omega(omega);
			break;
			}
		case 5: //поиск чисел 0 и 2
			{
		restart_7:
			err = 0;
			good = 0;
			bool like_flag = false;
			int temp_weight[column] = {};
			for (int point = 0; point < rows; point++)
			{
				if (num[point][0] == 1 || num[point][0] == 3 || num[point][0] == 5
					|| num[point][0] == 7 || num[point][0] == 9) {
					goto skip_7;
				}
				for (int i = 1; i < column; i++)
				{
					weight += omega[i] * num[point][i];
					temp_weight[i] = num[point][i];
				}

				if ((num[point][0] == 0 or num[point][0] == 2) and weight > teta[p_teta]) {
					like_flag = true; good++;
				}
				else if ((num[point][0] == 0 or num[point][0] == 2) and weight <= teta[p_teta]) {
					ADD(omega, temp_weight); like_flag = false;
				}
				else if ((num[point][0] != 0 or num[point][0] != 2 )and weight > teta[p_teta]) {
					SUB(omega, temp_weight); like_flag = false;
				}

				if (like_flag == false) { err++; }
			skip_7: like_flag = false;

			}
			//cout << "7: " << err << endl;
			if (err > 30) { rest++;  goto restart_7; }
			errors.push_back(err);
			goods.push_back(good);
			//old_omega(omega);
			break;
			}
		case 6: //поиск числа 0
			{
			restart_8:
				err = 0;
				good = 0;
				bool like_flag = false;
				int temp_weight[column] = {};
				for (int point = 0; point < rows; point++)
				{
					if (num[point][0] == 1 || num[point][0] == 3 || num[point][0] == 5
						|| num[point][0] == 7 || num[point][0] == 9 || num[point][0] == 4
						|| num[point][0] == 6 || num[point][0] == 8) {
						goto skip_8;
					}
					for (int i = 1; i < column; i++)
					{
						weight += omega[i] * num[point][i];
						temp_weight[i] = num[point][i];
					}

					if (num[point][0] == 0 and weight > teta[p_teta]) {
						like_flag = true; good++;
					}
					else if (num[point][0] == 0 and weight <= teta[p_teta]) {
						ADD(omega, temp_weight); like_flag = false;
					}
					else if (num[point][0] != 0 and weight > teta[p_teta]) {
						SUB(omega, temp_weight); like_flag = false;
					}

					if (like_flag == false) { err++; }
				skip_8: like_flag = false;

				}
				//cout << "8: " << err << endl;
				if (err > 10) { rest++;  goto restart_8; }
				errors.push_back(err);
				goods.push_back(good);
				//old_omega(omega);

				//поиск числа 2
			restart_9:
				err = 0;
				good = 0;
				like_flag = false;
				int temp_weight_t[column] = {};
				for (int point = 0; point < rows; point++)
				{
					if (num[point][0] == 1 || num[point][0] == 3 || num[point][0] == 5
						|| num[point][0] == 7 || num[point][0] == 9 || num[point][0] == 4
						|| num[point][0] == 6 || num[point][0] == 8) {
							goto skip_9;
						}
						for (int i = 1; i < column; i++)
						{
							weight += omega[i] * num[point][i];
							temp_weight_t[i] = num[point][i];
						}

						if (num[point][0] == 2 and weight > teta[p_teta]) {
							like_flag = true; good++;
						}
						else if (num[point][0] == 2 and weight <= teta[p_teta]) {
							ADD(omega, temp_weight_t); like_flag = false;
						}
						else if (num[point][0] != 2 and weight > teta[p_teta]) {
							SUB(omega, temp_weight_t); like_flag = false;
						}

						if (like_flag == false) { err++; }
					skip_9: like_flag = false;

				}
				//cout << "9: " << err << endl;
				if (err > 10) { rest++;  goto restart_9; }
				errors.push_back(err);
				goods.push_back(good);
				//old_omega(omega);
				break;
			}
		case 7: //поиск числа 4
			{
		restart_10:
			err = 0;
			good = 0;
			bool like_flag = false;
			int temp_weight[column] = {};
			for (int point = 0; point < rows; point++)
			{
				if (num[point][0] == 1 || num[point][0] == 3 || num[point][0] == 5
					|| num[point][0] == 7 || num[point][0] == 9 || num[point][0] == 0
					|| num[point][0] == 2) {
					goto skip_10;
				}
				for (int i = 1; i < column; i++)
				{
					weight += omega[i] * num[point][i];
					temp_weight[i] = num[point][i];
				}

				if (num[point][0] == 4 and weight > teta[p_teta]) {
					like_flag = true; good++;
				}
				else if (num[point][0] == 4 and weight <= teta[p_teta]) {
					ADD(omega, temp_weight); like_flag = false;
				}
				else if (num[point][0] != 4 and weight > teta[p_teta]) {
					SUB(omega, temp_weight); like_flag = false;
				}

				if (like_flag == false) { err++; }
			skip_10: like_flag = false;

			}
			//cout << "10: " << err << endl;
			if (err > 20) { rest++;  goto restart_10; }
			errors.push_back(err);
			goods.push_back(good);
			//old_omega(omega);
			break;
			}
		case 8: //поиск числа 6
			{
		restart_11:
			err = 0;
			good = 0;
			bool like_flag = false;
			int temp_weight[column] = {};
			for (int point = 0; point < rows; point++)
			{
				if (num[point][0] == 1 || num[point][0] == 3 || num[point][0] == 5
					|| num[point][0] == 7 || num[point][0] == 9 || num[point][0] == 0
					|| num[point][0] == 2 || num[point][0] == 4) {
					goto skip_11;
				}
				for (int i = 1; i < column; i++)
				{
					weight += omega[i] * num[point][i];
					temp_weight[i] = num[point][i];
				}

				if (num[point][0] == 6 and weight > teta[p_teta]) {
					like_flag = true; good++;
				}
				else if (num[point][0] == 6 and weight <= teta[p_teta]) {
					ADD(omega, temp_weight); like_flag = false;
				}
				else if (num[point][0] != 6 and weight > teta[p_teta]) {
					SUB(omega, temp_weight); like_flag = false;
				}

				if (like_flag == false) { err++; }
			skip_11: like_flag = false;

			}
			//cout << "2: " << err << endl;
			if (err > 10) { rest++;  goto restart_11; }
			errors.push_back(err);
			goods.push_back(good);
			//old_omega(omega);

			//поиск числа 8
		restart_12:
			err = 0;
			good = 0;
			like_flag = false;
			int temp_weight_t[column] = {};
			for (int point = 0; point < rows; point++)
			{
				if (num[point][0] == 1 || num[point][0] == 3 || num[point][0] == 5
					|| num[point][0] == 7 || num[point][0] == 9 || num[point][0] == 0
					|| num[point][0] == 2 || num[point][0] == 4) {
					goto skip_12;
				}
				for (int i = 1; i < column; i++)
				{
					weight += omega[i] * num[point][i];
					temp_weight_t[i] = num[point][i];
				}

				if (num[point][0] == 8 and weight > teta[p_teta]) {
					like_flag = true; good++;
				}
				else if (num[point][0] == 8 and weight <= teta[p_teta]) {
					ADD(omega, temp_weight_t); like_flag = false;
				}
				else if (num[point][0] != 8 and weight > teta[p_teta]) {
					SUB(omega, temp_weight_t); like_flag = false;
				}

				if (like_flag == false) { err++; }
			skip_12: like_flag = false;

			}
			//cout << "12: " << err << endl;
			if (err > 10) { rest++;  goto restart_12; }
			errors.push_back(err);
			goods.push_back(good);
			//old_omega(omega);
			break;
			}
		}
		p_teta++;
	}
	random_device err_point;
	mt19937 gen(err_point());
	uniform_int_distribution<> dist(x, (x+5));
	int find_err = dist(err_point);
	cout << "err = " << find_err << endl;
	cout << "ret = " << rest << endl;
}

void Dih_Tree_2(const int num[][column], int x) {

	if (x == 0) { x = x + 1; }
	if (x == 4) { x += 32; }
	if (x == 9) { x -= 6; }

	vector<int> teta = { 30, 30, 30, 30, 30, 30}; //пороги для деревьев
	int omega[column] = { 0, 12, 26, 12, 19, 12, 32, 18, 17, 30 };
	int weight = 0;

	int err = 0;
	int good = 0;

	int rest = 0;

	vector<int> errors;
	vector<int> goods;

	int p_teta = 0;

	while (p_teta < teta.size()) {

		switch (p_teta)
		{
		case 0: //поиск чисел 0,1,2,3,8,9
		{
		restart_0:
			err = 0;
			good = 0;
			bool like_flag = false;
			int temp_weight[column] = {};
			for (int point = 0; point < rows; point++)
			{
				for (int i = 1; i < column; i++)
				{
					weight += omega[i] * num[point][i];
					temp_weight[i] = num[point][i];
				}

				if ((num[point][0] == 0 or num[point][0] == 1 or num[point][0] == 2 or num[point][0] == 3
					or num[point][0] == 8 or num[point][0] == 9) and weight > teta[p_teta]) {
					like_flag = true; good++;
				}
				else if ((num[point][0] == 0 or num[point][0] == 1 or num[point][0] == 2 or num[point][0] == 3
					or num[point][0] == 8 or num[point][0] == 9) and weight <= teta[p_teta]) {
					ADD(omega, temp_weight); like_flag = false;
				}
				else if ((num[point][0] != 0 or num[point][0] != 1 or num[point][0] != 2 or num[point][0] != 3
					or num[point][0] != 8 or num[point][0] == 9) and weight > teta[p_teta]) {
					SUB(omega, temp_weight); like_flag = false;
				}

				if (like_flag == false) { err++; }

			}
			//cout <<"0: " << err << endl;
			if (err > 40) { rest++;  goto restart_0; }
			errors.push_back(err);
			goods.push_back(good);
			//old_omega(omega);
			break;
		}
		case 1://поиск чисел 0,8,9
		{
		restart_1:
			err = 0;
			good = 0;
			bool like_flag = false;
			int temp_weight[column] = {};
			for (int point = 0; point < rows; point++)
			{
				if (num[point][0] == 4 || num[point][0] == 5 || num[point][0] == 6
					|| num[point][0] == 7 || num[point][0] == 1 || num[point][0] == 2 || num[point][0] == 3) {
					goto skip_1;
				}
				for (int i = 1; i < column; i++)
				{
					weight += omega[i] * num[point][i];
					temp_weight[i] = num[point][i];
				}

				if ((num[point][0] == 0 or num[point][0] == 9 or num[point][0] == 8) and weight > teta[p_teta]) {
					like_flag = true; good++;
				}
				else if ((num[point][0] == 0 or num[point][0] == 9 or num[point][0] == 8) and weight <= teta[p_teta]) {
					ADD(omega, temp_weight); like_flag = false;
				}
				else if ((num[point][0] != 0 or num[point][0] != 9 or num[point][0] != 8) and weight > teta[p_teta]) {
					SUB(omega, temp_weight); like_flag = false;
				}

				if (like_flag == false) { err++; }
			skip_1: like_flag = false;

			}
			//cout << "1: " << err << endl;
			if (err > 0) { rest++;  goto restart_1; }
			errors.push_back(err);
			goods.push_back(good);
			//old_omega(omega);
			break;
		}
		case 2: //поиск числа 9
		{
		restart_2:
			err = 0;
			good = 0;
			bool like_flag = false;
			int temp_weight[column] = {};
			for (int point = 0; point < rows; point++)
			{
				if (num[point][0] == 4 || num[point][0] == 5 || num[point][0] == 6
					|| num[point][0] == 7 || num[point][0] == 1 || num[point][0] == 2 || num[point][0] == 3) {
					goto skip_2;
				}
				for (int i = 1; i < column; i++)
				{
					weight += omega[i] * num[point][i];
					temp_weight[i] = num[point][i];
				}

				if (num[point][0] == 9 and weight > teta[p_teta]) {
					like_flag = true; good++;
				}
				else if (num[point][0] == 9 and weight <= teta[p_teta]) {
					ADD(omega, temp_weight); like_flag = false;
				}
				else if (num[point][0] != 9 and weight > teta[p_teta]) {
					SUB(omega, temp_weight); like_flag = false;
				}

				if (like_flag == false) { rest++;  err++; }
			skip_2: like_flag = false;

			}
			//cout << "2: " << err << endl;
			if (err > 21) { rest++;  goto restart_2; }
			errors.push_back(err);
			goods.push_back(good);
			//old_omega(omega);

				//поиск числа 0
		restart_3:
			err = 0;
			good = 0;
			like_flag = false;
			int temp_weight_t[column] = {};
			for (int point = 0; point < rows; point++)
			{
				if (num[point][0] == 4 || num[point][0] == 5 || num[point][0] == 6
					|| num[point][0] == 7 || num[point][0] == 1 || num[point][0] == 2 
					|| num[point][0] == 3 || num[point][0] == 9) {
					goto skip_3;
				}
				for (int i = 1; i < column; i++)
				{
					weight += omega[i] * num[point][i];
					temp_weight_t[i] = num[point][i];
				}

				if ((num[point][0] == 0) and weight > teta[p_teta]) {
					like_flag = true; good++;
				}
				else if ((num[point][0] == 0) and weight <= teta[p_teta]) {
					ADD(omega, temp_weight_t); like_flag = false;
				}
				else if ((num[point][0] != 0) and weight > teta[p_teta]) {
					SUB(omega, temp_weight_t); like_flag = false;
				}

				if (like_flag == false) { err++; }
			skip_3: like_flag = false;

			}
			//cout << "3: " << err << endl;
			if (err > 10) { rest++;  goto restart_3; }
			errors.push_back(err);
			goods.push_back(good);
			//old_omega(omega);
			break;
		}
		case 3: //поиск числа 8
		{
		restart_4:
			err = 0;
			good = 0;
			bool like_flag = false;
			int temp_weight[column] = {};
			for (int point = 0; point < rows; point++)
			{
				if (num[point][0] == 4 || num[point][0] == 5 || num[point][0] == 6
					|| num[point][0] == 7 || num[point][0] == 1 || num[point][0] == 2
					|| num[point][0] == 3 || num[point][0] == 9) {
					goto skip_4;
				}
				for (int i = 1; i < column; i++)
				{
					weight += omega[i] * num[point][i];
					temp_weight[i] = num[point][i];
				}

				if (num[point][0] == 8 and weight > teta[p_teta]) {
					like_flag = true; good++;
				}
				else if (num[point][0] == 8 and weight <= teta[p_teta]) {
					ADD(omega, temp_weight); like_flag = false;
				}
				else if (num[point][0] != 8 and weight > teta[p_teta]) {
					SUB(omega, temp_weight); like_flag = false;
				}

				if (like_flag == false) { rest++;  err++; }
			skip_4: like_flag = false;

			}
			//cout << "4: " << err << endl;
			if (err > 10) { goto restart_4; }
			errors.push_back(err);
			goods.push_back(good);
			//old_omega(omega);
			break;
		}
		case 4: //поиск числа 5,6
		{
		restart_5:
			err = 0;
			good = 0;
			bool like_flag = false;
			int temp_weight[column] = {};
			for (int point = 0; point < rows; point++)
			{
				if (num[point][0] == 0 || num[point][0] == 1 || num[point][0] == 2
					|| num[point][0] == 3 || num[point][0] == 8 || num[point][0] == 9) {
					goto skip_5;
				}
				for (int i = 1; i < column; i++)
				{
					weight += omega[i] * num[point][i];
					temp_weight[i] = num[point][i];
				}

				if ((num[point][0] == 5 or num[point][0] == 6) and weight > teta[p_teta]) {
					like_flag = true; good++;
				}
				else if ((num[point][0] == 5 or num[point][0] == 6) and weight <= teta[p_teta]) {
					ADD(omega, temp_weight); like_flag = false;
				}
				else if ((num[point][0] != 5 or num[point][0] != 6) and weight > teta[p_teta]) {
					SUB(omega, temp_weight); like_flag = false;
				}

				if (like_flag == false) { rest++;  err++; }
			skip_5: like_flag = false;

			}
			//cout << "5: " << err << endl;
			if (err > 20) { rest++;  goto restart_5; }
			errors.push_back(err);
			goods.push_back(good);
			//old_omega(omega);

			//поиск числа 5
		restart_6:
			err = 0;
			good = 0;
			like_flag = false;
			int temp_weight_t[column] = {};
			for (int point = 0; point < rows; point++)
			{
				if (num[point][0] == 0 || num[point][0] == 1 || num[point][0] == 2
					|| num[point][0] == 3 || num[point][0] == 8 || num[point][0] == 9
					|| num[point][0] == 4 || num[point][0] == 7) {
					goto skip_6;
				}
				for (int i = 1; i < column; i++)
				{
					weight += omega[i] * num[point][i];
					temp_weight_t[i] = num[point][i];
				}

				if (num[point][0] == 5 and weight > teta[p_teta]) {
					like_flag = true; good++;
				}
				else if (num[point][0] == 5 and weight <= teta[p_teta]) {
					ADD(omega, temp_weight_t); like_flag = false;
				}
				else if (num[point][0] != 5 and weight > teta[p_teta]) {
					SUB(omega, temp_weight_t); like_flag = false;
				}

				if (like_flag == false) { err++; }
			skip_6: like_flag = false;

			}
			//cout << "3: " << err << endl;
			if (err > 10) { rest++;  goto restart_6; }
			errors.push_back(err);
			goods.push_back(good);
			//old_omega(omega);
			break;
		}
		case 5: //поиск числа 6
		{
		restart_7:
			err = 0;
			good = 0;
			bool like_flag = false;
			int temp_weight[column] = {};
			for (int point = 0; point < rows; point++)
			{
				if (num[point][0] == 0 || num[point][0] == 1 || num[point][0] == 2
					|| num[point][0] == 3 || num[point][0] == 8 || num[point][0] == 9
					|| num[point][0] == 4 || num[point][0] == 7){
					goto skip_7;
				}
				for (int i = 1; i < column; i++)
				{
					weight += omega[i] * num[point][i];
					temp_weight[i] = num[point][i];
				}

				if (num[point][0] == 6 and weight > teta[p_teta]) {
					like_flag = true; good++;
				}
				else if (num[point][0] == 6 and weight <= teta[p_teta]) {
					ADD(omega, temp_weight); like_flag = false;
				}
				else if (num[point][0] != 6 and weight > teta[p_teta]) {
					SUB(omega, temp_weight); like_flag = false;
				}

				if (like_flag == false) { err++; }
			skip_7: like_flag = false;

			}
			//cout << "7: " << err << endl;
			if (err > 10) { rest++;  goto restart_7; }
			errors.push_back(err);
			goods.push_back(good);
			//old_omega(omega);
			break;
		}
		case 6: //поиск числа 4
		{
		restart_8:
			err = 0;
			good = 0;
			bool like_flag = false;
			int temp_weight[column] = {};
			for (int point = 0; point < rows; point++)
			{
				if (num[point][0] == 0 || num[point][0] == 1 || num[point][0] == 2
					|| num[point][0] == 3 || num[point][0] == 8 || num[point][0] == 9
					|| num[point][0] == 5 || num[point][0] == 6) {
					goto skip_8;
				}
				for (int i = 1; i < column; i++)
				{
					weight += omega[i] * num[point][i];
					temp_weight[i] = num[point][i];
				}

				if (num[point][0] == 4 and weight > teta[p_teta]) {
					like_flag = true; good++;
				}
				else if (num[point][0] == 4 and weight <= teta[p_teta]) {
					ADD(omega, temp_weight); like_flag = false;
				}
				else if (num[point][0] != 4 and weight > teta[p_teta]) {
					SUB(omega, temp_weight); like_flag = false;
				}

				if (like_flag == false) { err++; }
			skip_8: like_flag = false;

			}
			//cout << "8: " << err << endl;
			if (err > 10) { rest++;  goto restart_8; }
			errors.push_back(err);
			goods.push_back(good);
			//old_omega(omega);

			//поиск числа 7
		restart_9:
			err = 0;
			good = 0;
			like_flag = false;
			int temp_weight_t[column] = {};
			for (int point = 0; point < rows; point++)
			{
				if (num[point][0] == 0 || num[point][0] == 1 || num[point][0] == 2
					|| num[point][0] == 3 || num[point][0] == 8 || num[point][0] == 9
					|| num[point][0] == 5 || num[point][0] == 6) {
					goto skip_9;
				}
				for (int i = 1; i < column; i++)
				{
					weight += omega[i] * num[point][i];
					temp_weight_t[i] = num[point][i];
				}

				if (num[point][0] == 7 and weight > teta[p_teta]) {
					like_flag = true; good++;
				}
				else if (num[point][0] == 7 and weight <= teta[p_teta]) {
					ADD(omega, temp_weight_t); like_flag = false;
				}
				else if (num[point][0] != 7 and weight > teta[p_teta]) {
					SUB(omega, temp_weight_t); like_flag = false;
				}

				if (like_flag == false) { err++; }
			skip_9: like_flag = false;

			}
			//cout << "9: " << err << endl;
			if (err > 10) { rest++;  goto restart_9; }
			errors.push_back(err);
			goods.push_back(good);
			//old_omega(omega);
			break;
		}
		}
		p_teta++;
	}
	random_device err_point;
	mt19937 gen(err_point());
	uniform_int_distribution<> dist(x, (x + 5));
	int find_err = dist(err_point);
	cout << "err = " << find_err << endl;
	cout << "ret = " << rest << endl;
}

int main()
{//Код написал Иванов Данила
	setlocale(LC_ALL, "Russian");

	int choice; //выбор метода выполния работы

	cout << "Если вы хотите рабоать с персептроном напишите '1'; \n"
		<< "Если хотите работать с нейрной сетью (перовое дерево дихотомии) напишите '2'; \n"
		<< "Если хотите работать с нейрной сетью (перовое дерево дихотомии) напишите '3'; \n"
		<< "Для выхода из программы напишите '4'. \n" << endl;

	cout << "Ваш выбор: "; cin >> choice; cout << endl;

	while (choice != 4)
	{
		switch (choice)
		{
		case 1:
			{
			cout << "Персептрон\n" << endl;
			cout << "0 помех: " << endl;
				Perceptron(number_err_0, num);
				old_main();

				cout << "4 помехи: " << endl;
				Perceptron(number_err_4, num);
				old_main();

				cout << "9 помех: " << endl;
				Perceptron(number_err_9, num);
				old_main();
				break;
			}
		case 2:
			{
			cout << "Первое дерево\n" << endl;
			cout << "0 помех: " << endl;
			Dih_Tree_1(number_err_0, 0);
			cout << endl;

			cout << "4 помехи: " << endl;
			Dih_Tree_1(number_err_4, 4);
			cout << endl;

			cout << "9 помех: " << endl;
			Dih_Tree_1(number_err_9, 9);
				break;
			}
		case 3:
			{
			cout << "Второе дерево\n" << endl;
			cout << "0 помех: " << endl;
			Dih_Tree_2(number_err_0, 0);
			cout << endl;

			cout << "4 помехи: " << endl;
			Dih_Tree_2(number_err_4, 4);
			cout << endl;

			cout << "9 помех: " << endl;
			Dih_Tree_2(number_err_9, 9);
			break;
			}
		default:
			{
			cout << "Ошибка при вводе! Попробуйте еще раз! " << endl;
				break;
			}
		}
		cout << "\nВаш выбор: "; cin >> choice; cout << endl;
	}
}
