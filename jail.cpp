#include "jail.hpp"
#include "StrategyFactory.hpp"
#include "unit_tests.hpp"
#define TEST_72

void read_matrix(matrix*** matrix, std::string filename)
{
	std::ifstream fin(filename);
	std::string buf;
	std::getline(fin, buf);

	// чтение всей остальной матрицы
	int p1, p2, p3;
	for (int i = 0; i < 8; i++)
	{
		std::getline(fin, buf);
		// выбор заключённых
		buf[0] == 'C' ? p1 = 1 : p1 = 0;
		buf[3] == 'C' ? p2 = 1 : p2 = 0;
		buf[6] == 'C' ? p3 = 1 : p3 = 0;

		// баллы заключённым соответственно
		matrix[p1][p2][p3].p1_res = buf[13] - '0';
		matrix[p1][p2][p3].p2_res = buf[16] - '0';
		matrix[p1][p2][p3].p3_res = buf[19] - '0';
	}

	fin.close();
}

void detailed_step(matrix*** matrix, Strategy* S1, Strategy* S2, Strategy* S3, std::string& config_dir)
{
	int i = S1->choice(config_dir);
	int j = S2->choice(config_dir);
	int k = S3->choice(config_dir);
	char is, js, ks;
	i == 0 ? is = 'D' : is = 'C';
	j == 0 ? js = 'D' : js = 'C';
	k == 0 ? ks = 'D' : ks = 'C';

	S1->add_points(matrix[i][j][k].p1_res);
	S2->add_points(matrix[i][j][k].p2_res);
	S3->add_points(matrix[i][j][k].p3_res);
	S1->write_frame(i, j, k);
	S2->write_frame(j, i, k);
	S3->write_frame(k, i, j);

	std::cout << "Choices: p1 - " << is << " p2 - " << js << " p3 - " << ks << std::endl;
	std::cout << "Points for the current step: p1 - " << matrix[i][j][k].p1_res << " p2 - " << matrix[i][j][k].p2_res << " p3 - " << matrix[i][j][k].p3_res << std::endl;
	std::cout << "Total points: p1 - " << S1->points_cnt() << " p2 - " << S2->points_cnt() << " p3 - " << S3->points_cnt() << std::endl;
}

void fast_step(matrix*** matrix, Strategy* S1, Strategy* S2, Strategy* S3, std::string& config_dir)
{
	int i = S1->choice(config_dir);
	int j = S2->choice(config_dir);
	int k = S3->choice(config_dir);
	S1->add_points(matrix[i][j][k].p1_res);
	S2->add_points(matrix[i][j][k].p2_res);
	S3->add_points(matrix[i][j][k].p3_res);
	S1->write_frame(i, j, k);
	S2->write_frame(j, i, k);
	S3->write_frame(k, i, j);
}

int* competition(matrix*** matrix, StrategyFactory* SF1, StrategyFactory* SF2, StrategyFactory* SF3, bool is_detailed, std::string& config_dir, int steps)
{
	Strategy* S1 = SF1->create();
	Strategy* S2 = SF2->create();
	Strategy* S3 = SF3->create();

	std::cout << std::endl << S1->say_name() << " vs " << S2->say_name() << " vs " << S3->say_name() << std::endl;

	for (int i = 0; i != steps; i++)
	{
		std::string command;
		if (is_detailed)
		{
			std::getline(std::cin, command);
			if (command == "quit")
				break;
			detailed_step(matrix, S1, S2, S3, config_dir);
		}
		else
		{
			fast_step(matrix, S1, S2, S3, config_dir);
		}
	}

	std::cout << std::endl << "Results: p1 - " << S1->points_cnt() << " p2 - " << S2->points_cnt() << " p3 - " << S3->points_cnt() << std::endl;

	int* res = new int[3];
	res[0] = S1->points_cnt();
	res[1] = S2->points_cnt();
	res[2] = S3->points_cnt();
	return res;
}

void tournament(matrix*** matrix, std::vector<StrategyFactory*>& s_factories, std::string& config_dir, int steps)
{
	int* res = new int[s_factories.size()];
	for (int i = 0; i < s_factories.size(); i++)
	{
		res[i] = 0;
	}

	for (int i = 0; i < s_factories.size(); i++)
	{
		for (int j = i + 1; j < s_factories.size(); j++)
		{
			for (int k = j + 1; k < s_factories.size(); k++)
			{
				std::cout << std::endl;
				int* step_res = competition(matrix, s_factories[i], s_factories[j], s_factories[k], 0, config_dir, steps);
				res[i] += step_res[0];
				res[j] += step_res[1];
				res[k] += step_res[2];
			}
		}
	}
	std::cout << std::endl << "Final res: ";
	for (int i = 0; i < s_factories.size(); i++)
	{
		std::cout << s_factories[i]->say_name() << " - " << res[i] << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[])
{

#ifdef TEST_72
	testing::InitGoogleTest();
	RUN_ALL_TESTS();
#endif

	srand(time(0));

	// матрица баллов
	matrix*** matrix = new struct matrix** [2];
	for (int i = 0; i < 2; i++)
	{
		matrix[i] = new struct matrix* [2];
		for (int j = 0; j < 2; j++)
		{
			matrix[i][j] = new struct matrix[2];
		}
	}

	// работа с аргументами коммандной строки
	// jail.exe -mode=detailed --matrix=example_matrix.txt --configs=configs
	// jail.exe -mode=fast --steps=10
	int mode = -1; // 0 - detailed, 1 - fast, 2 - tournament
	std::string matrix_file_name = "default_matrix.txt";
	int steps = -1;
	std::vector<std::string> strat_names;
	std::string configs_dir_name = "configs";

	//парсер
	for (int i = 1; i < argc; i++)
	{
		std::string str = std::string(argv[i]);
		std::string command;
		command = str.substr(0, 6);
		if (command == "-mode=")
		{
			command = str.substr(6, std::string::npos);
			if (command == "detailed")
			{
				mode = 0;
			}
			else if (command == "fast")
			{
				mode = 1;
			}
			else if (command == "tournament")
			{
				mode = 2;
			}
			continue;
		}
		command = str.substr(0, 8);
		if (command == "--steps=")
		{
			steps = stoi(str.substr(8, std::string::npos));
			continue;
		}
		command = str.substr(0, 9);
		if (command == "--matrix=")
		{
			matrix_file_name = str.substr(9, std::string::npos);
			continue;
		}
		command = str.substr(0, 10);
		if (command == "--configs=")
		{
			configs_dir_name = str.substr(11, std::string::npos);
			continue;
		}
		strat_names.insert(strat_names.end(), 1, command);
	}
	if (strat_names.size() > 3 && mode == -1)
	{
		mode = 2;
	}
	else if (mode == -1)
	{
		mode = 0;
	}
	std::string& config_dir = configs_dir_name;

	read_matrix(matrix, matrix_file_name);

	std::vector<StrategyFactory*> s_factories;
	for (int i = 0; i < strat_names.size(); i++)
	{
		if (strat_names[i] == "s1")
			s_factories.push_back(new Triv1Factory);
		else if (strat_names[i] == "s2")
			s_factories.push_back(new Triv2Factory);
		else if (strat_names[i] == "s3")
			s_factories.push_back(new Triv3Factory);
		else if (strat_names[i] == "s4")
			s_factories.push_back(new Strategy4Factory);
		else if (strat_names[i] == "s5")
			s_factories.push_back(new Strategy5Factory);
		else if (strat_names[i] == "s6")
			s_factories.push_back(new Strategy6Factory);
	}
	std::vector<StrategyFactory*>& ss_factories = s_factories;

	switch (mode)
	{
	default:
		if (strat_names.size() != 3)
		{
			std::cout << "Can't play detailed mode with number of strategies different from 3!" << std::endl;
			break;
		}
		competition(matrix, s_factories[0], s_factories[1], s_factories[2], 1, config_dir, steps);
		break;

	case 1:
		if (strat_names.size() != 3)
		{
			std::cout << "Can't play fast mode with number of strategies different from 3!" << std::endl;
			break;
		}
		if (steps == -1)
		{
			std::cout << "Can't play fast competition without steps amount!" << std::endl;
			break;
		}
		competition(matrix, s_factories[0], s_factories[1], s_factories[2], 0, config_dir,  steps);
		break;

	case 2:
		if (strat_names.size() < 3)
		{
			std::cout << "Can't play tournament mode with number of strategies less than 3!" << std::endl;
		}
		if (steps == -1)
		{
			std::cout << "Can't play tournament without steps amount!" << std::endl;
			break;
		}
		tournament(matrix, ss_factories, config_dir ,steps);
		break;
	}

	return 0;
}
