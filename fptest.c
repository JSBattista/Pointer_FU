#include <stdio.h> 
#include <stdlib.h>
 //  The goal of this short demo is to see if we can use a structure with a function pointer that can 
 //  be used to point to different kinds of functions. The limitation is strict C code. 
 //  Ultimately the goal is a linked list of nodes that point to functions that do different things 
 //  so that instead of IF-THEN-ELSE and CASE/SWITCH blocks we can construct a list of function calls
 //  and set up that list pertaining to what we need at the given time and keep the program lean and mean.
 //  Even a recursive routine is possible. 
 //
 //
 //
// In this case is a function that will be pointed to that takes merely an integer
void fun(int* a)
{ 
     printf("Value of a is %i\n", *a); 
} 
// Now a function that takes s couple of doubles
void fin(double* a, double* b) 
{ 
    if (a) printf("hey now %f\n", *a); 
    if (b) printf("now hey %f\n", *b);
} 
// Now for the more enigmatic function
void fan (void* thevoid, void* anothervoid) {
	if(thevoid)printf("Now in the void: %i\n", *(int*)thevoid);
        if(anothervoid)printf("and beyond...  : %f\n", *(double*)anothervoid);
}
void fu(void** ultimatevoid) {
	for (int incr = 0; incr < 3; incr++){
	    if(ultimatevoid[incr])printf("turbo void %i\n", *(int*)ultimatevoid[incr]);
	} // for
}
// Here is the struct that defines a function point for two voids
struct node {
  int x;
   /* The above line is equivalent of following two 
   void (*fun_ptr)(int); 
   fun_ptr = &fun;  
  */
  void (*fun_ptr)(void*, void*);//= &fun; 
  struct node *next;
};


int main() 
{ 

   struct node *root;   // the main handle
   root = (struct node *) malloc( sizeof(struct node) ); 
   root->fun_ptr= &fun;  // This pointer points to the function that take the integer parameter. 
   struct node *temp;  // this is pointed to in node that the handle attaches to 
   temp = (struct node *) malloc( sizeof(struct node)); 
   temp->fun_ptr= &fin;  // Now this one is pointing to the other function that takes the doubles.


   struct node *last;  // this is pointed to in node that the handle attaches to 
   last = (struct node *) malloc( sizeof(struct node)); 
   last->fun_ptr=&fan;

   temp->next = last;	// This is the "end" of the linked list
   root->next = temp;   // Now temp becomes the next node in the linked list
                             
  // Invoking fun() using fun_ptr 
  int var = 11;
  int* ip;
  ip = &var; // works
  *ip = 13; // works -- can cause a crash though the previous call then this call means it does not crash, so there's some "allocation" afoot probably.
 


   handle = (struct node *) malloc( sizeof(struct node)); 
   handle = root;
   while (handle) { // the loop is kind of wrong, since now the int argument goes into the double version, and some pointer checking must be done there. This is only to show the capability.
      handle->fun_ptr(ip, NULL); 
      handle = handle->next;
   } // while



   root->fun_ptr(ip,NULL); 
   double *id;
   // A string thing here. If you assign the pointer to point to a variable, no problem. But try assigning a value directly
   // to what the pointer points to and you get a segfault, so malloc must be used.
   // Here is a proper "malloc" before assignment that avoids the segfault that would happen without it. 
   id = (double*)malloc( sizeof(double)); 
   *id = 77.77;
   double *a_d;
   double dd = 77.11;
   // a_d = &dd;
   a_d = (double*)malloc( sizeof(double)); 
   *a_d = 17.11;
   root->next->fun_ptr(id , a_d);
   root->next->next->fun_ptr(ip, id); 

   void* uv[3] = {ip, id, a_d};
   struct node *xeno;  // this is pointed to in node that the handle attaches to 
   xeno = (struct node *) malloc( sizeof(struct node) ); 
   xeno->fun_ptr= &fu;  // Now this one is pointing to the other function that takes the doubles.
   xeno->fun_ptr(uv, NULL);



   return 0; 
} 



// Note:
// Using something like *pointer = &thevariablepointedto works, then after that, something like *pointer = 77.00 is OK. But without
// first * = &, there is no implied memory allocation and the result is a segfault. So the choice must be made to either create the variable
// that is pointed to, or used malloc on the pointer. 

