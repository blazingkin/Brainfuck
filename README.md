Brainfuck
========

A Turing complete language. Annnnddd... that's about it.

Usage
=====

### Prerequisites
* gcc
* make

### Installation

Simply run `make`

### Usage

`./bf [Brainfuck source]`

Features
======

Brainfuck has 8 instructions, everything else is ignored

|Character|Function|
|---------|---------|
|>|Increment the data pointer|
|<|Decrement the data pointer|
|+|Increment the value at the current location|
|-|Decrement the value at the current location|
|.|Print the value at the current location|
|,|Get input from the user, store it at the current location|
|[|If the current location is 0, jump past the matching ]|
|]|If the current location is not 0, jump to the matching [|