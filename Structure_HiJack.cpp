// Structure_HiJack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//	This demonstrates a hijack of data from structures when passed in as a void. Note that even when cast, the data fields still work!
//	Sort of.... 
//	As long as the values are in the same place, then the data comes through.
//
/*
Now in the void: 22
Deeper into the void : X
still in the void : ╠
The bones say : 22, X
╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠H° is my dog
Now in the void: 44
Deeper into the void : Z
still in the void : ╠
The bones say : 44, Z
is my dog
Now in the void : 66
Deeper into the void : ╠
still in the void : Q
The bones say : 66, ╠
Ginger is my dog

C : \Users\JSB\source\repos\Structure_HiJack\Debug\Structure_HiJack.exe(process 6600) exited with code 0.
	Press any key to close this window . . .
*/
//
// Note: this stuff will probably cause a crash or segfault eventually.
//
#include "pch.h"
#include <iostream>
struct dog
{
	char name[10];
	char breed[10];
	int age;
	char color[10];
	int xy[2];
	struct tail { int taily; } thetailofthedog;
};
struct template__bargraph {
	unsigned int loc__Ys[13];
	unsigned int spacing_Ys[13];
};
struct detectors__FIRE {
	unsigned short priority;
	char stat;
};
struct probes__O2 {
	unsigned short priority;
	char stat;
	struct dog doggy;
};
struct another_struct {
	unsigned short priority;
	struct dog doggy;
	char stat;
};
struct skeleton {
	unsigned short priority;
	char stat;
};
unsigned short hijack(void* thevoid) {
	if (thevoid) {
		printf("Now in the void: %i\n", *(unsigned short*)thevoid);	// no cast
		struct detectors__FIRE it1 = *(detectors__FIRE*)thevoid;	// cast to structire
		struct another_struct it2 = *(another_struct*)thevoid;		// cast to structure
		printf("Deeper into the void: %c\n", it1.stat);
		printf("still in the void: %c\n", it2.stat);
		struct skeleton skelly = *(skeleton*)thevoid;		// cast to structure
		printf("The bones say: %i, %c\n", skelly.priority, skelly.stat);
		struct dog wheresmydoggy = it2.doggy;	// we can pull this structire out of the properly cast structure
		printf("%s is my dog\n", wheresmydoggy.name);
		int iii = -3; //deb100
	}	// if
	return 0;
}
int main()
{
	struct dog *ptr_dog;
	struct detectors__FIRE *ptr_fd;
	struct probes__O2 *ptr_o2;
	struct another_struct *ptr_as;
	unsigned short(*fun_ptr)(void*);
	{ // Here the struct instance is created, but the pointer to it is also assigned, then tne instance is gone out of scope, but still persists
		struct detectors__FIRE fd = { 22, 'X' };
		struct probes__O2 o2 = { 44, 'Z' };
		struct another_struct as = { 66, { "Ginger", "Ridgeback", 22, "red wheat", {77,44}}, 'Q' };
		ptr_fd = &fd;
		ptr_o2 = &o2;
		ptr_as = &as;
	}  // end construction block
	hijack(ptr_fd);
	hijack(ptr_o2);
	hijack(ptr_as);

}