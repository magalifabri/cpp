#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <string>

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define REVERSED "\033[7m"

class A_Enemy
{
	private:
	int hp;
	std::string type;

	public:
	A_Enemy();
	A_Enemy(int hp, std::string const &type);
	A_Enemy(const A_Enemy &enemy);
	void operator=(const A_Enemy &enemy);
	virtual ~A_Enemy();
	std::string virtual getType() const;
	int getHP() const;
	virtual void takeDamage(int);
};

#endif