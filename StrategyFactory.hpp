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
protected:
	int points = 0;
	std::vector<int*> history;
	int read(int frame, int x);
public:
	void write_frame(int x, int y, int z);
	virtual std::string& say_name(void);
	int points_cnt(void);
	virtual int choice(std::string& config_dir);
	void add_points(int cnt);
};

class Triv1 : public Strategy
{
private:
	std::string name = "s1";
public:
	std::string& say_name(void);
	int choice(std::string& config_dir);
};

class Triv2 : public Strategy
{
private:
	std::string name = "s2";
public:
	std::string& say_name(void);
	int choice(std::string& config_dir);
};

class Triv3 : public Strategy
{
private:
	std::string name = "s3";
public:
	std::string& say_name(void);
	int choice(std::string& config_dir);
};

class Strategy4 : public Strategy
{
private:
	std::string name = "s4";
public:
	std::string& say_name(void);
	int choice(std::string& config_dir);
};

//Фабрики стратегий:
class StrategyFactory
{
public:
	virtual std::string& say_name(void);
	virtual Strategy* create() const;
};

class Triv1Factory : public StrategyFactory
{
private:
	std::string name = "s1";
public:
	std::string& say_name(void);
	Strategy* create() const;
};

class Triv2Factory : public StrategyFactory
{
private:
	std::string name = "s2";
public:
	std::string& say_name(void);
	Strategy* create() const;
};

class Triv3Factory : public StrategyFactory
{
private:
	std::string name = "s3";
public:
	std::string& say_name(void);
	Strategy* create() const;
};

class Strategy4Factory : public StrategyFactory
{
private:
	std::string name = "s4";
public:
	std::string& say_name(void);
	Strategy* create() const;
};


#endif /*SF_642*/