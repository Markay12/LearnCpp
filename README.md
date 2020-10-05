# LearnCpp

# Table of Contents
1. [Imperative]()
2. [Functions]()
3. [Macros]()

999. [Credit]()


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



