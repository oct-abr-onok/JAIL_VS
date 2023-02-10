//#include "jail.hpp"
#include "StrategyFactory.hpp"
#include "unit_tests.hpp"
#include "jail.hpp"

std::string cd = "configs";
std::string& config_dir = cd;

std::string ccd = "custom_configs";
std::string& c_config_dir = ccd;


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

TEST(comp, s5_v_s1_v_s1)
{
	StrategyFactory* SF1 = new Strategy5Factory;
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
	EXPECT_EQ(res[0], 70);
	EXPECT_EQ(res[1], 70);
	EXPECT_EQ(res[2], 70);
}

TEST(comp, s5_v_s2_v_s2)
{
	StrategyFactory* SF1 = new Strategy5Factory;
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
	EXPECT_EQ(res[0], 9);
	EXPECT_EQ(res[1], 14);
	EXPECT_EQ(res[2], 14);
}

TEST(comp, s6_v_s1_v_s1)
{
	StrategyFactory* SF1 = new Strategy6Factory;
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

TEST(comp, s6_v_s2_v_s2)
{
	StrategyFactory* SF1 = new Strategy6Factory;
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

TEST(custom_config, s4_v_s1_v_s1)
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
	res = competition(matrix, SF1, SF2, SF3, 0, c_config_dir, 10);
	EXPECT_EQ(res[0], 72);
	EXPECT_EQ(res[1], 66);
	EXPECT_EQ(res[2], 66);
}


TEST(custom_config, s4_v_s2_v_s2)
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
	res = competition(matrix, SF1, SF2, SF3, 0, c_config_dir, 10);
	EXPECT_EQ(res[0], 10);
	EXPECT_EQ(res[1], 10);
	EXPECT_EQ(res[2], 10);
}

TEST(custom_config, s5_v_s1_v_s1)
{
	StrategyFactory* SF1 = new Strategy5Factory;
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
	res = competition(matrix, SF1, SF2, SF3, 0, c_config_dir, 10);
	EXPECT_EQ(res[0], 88);
	EXPECT_EQ(res[1], 34);
	EXPECT_EQ(res[2], 34);
}

TEST(custom_config, s5_v_s2_v_s2)
{
	StrategyFactory* SF1 = new Strategy5Factory;
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
	res = competition(matrix, SF1, SF2, SF3, 0, c_config_dir, 10);
	EXPECT_EQ(res[0], 9);
	EXPECT_EQ(res[1], 14);
	EXPECT_EQ(res[2], 14);
}

TEST(custom_config, s6_v_s1_v_s1)
{
	StrategyFactory* SF1 = new Strategy6Factory;
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
	res = competition(matrix, SF1, SF2, SF3, 0, c_config_dir, 10);
	EXPECT_EQ(res[0], 72);
	EXPECT_EQ(res[1], 66);
	EXPECT_EQ(res[2], 66);
}

TEST(custom_config, s6_v_s2_v_s2)
{
	StrategyFactory* SF1 = new Strategy6Factory;
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
	res = competition(matrix, SF1, SF2, SF3, 0, c_config_dir, 10);
	EXPECT_EQ(res[0], 10);
	EXPECT_EQ(res[1], 10);
	EXPECT_EQ(res[2], 10);
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