# Learning C++

![C++Image](https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fupload.wikimedia.org%2Fwikipedia%2Fcommons%2Fthumb%2F1%2F18%2FISO_C%252B%252B_Logo.svg%2F160px-ISO_C%252B%252B_Logo.svg.png&f=1&nofb=1)

# Table of Contents
* [Imperative]()
* [Functions]()
* [Macros]()
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


