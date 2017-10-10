# Data-Structures-Library-A
Data Structures Library done with Arrays.

Specifications 
The specifications for your classes can be found here: 
dynamic arrays 
circular dynamic arrays 
stacks 
queues
Your classes will be tested individually by integrating them with my testing code. 
Generic data pointers 
Generic values in C are stored in void * pointers. Any data pointer can be stored in a void * pointer with no cast: 
      void *p = newInteger(5);
The reverse requires a cast: 
      void *p = newInteger(5);
      integer *q = (integer *) p;
It is a grave error to cast a void * pointer to a type that does not reflect the original value stored in the void * pointer. 
Function pointers 
You can pass a function to another function in C by using a function pointer. Suppose you wish to pass a function with this signature: 
    int plus(int,int);
to a function named accumulate, in addition to an array of integers. The signature of accumulate would be: 
    int accumulate(int *array,int size,int (*combine)(int,int));
That third argument is a function pointer. To derive the proper function pointer type, simply take the signature of the function to be passed and perform the following transformations: 
    int plus(int,int);      //original signature
    int plus(int,int)       //remove the semicolon
    int (plus)(int,int)     //wrap the function name in parens
    int (*plus)(int,int)    //place an asterisk immediately before the function name
    int (*combine)(int,int) //change the name of the function to the name of the formal parameter
Inside the accumulate function, the combine function pointer can be called like a regular function: 
    total = combine(total,array[i]);
Programming style 
You must implement your data structures in C99. You must follow the C programming style guide for this project: http://beastie.cs.ua.edu/cs201/cstyle.html. 
Makefiles 
You should provide a makefile which responds to the commands: 
make
make clean
make test
All compilations should proceed cleanly with no warnings or errors at the highest level of error checking (the -Wall and -Wextra options). the make clean command should remove object files and any executables. 

The make command should compile all your modules, if they have not already been compiled. 

The make test command runs all your tests on your implementations. You should provide sufficient testing, especially testing the boundaries of your data structures. Examples of boundary testing are: 
displaying an empty stack
having a stack go non-empty, then empty, and then non-empty again
printing the size of an empty queue
put a large number of values in a dynamic array
