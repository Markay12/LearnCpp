# Part 2


# Memory
In programming we work with a lot with RAM.
RAM is fast to use and access than a Hard Drive.

One thing is quicker...
**Registers**
* Hardware components at the lowest level
* Does data operations in the low level
* Load values into registers and add them together

C++ has a way to suggest to the compiler that a var should live in a register instead of RAM
Register keyword:
* `register int myint = 7;`
* If avalilable to be in a register, assign this var to a register when possible

This, however, has no functionality
It suggest to the compiler that this var is going to be used a LOT, but doesnt actually force any change
* Esentially gives the variable a higher priority than others

## Pointers
Variables consist of:
* Value
    * What's stored in the variable
    * The book itself
* Location
    * actual spot in memory
    * Where on the bookshelf is this stored?
* Address
    * reference to location
    * the floor number + shelf number + layer number of the book
* Name
    * Way we can refer to this var easily
    * The name of the book or the bookshelf

Address is how we refer to the location and the location is the actual location

## Pointers in the Library
The pointer is the index card in the Catalogue of the library
* The entry on the computer that you looked up the book on

Index card gives all the information about the book and tells you where it is and how to get it
* Can be used to fetch the book too

## Pointers
They have the same properties as the variable
* Value
* Location
* Address
* Name

This means we can have Pointers to pointers...
Pointers are also variables

## Why use Pointers?
Humans are good at remembering names, machines only work in addresses
Pointers give us both by providing a name to an address...
* This is especially useful when we start working with pointers to pointers
Direct control of these addresses is powerful and allows us to more fully control our memory

We work purely with addresses in pointers, but we also have the ability to access and work with the info the pointer is going towards
Operators:
* & - when is used with var name, and give us the address of that variable
    * allows the programmer to makje that var the target of the pointer

* \* is used in two contexts
    * use it to declare a pointer by adding it to the var declaration
        * int* myIntPointer
    * We use it to access information that the pointer points to - This is called de-referencing
        * int value = *myPointer

**What is a pointer?**
A variable that stores an address


## Byte-Addressable Memory
* This is going to be slightly different for a 64 bit system since memory addresses will be 64 bits in size
* Whenever we create anything that uses memory it is given an address in RAM that uses that much space
* The size of data directly impacts how the addressing is assigned
    * Each byte is given an address

### Visualization
Think of people going to the olympics
1. People come from wherever they live to a hotel/venue (disk)
2. Then they get to their floor and room number (address)
3. Eventually called to their event and waiting area (registers)
4. Complete the venue/task (CPU)

Understanding this can help us understand pointers as well
* We can manipulate what memory a pointer is pointing to by using simple math
    * we can add/subtract from the pointer to move it in memory
Pointers have data types
* That data type - byte addressable memory impacts how the pointer moves in memory

### Pointers and Byte-Addressable Memory
We have two types of pointers
* int*
* Char*

An int takes up 32 bits of memory (4bytes)
A char only takes 8 bits or 1 byte

When we add 1 to a pointer we are moving it "one full data-type"
* We see the int* movees 4 bytes
* The char* only moves one byte

# C/C++ Arrays and Strings
Most fundamental data structure
Arrays in many languages are similar with minor differences

*Basic Understanding*
* An array is a basic sata structure that stores multiple vars worth of info under a single name
* Values stores sequentially in memory and accessed through an index
* Index is necessary as it caluclates the position of each value that we need
* Array name labels the starting address of the array, and each val is found
    * Desired address = init address + (index * size of data stored)
This is why the first index is *always* zero

**Visualization**
Think of an apartment building
There are dozens of people living in a single apt building
The building only has one address, with all individuals inside it
However, each person inside this one address can be found through a specific unit

## Arrays
* Creating an array in C/C++ is fairly similar to Java
    * Major difference here is its Syntax

There are 2 types of arrays
**Arrays at Compile Time**
* Simple, as long as you know what is in it

**Create during Runtime**
* Known as dynamic arrays
* When we don't know much about the data coming in

### Basic Array Creation
Declaraing an array:
* <data type> <name>[<size>];
    * `int intList[5];`

Unlike Java, the array is not filled with anything. If you output the array, C/C++ will attempt to make the bits in RAM at that point 
* May get undesired results


**Accessing Array Values**
```cpp
{

    int myArray[10];
    for (int index = 0; index < 10; index++)
    {

        myArray[index] = index;

    }

}
```

Arrays are not automatically bound checked
We **must** keep track of the bounds through variables, constants or #defined macro constants
```cpp
{

    const int SIZE = 5;
    int array[SIZE];

    for(int index = 0; index < SIZE; index++)
    {

        cout << array[index] << endl;

    }

}
```
If we don't bound check our selves C/C++ will continue reading into RAM

## Multiple Dimensions
**2D Array**
* Just use another set of [] for each dimension
* `int twoD[10][20];`
* In mem each row is listed in order

**3D Array**
* `int threeD[5][6][7]`
* This can continue as much as you need, just set a new [] for each dimension

```cpp
{

    int twoD[4][4];
    for(int i = 0; i <4; i++)
    {

        for(int j = 0;j < 4; j++)
        {

            twoD[i][j] = j+i;

        }

    }

}
```

### Initializing an Array
`int array[10]` = {1,2,3,4,5,6,7,8,9,10};

We can initialize multidimenstional arrays with nesting lists
`int array[3][3]` = 1,2,3 ; 4,5,6

## Arrays - Strings vs. Chars
There are two ways of initializing arrays of character in declaration

`char s1[ ] = {'a', 'l', 'p', 'h', 'a'}; //as an array of char`
`char s2[ ] = "alpha"; //as a string`

These two initializations have different results in memory
s1("alpha") has a size of 5
s2("alpha\0") has a size of 6

The first item initializes that array as a character array rather than a String

s2 initializes it as a String and therefore automatically adds the '\0' character into the data
* this can lead to function issues looking for a C-style string. If '\0' is not present it can cause errors

**Truncated Initialization**
If the size of the array is specified and there is not enough space, the null charf will not be attached to the string

`char s2[5] = "alpha"`; will not attach this because there is not enough room. We specified a length of 5 and we need the '\0' at length 6

## Arrays and Sizing
In C/C++ there is a command that gets the size of Compile Time created arrays
* *This command is almost completely useless for dynamic arrays*
`sizeof(<target>);`

This command gives us the size in bytes of the target that is passed in
`size = sizeof(array);` / `(sizeof(datatype));`
`sizeof(array[0]);`

# Dynamic Allocated Arrays
These are used when we don't know the size of the data that we are going to be working with.
When we don't know the size of the data we cannot allocate the array during compile time

You cannot create an array with an unknown size:
* int myArray[]; gives an error of size unknown
    * We can't simply create one and resize later

If we guess, problems of too large and too small will occur

> How do we solve this issue?
**_Pointers_**
*Remember*: a pointer stores a memory address
* An array reference is the memory address of the first element
* A pointer can point to an array

C/C++ has different ways of doing this
* C uses malloc()
* C++ uses new

## C Style Dynamic Arrays
malloc()
* stands for memory allocation

malloc() returns a void pointer
Void is an undefined data type
* Void is how we deal with unknowns 

The malloc command needs to be casted into the type that we want it to be
* `void* address = malloc(<number of bytes>);`

We use the free(<item>) command to release the memory


## Making an Array
```cpp
{
   int* myArray;
   int size = 10;

   myArray = (int*) malloc(size * sizeof(int)); 
}
```

1. Malloc sets aside a number of bytes
2. We need an array of integers, so we need enough bytes to store those integers
3. So we multiply the number of integers we want, by the size of the integers
4. This memory gets allocated as a void pointer
5. We cast the void pointer to an integer pointer
6. We give the new integer pointer to our array pointer


## Make in C++
```cpp
{
    int* myArray = new int[10]
}
```
Looks a lot more like Java, no data caluculation like malloc

To frree space we use the delete command
* `delete[] myArray;`

```cpp
{
    int* myArray;
    int size = 10;

    myArray = (int*) malloc(size * sizeof(int));
    for(int c = 0; c < size; c++)
	    myArray[c] = c;
}
```

In C/C++ and other languages [] is actually an operator!
In the context of a statement such as `myArray[c]` they are in pointer notation
* x[y] is identical to *(x + y)
* myArray[c] -> *(myArray + c)
    * myArray is an address
    * c modifies this
    * new address and dereference to work with stored value at this location


## [] vs *
It is quicker to traverse memory by using pointer notation (*) instead of brackets
[] adds extra code since it has to be recognized and replaced in compilation
Using your pointers to navigate through memory is faster by fractions of a second


## **CAUTION**
We are now in the territory of managing our own memory which means we must be more aware of scope and how it is used.
Running through a loop that is local scoped rather than block scoped, when we don't dump our memory

# Memory Management
Golden Rule - "Whenever we dynamically allocate memory we MUST give it back"
Dynamically allocated memory is given a specific location in RAM
When we allocate from that part of RAM we have to free that memory back up so it can be used again
* **THIS DOES NOT HAPPEN AUTOMATICALLY**

## The HEAP
The heap is used for dynamic allocation
in Java the JVM creates a Heap for grabage collection and memory allocation
The heap is allocated during run-time through dynamic allocation, but it also needs to be managed during run-time
This is where grabage collection and memory management comes in
* if we don't manage the heap we end with memeory leaks

## Don't trust Sizeof
The sizeof() function is useless when it comes to dynamic arrays
* sizeof() returns the size of the target in bytes

Due to the creation of a dynamic array through the use of pointers we have to navigate through that pointer
```cpp
{
    int* myArray = new int[10]; //40 bytes of ints?
    cout << sizeof(myArray) << endl; // output ... 4 ...
}
```
It's size is the same size of an int... even when pointing to an array
* on a 64-bit machine the size of the pointer will be 8 bytes


# Multi-Dimenstion Dynamics

## Arrays of Arrays
In java we can make something called a "ragged array"
This is where we create a multi-dimenstional array but the "2D" portion isn't the same size

In Java this is very easy to create because they are objects here
```Java
{
    int[][] array = new int[10][];
    for(int c = 0; c < 10; c++)
    {

        array[c] = new int[c+5];

    }
}
```

## Dynamic 2D
When creating a C/C++ array, we have to use pointers
* and sometimes pointers to pointers