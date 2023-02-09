#include "StrategyFactory.hpp"

void Strategy::write_frame(int x, int y, int z)
{
    history.push_back(new int[3]);
    history.back()[0] = x;
    history.back()[1] = y;
    history.back()[2] = z;
}

int Strategy::read(int frame, int x)
{
    return history[frame][x];
}

//Стратегии:
int Strategy::points_cnt(void)
{
    return points;
}

std::string& Strategy::say_name(void)
{
    std::string name = "ja";
    std::string& s_name = name;
    return s_name;
}

void Strategy::add_points(int cnt)
{
    points += cnt;
}

int Strategy::choice(void)
{
    return 1;
}

std::string& Triv1::say_name(void) //сделать через темплейт для всех стратегий
{
    std::string& s_name = name;
    return s_name;
}

std::string& Triv2::say_name(void) //сделать через темплейт для всех стратегий
{
    std::string& s_name = name;
    return s_name;
}

std::string& Triv3::say_name(void) //сделать через темплейт для всех стратегий
{
    std::string& s_name = name;
    return s_name;
}

std::string& Strategy4::say_name(void) //сделать через темплейт для всех стратегий
{
    std::string& s_name = name;
    return s_name;
}

int Triv1::choice(void)
{
    return 1;
}

int Triv2::choice(void)
{
    return 0;
}

int Triv3::choice(void)
{
    return rand() % 2;
}

int Strategy4::choice(void)
{
    int sum = 0;
    int res;

    for (int i = 0; i < history.size(); i++)
    {
        for (int j = 1; j < 3; j++)
        {
            sum += history[i][j];
        }
    }

    sum > history.size() ? res = 1 : res = 0; //выбирает 1 если другие игроки чаще сотрудничали и 0, если чаще предавали
    return res;
}

//Фабрики стратегий:
Strategy *StrategyFactory::create() const
{
    return new Strategy;
}

Strategy *Triv1Factory::create() const //попробовать сделать через шаблон для всех
{
    return new Triv1;
}

Strategy *Triv2Factory::create() const //попробовать сделать через шаблон для всех
{
    return new Triv2;
}

Strategy *Triv3Factory::create() const //попробовать сделать через шаблон для всех
{
    return new Triv3;
}

Strategy* Strategy4Factory::create() const //попробовать сделать через шаблон для всех
{
    return new Strategy4;
}

std::string& Triv1Factory::say_name(void) //сделать через темплейт для всех фабрик
{
    std::string& s_name = name;
    return s_name;
}

std::string& Triv2Factory::say_name(void) //сделать через темплейт для всех фабрик
{
    std::string& s_name = name;
    return s_name;
}

std::string& Triv3Factory::say_name(void) //сделать через темплейт для всех фабрик
{
    std::string& s_name = name;
    return s_name;
}

std::string& Strategy4Factory::say_name(void) //сделать через темплейт для всех фабрик
{
    std::string& s_name = name;
    return s_name;
}

std::string& StrategyFactory::say_name(void)
{
    std::string name = "ja";
    std::string& s_name = name;
    return s_name;
}

//эксперименты
// int main()
// {
//     srand(time(0));
//     Triv3Factory T1F;
//     Strategy *S = T1F.create();
//     for (int j = 0; j < 10; j++)
//     {
//         int i = S->choice();
//         std::cout << i << std::endl;
//     }
//     return 0;
// }