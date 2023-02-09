//#include "jail.hpp"
#include "StrategyFactory.hpp"
#include "unit_tests.hpp"
#include "jail.hpp"

std::string cd = "configs";
std::string& config_dir = cd;

//тесты
TEST(comp, s1_v_s1_v_s1)
{
	StrategyFactory* SF1 = new Triv1Factory;
	StrategyFactory* SF2 = new Triv1Factory;
	StrategyFactory* SF3 = new Triv1Factory;
	matrix*** matrix = new struct matrix** [2];
	for (int i = 0; i < 2; i++)
	{
		matrix[i] = new struct matrix* [2];
		for (int j = 0; j < 2; j++)
		{
			matrix[i][j] = new struct matrix[2];
		}
	}
	read_matrix(matrix);
	int* res = new int[3];
	res = competition(matrix, SF1, SF2, SF3, 0, cd, 10);
	EXPECT_EQ(res[0], 70);
	EXPECT_EQ(res[1], 70);
	EXPECT_EQ(res[2], 70);
}

TEST(comp, s2_v_s2_v_s2)
{
	StrategyFactory* SF1 = new Triv2Factory;
	StrategyFactory* SF2 = new Triv2Factory;
	StrategyFactory* SF3 = new Triv2Factory;
	matrix*** matrix = new struct matrix** [2];
	for (int i = 0; i < 2; i++)
	{
		matrix[i] = new struct matrix* [2];
		for (int j = 0; j < 2; j++)
		{
			matrix[i][j] = new struct matrix[2];
		}
	}
	read_matrix(matrix);
	int* res = new int[3];
	res = competition(matrix, SF1, SF2, SF3, 0, config_dir, 10);
	EXPECT_EQ(res[0], 10);
	EXPECT_EQ(res[1], 10);
	EXPECT_EQ(res[2], 10);
}

TEST(comp, s2_v_s1_v_s1)
{
	StrategyFactory* SF1 = new Triv2Factory;
	StrategyFactory* SF2 = new Triv1Factory;
	StrategyFactory* SF3 = new Triv1Factory;
	matrix*** matrix = new struct matrix** [2];
	for (int i = 0; i < 2; i++)
	{
		matrix[i] = new struct matrix* [2];
		for (int j = 0; j < 2; j++)
		{
			matrix[i][j] = new struct matrix[2];
		}
	}
	read_matrix(matrix);
	int* res = new int[3];
	res = competition(matrix, SF1, SF2, SF3, 0, config_dir, 10);
	EXPECT_EQ(res[0], 90);
	EXPECT_EQ(res[1], 30);
	EXPECT_EQ(res[2], 30);
}

TEST(comp, s4_v_s2_v_s2)
{
	StrategyFactory* SF1 = new Strategy4Factory;
	StrategyFactory* SF2 = new Triv2Factory;
	StrategyFactory* SF3 = new Triv2Factory;
	matrix*** matrix = new struct matrix** [2];
	for (int i = 0; i < 2; i++)
	{
		matrix[i] = new struct matrix* [2];
		for (int j = 0; j < 2; j++)
		{
			matrix[i][j] = new struct matrix[2];
		}
	}
	read_matrix(matrix);
	int* res = new int[3];
	res = competition(matrix, SF1, SF2, SF3, 0, config_dir, 10);
	EXPECT_EQ(res[0], 10);
	EXPECT_EQ(res[1], 10);
	EXPECT_EQ(res[2], 10);
}

TEST(comp, s4_v_s2_v_s1)
{
	StrategyFactory* SF1 = new Strategy4Factory;
	StrategyFactory* SF2 = new Triv2Factory;
	StrategyFactory* SF3 = new Triv1Factory;
	matrix*** matrix = new struct matrix** [2];
	for (int i = 0; i < 2; i++)
	{
		matrix[i] = new struct matrix* [2];
		for (int j = 0; j < 2; j++)
		{
			matrix[i][j] = new struct matrix[2];
		}
	}
	read_matrix(matrix);
	int* res = new int[3];
	res = competition(matrix, SF1, SF2, SF3, 0, config_dir, 10);
	EXPECT_EQ(res[0], 50);
	EXPECT_EQ(res[1], 50);
	EXPECT_EQ(res[2], 0);
}

TEST(comp, s4_v_s1_v_s1)
{
	StrategyFactory* SF1 = new Strategy4Factory;
	StrategyFactory* SF2 = new Triv1Factory;
	StrategyFactory* SF3 = new Triv1Factory;
	matrix*** matrix = new struct matrix** [2];
	for (int i = 0; i < 2; i++)
	{
		matrix[i] = new struct matrix* [2];
		for (int j = 0; j < 2; j++)
		{
			matrix[i][j] = new struct matrix[2];
		}
	}
	read_matrix(matrix);
	int* res = new int[3];
	res = competition(matrix, SF1, SF2, SF3, 0, config_dir, 10);
	EXPECT_EQ(res[0], 72);
	EXPECT_EQ(res[1], 66);
	EXPECT_EQ(res[2], 66);
}

TEST(choice, s1)
{
	StrategyFactory* SF1 = new Triv1Factory;
	Strategy* S1 = SF1->create();
	EXPECT_EQ(S1->choice(config_dir), 1);
}

TEST(choice, s2)
{
	StrategyFactory* SF1 = new Triv2Factory;
	Strategy* S1 = SF1->create();
	EXPECT_EQ(S1->choice(config_dir), 0);
}