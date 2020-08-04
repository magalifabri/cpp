#include "Pony.hpp"

void ponyOnTheStack()
{
	std::cout << "entered ponyOnTheStack()\n";
	Pony ponyOnTheStack;
	ponyOnTheStack.name = "stackPony";
	ponyOnTheStack.eat();
	ponyOnTheStack.sleep();
	ponyOnTheStack.shit();
	return ;
}

void ponyOnTheHeap()
{
	std::cout << "entered ponyOnTheHeap()\n";
	Pony *ponyOnTheHeap;
	ponyOnTheHeap = new Pony;
	ponyOnTheHeap->name = "heapPony";
	ponyOnTheHeap->eat();
	ponyOnTheHeap->sleep();
	ponyOnTheHeap->shit();
	delete ponyOnTheHeap;
	return ;
}

int main()
{
	ponyOnTheStack();
	ponyOnTheHeap();
	return 0;
}