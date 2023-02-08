#ifndef SF_642
#define SF_642
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>

//Стратегии:
class Strategy
{
private:
	int points = 0;

public:
	virtual std::string& say_name(void);
	int points_cnt(void);
	virtual int choice(void);
	void add_points(int cnt);
};

class Triv1 : public Strategy
{
private:
	std::string name = "s1";
public:
	std::string& say_name(void);
	int choice(void);
};

class Triv2 : public Strategy
{
private:
	std::string name = "s2";
public:
	std::string& say_name(void);
	int choice(void);
};

class Triv3 : public Strategy
{
private:
	std::string name = "s3";
public:
	std::string& say_name(void);
	int choice(void);
};

//Фабрики стратегий:
class StrategyFactory
{
public:
	virtual Strategy* create() const;
};

class Triv1Factory : public StrategyFactory
{
public:
	Strategy* create() const;
};

class Triv2Factory : public StrategyFactory
{
public:
	Strategy* create() const;
};

class Triv3Factory : public StrategyFactory
{
public:
	Strategy* create() const;
};

#endif /*SF_642*/