#include <stdio.h> 
#include <stdlib.h>
//
//	Deeper variation into array of function pointers, dynamic even. 
//	fun_ptr is now array of pointers.
//
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
	    if(ultimatevoid[0])printf("turbo void %i\n", *(int*)ultimatevoid[0]);
	    if(ultimatevoid[1])printf("turbo void %f\n", *(double*)ultimatevoid[1]);
	    if(ultimatevoid[2])printf("turbo void %f\n", *(double*)ultimatevoid[2]);
}
//https://stackoverflow.com/questions/5488608/how-define-an-array-of-function-pointers-in-c
// Here is the struct that defines a function point for two voids
struct nodeType1 {
  void (**fun_ptr)(void*, void*); 
  struct nodeType1 *next;
};
int main() 
{ 
   int i = 0;
   struct nodeType1 *root;   // the main handle
   root = (struct nodeType1 *) malloc( sizeof(struct nodeType1) ); 
   root->fun_ptr = calloc( 1, sizeof( void (*)( void*,void* ) ) );
   root->fun_ptr[0]= &fun;  // This pointer points to the function that take the integer parameter. 

   struct nodeType1 *second;   // the main handle
   //second = (struct nodeType1 *) malloc( sizeof(struct nodeType1) ); 
   second = (struct nodeType1 *) malloc( sizeof(struct nodeType1) ); 
   second->fun_ptr = calloc( 2, sizeof( void (*)( void*,void* ) ) );
   second->fun_ptr[0]= &fan;   
   second->fun_ptr[1]= &fu;  

   second->next = NULL;
   root->next = second;

   int var = 11;
   int* ip;
   ip = &var; // works
   double *id;
   id = (double*)malloc( sizeof(double)); 
   *id = 77.77;
   double *a_d;
   double dd = 77.11;
   a_d = (double*)malloc( sizeof(double)); 
   *a_d = 17.11;

   void* uv[3] = {ip, id, a_d};
   root->fun_ptr[0](ip,NULL);
   //   root->fun_ptr[1](ip,NULL); // but there was onlye ONE handle.
   root->next->fun_ptr[0](ip,uv[2]);
   root->next->fun_ptr[1](uv,NULL);
   return 0; 
} 
