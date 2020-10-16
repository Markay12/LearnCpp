# Learning C++

![C++Image](https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fupload.wikimedia.org%2Fwikipedia%2Fcommons%2Fthumb%2F1%2F18%2FISO_C%252B%252B_Logo.svg%2F160px-ISO_C%252B%252B_Logo.svg.png&f=1&nofb=1)

# Table of Contents
* [Imperative]()
* [Functions]()
* [Macros]()
* [Compilation]()
* [Anatomy: C vs Java]()
* [printf]()
* [Input]()
* [C++ Style]()
* [File Input and Output]()

---
# Part 2
* [Memory]()

* [Credit]()


# Imperative Paradigm
The Imperative Paradigm is focused on "how" to program and algorithms
* Do this
* Do that
* Repeat this 10 times

This is fully specified, fully controlled manipulation of data, which happens in a **stepwise** fashion

## What is a paradigm?
> A program is the application of an algorithm to a set of data 

Different paradigms give different focus to each of these parts

## Data
In the imperative paradigm data is represented by states
* collection of vars and their values made to explain the current state of data

Variables can be *snapped* to see the state
* this ties into the ideas of a Finite State Machine or Turing Machine
    * Tied to the Computational Theory

## FSM/Turing
* Variables describe the state of the program
* The algorithm describes the transitions and rules
* As we move from state to state, things about the data will change

## Data - Key Concepts
1. Type: What values and operations are allowed
2. Location: Where data is stored in the memory
3. Address: An integer associated with location
4. Reference/pointer: a name associated with the *variable that holds an address* of the location
5. Value: Data that is stored in this location
6. Scope: (lifetime) and visibility

# Functions
Functions are the primary unit of Abstraction in C and C++
They are largely like Java methods...
* A function and a method are technically two different things
* Methods specifically belong to a class/object

In C/C++ we follow a patter called "Forward Declaration" for most things we create
* when we create a function we pre-declare the 'signature' of the function before providing a definition

## Forward Declaration and Prototyping
The forward declaration gives
* return type
* name
* Param TYPE list

So when forward declaring a function it would look like:

```cpp
{

    float distance(int, int, int, int);

}
```
* you could give the params names `int x1`, however these become irrelevant and overwritten

All of this would go before the main function

1. We use forward declaration to prevent issues with mutual function calling 
2. C/C++ will not know that something exists
3. If they are forward declared, C/C++ knows they exists and allows this to work

# Macros

## Program Pre-Processing
Many programming languages allow the programmer to create Macros or inline procedures
* Macros are pre-processed
* Happens before primary compilation

References to Macros and inline procedures are replaced by their actual code which is compiled with the rest of the code
* retains readability while exploiting some effeciency features

These macros become a text replacement. When using these in BASH or our Linux command line we can think of alias
One that I use a lot of the time is `alias gc="git commit "` which allows me to commit a file quickly to git.
> git commit ./<filename> -m "comment"
now becomes
> gc ./<filename> -m "comment"


These are not used in all programming languages. More specifically this can be defined in C and C++
* _inline/inline prefix keyword for functions
* #define keywords

Java does not support macros
```cpp
{

    #define MAXVAL 100
    #define QUADFN(a,b) a*sqrt(b)+b*b- 2*a*a*t++
    x = MAXVAL + QUADFN(5,16);

}
```

## How do these macros work?

### Out-line - simulating a function call
Two separate statements that contradict each other
Statement [1] and statement [2]

We have two conflict opinions on using pictures in writing. 
Confucius gave a statement [1], while Dijkstra gave a different statement [2]....

Do you believe the statement [1] or [2]?
[1] Confucius : “A picture is worth a thousand words”.
[2] Dijkstra: “Pictures are a crutch for weak minds”.

### In-line
Use within the same sentence and keep the line going
We have two conflict opinions on using pictures in writing. Confucius gave a statement “A picture is worth a thousand words”, while Dijkstra gave a different statement “Pictures are a crutch for weak minds”.
Do you believe the statement “A picture is worth a thousand words” or “Pictures are a crutch for weak minds”?


### In vs Out
using input inline directly is most likely the best way to go
* sometimes programming a macro can work well

**Risks of Macros**
* Macros aren't checked for syntax, context or semantics- they are just inserted into the code then compiled
    * the data given is the data the macro will try and work with
* lead to difficulties in tracking down debugging errors


## Macros vs Inline
The programmer and compiler may choose to 'in-line' a function/method
* processed differently
* Macros are pre-processed and direct replacements
    * can lead to errors
* In-line procedures are handled by the compiler and is usually done only for simple functions

In-Lining (in C/C++):
* The compiler decided if the code is to be optimized
* Compiler is responsible for the correctness
* The programmer (you) will not know if the optimization is done and cannot predict performance
    * can use inline keywords for debugging to make sure this happens

Macro
* programmer decides if to optimize the program
* programmer is responsible for correctness


# Anatomy: C vs Java
C is the "grand parent" of many programming languages
C's syntax structure informs:
* C++
* Java
* JavaScript
* Pearl
* PHP
* C#
* ActionScript
* Objective-C

Makes going back and forth quite easy, these above are all C derived languages

## Anatomy of C
C's primary component structure revolves around **functions**

Functions are essentially sub-routines that can be called on at any time through name and a parameters list
There are two kinds of functions:
* pre-compiler library imports
* prototypes for functions and structures
* global scope
* main function
* function definitions

```cpp
{

    #include<stdio.h>

    main()
    {

        printf("Hello World!");

    }

}
```

We have statements to bring in our basic output function
* The #include statement is what brings a code library to our program
    * one major difficulty with C/C++ is remembering all the libraries that you need to use

stdio.h gives us access to Standard Input and Ouput functions
* Console and File based I/O

## The Main Function
This function can be void but some compilers won't allow for this
* You can just use `int main() { ...return 0; }`

The main function can take command line args, passed into the params
* `int main(int argc, char** argv)`
* by convention we name these vars
    * argc - Argument Count - contains num of args given in command line
    * char** argv - argument vector - Contains the C-style strings for each commadn line argumetn given to the executable

### printf()
printf() allows us to format out our output to a greater extent

# Compilation
gcc -g -Wall helloW.c -o hello

gcc - what are we compiling
g - include all debugging info
Wall - Show us all of the warnings
helloW.c - filename that we are compiling
o - redirect ouput to this filename

## Declaring Variables
At the machine level data is stored in a memory location as a sequence of bits.
A variable declaration binds a name, attributes and a value to a location in memory allowing the programmer easy access to data stored.
Attributes:
* Type - what kind of info is stored, determines size of storage
* Scope - What is the lifetime of the variable - this determines what part of RAM the var is stored in
* Qualifiers - modifications such as constant

Follows the following syntax
* <data type> <variable name> = <value>

You can separate multiple declarations with commas
* int a, b, c;

Initializations can also be separated

## Scope
The **scope** of a var begins at the point of declaration
* Local Scope - A var that is created within code-block of function
* Block Scope - A var that is created within some other code-block such as if statement, loop etc.

Declaration-before-use: All variables must be declared before they are used
```cpp
{

    int height = 6;
    int width = 6;
    int area  = height * width;

}
```
In the example above, if we change the declaration of height and place `int area = height * width;` we would get a compile time error

*Everything in C is declaration before use* 

# Data Types and C
C defines five basic types:
* Character - 1 Byte - char
* Integer - 4 Bytes - int
* Floating point decimal - 4 bytes - float
* Double floating point decimal - 8 bytes - double
* Void - valueless - void

C++ further Adds
* Boolean - 1 byte - bool
* Wide Character - 2 bytes - wchar_t

**NOTE: BOOLEAN does not exist as a data type in C** 

## Modifications
Short - short - reduces the size of an int to 2 bytes
Long - long - increases the size of an int to 8 bytes
Unsigned and Signed integers


# Printf
printf means - "print formatted data"
This is our primary output statement in C
Comes form <stdio.h> and workds similar to other printf commands
Java also has printf() and almost works identically

## Anatomy of printf
printf() has two primary parts
* Output/formatting string
* value list

printf == printf(<output string>, (value), (value), ...)

The output string is the primary output. Anything here will be output to standard output stream
* `printf("Hello")` --> Hello

The output string can also put in specifier tags similar to a macro
* all tags take the for of %<character>

## printf() specifiers
1. %d - decimal integer
2. %f - floating point number
3. %s - String
4. %c - character
5. %p - pointer address

Examples.
```cpp
{

    float myFloat = 3.1415926;
    int myInt = 12345;

    printf("My integer value: %10\n", myInt);
    printf("My float value: %10.2f\n", myFloat);


}
```

Output --> `My integer value: 12345`
           `My float value: 3.14`

## printf variants
fprintf(<file>, <output string>, <value list>)
* the file I/O version of printf

sprintf(<C string>, <output string>, <value list>)
* this allows you to compose a string, output is a character array

snprintf(<C String>, <max byte count>, <output string>, <value list>)
* This allows you to compose a string with a maximum size
* Output is stored into the specified character array <C string>
* This is usually used for buffer loading–Overloading causes loss of data as remaining


# Input
scanf
* at first glance these two printf and scanf can look similar
scanf() also uses a specifier tag system
scanf() --> scanf(<specifier string>, <variable list>)

### Oddity with Strings
This is due to Strings not being a data type within C
`char str [80]`
`printf ("Enter your family name: ");`
`scanf ("%79s", str);` --> limit this input to 79 characters

We can also get multiple inputs from scanf
`scanf("%i %i %i", %minx, %maxx, %miny);`
* these are read from left to right order

## Variants
fscanf(<file>, <output string>, <value list>)
* The file I/O version of scanf

sscanf(<C string>, <output string>, <value list>)
* allows us to compose a string. Input is stored into character array String

# C++ Style

## More Libraries
C/C++ revolves around using the right libraries
* `#include <iostream>` ...or `#include <iostream.h>` depends on the compiler that you are using
using namespace std;
* newer version of C++ have required that you cope into the std:: namespace to use iostream based functions and operators
* With increased emphasis on OOP and more modern dev namespaces become much more standard
    * using namespace is similar, but not completely like importing a library


## Output
* cout <<
* or std::cout - if 'using namespace std;' is not used

This is the basic output statement of C++.
Each item that you want to output is separarted by the insertion operator '<<'.
These items are inserted into the standards output stream as it is typed
* no whitespace is invented or used

`cout << "Hello World! << endl;`
* endl puts an endline in the output stream
`cout << "The location is " << x << ", " << << endl;`

cout is fast and simple at a base level, however, it doesn't format output. To do this we have to use another library
`#include <iomanip> … or … #include <iomanip.h>`
This brings in the output stream manipulation functions:
We can control
* size
* position
* number of digits

## iomanip
*TODO*


# File Input and Output

## Pointers
To work with files we need to manipulate file pointers.
The pipeline for working with files:
* Create file pointer
    * same thing is used for both input or output
* Open File
    * Same command is used for in and output
    * Need to give it different directives
* Use file
    * fscanf
    * fprintf

## File Pointer
When working with C files we need a file pointer
* FILE * <identifier>;

What is the FILE *  ?
* A FILE is an abstract data structure
    * Details of it are hidden from the programmer
    * Can only manipulate through C commands

What is the '*'?
* This says that the var in question is a pointer
* We are creating a pointer to a FILE structure

```cpp
{

    FILE* infile; //creates the file pointer

}
```

## Opening the File
Once we have the FILE* we need to point at, we open a file with the `fopen()` function
* `fopen("<path>", "<directives>")
* this creates a FILE for our FILE* to point at

The path is a string and consequently needs to follow string rules
* specifically double-slash for our paths
    * `fopen("c:\\temp\\test\\text.txt”, “<directives>”);`

The directives are also a string, but it is a string of key letters that tell the compiler what we want to do for the file
* similar to the use of Vi or any basic file editor in Linux

Common uses:
* "w" for write
* "r" for read

### fopen()
These directives can be combined 

Examples: 
* open file as binary file for reading
    * `fopen("file", "rb");`
    * NOTE: Binary reading/writing does not use fscanf/fprintf... we use fread/fwrite

```cpp
{

    #include <stdio.h>
    #include <stdlib.h>

    int main(int argc, char** argv)
    {

        FILE* outfile; //file pointer
        outfile = fopen("data.t", "w"); //open data.t for writing

        int i;

        //loop through file to fprinf information
        for (i = 0; i < 100; i++)
        {

            fprintf(outfile, "%d\n", i);

        }

        fclose(outfile);

        infile = fopen("data.t" , "r"); //open data.t for reading

        int read;
        int result;

        while (result != EOF) //EOF stands for end of file
        {

            result = fscanf(infile, "%d", read);
            printf("read: %d\n", read);

        }
        
        fclose(infile);

        return 0;


    }

}
```

### fscanf() input
Input and output work much the same as we would expect from the console. 
The File pointer must be used
* `fscanf(infile, "%s", strBuff);`
Like most file input, fscanf() will consume the file sequentially
When working with Strings, we need a C style string which is a character Array

```cpp
{

    FILE * infile;
    char buffer[30];
    infile = fopen("C:\\data\\names.txt","r");

    int i = 0;
    for (i = 0; i < 15; i++)
    {

        fscanf(infile, "%s", buffer);

    }

    fclose(infile); //close the file

}
```


### fprintf() - output
Similar to printf and how fscanf works, we are no redirecting our printf to a file with the file pointer
* `fprintf(outfile, "%d\n", value);`

NOTE: like printf() there isn't any automatic new line characters. A new line needs to be added explicitly
* Rule of Thumb - do NOT use excessive whitespace in file I/O
* If you are generating an output file to read as an input file later, make your standard clear and concise to make that an easy process


## Closing a File
If you open a file, don't forget to close it
* `fclose(<FILE *>);`

If files are not closed it can cause corruption or other errors
* This also frees up RAM the file was using


### **File Input and Output with C++**

```cpp
{

    #include <iostream>
    #include <fstream>

    using std::cout;
    using std::endl;

    int main(int argc, char** argv)
    {

        std::ofstream outfile;
        std::ifstream infile;
        int input;

        outfile.open("info.dat");

        for (int i = 0; i < 100; i++)
        {

            outfile << i << endl;

        }
        outfile.close();

        infile.open("info.dat");

        for (int i = 0; i < 100; i++ )
        {

            infile >> input;
            cout << "Read: " << input << endl;

        }
        infile.close();

        return 0;

    }

}
```

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
* Name
    * Way we can refer to this var easily

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