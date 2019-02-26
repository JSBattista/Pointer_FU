# Pointer_FU
A foray into pointers to functions in C, with  an array of pointers to functions. 
This C program is merely an exercise in pointers to functions. I wanted to see if it were possible to use a linked list of struct, but point to diffewrent functions in the nodes of the linked list. 
Naturally there is more room to do this sort of thing in C++ where we can do things like define a function of the same name with different arguments. In this case with C we have to use a more primitve form of crowbar. 
Void makes the world go around, apparently. 
The reasoning behind this overall is based on the desire to construct programs that have a variable length of commands in a loop without having to go through large "IF THEN" or CASE/SWITCH structures. For example, if we wanted to write one program that reads sensors of variable plurality, that could be set up at launch time, probably through the args given to the program. 
Then some sort of linked list, or in C++ perhaps a vector, is simply looped through over and over. No checking what was entered: that was all done at construction time when the list or vector was put together. It's a form of front-loading a program: do all the assertions in the start, build the list of function pointers for the functionality that is called on, discard the rest (if there were other functions and pointers defined that are not called upon) and then run like the wind. I have done this with C++ programs in the past. 
It also saves on having to write big dreary IF THEN ELSE blocks and assert them over and over again. 
The use of the same Structure definition to call on different functions is a bit of a hack though. Not sure I would actually do something like that. 
Additional notes and findings are in the code. 
