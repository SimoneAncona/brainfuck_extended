# Brainfuck Extended
## Introduction
Brainfuck Extended is an extended version of the original Brainfuck

## Instructions
### Original instructions
- `>` Move pointer forward
- `<` Move pointer backward
- `+` Increment current cell
- `-` Decrement current cell
- `.` Print ASCII charaeter of the current cell
- `,` Get ASCII character and put in the current cell
- `[` While current cell != 0 loop
- `]` End loop

### New instructions
- `@` Define or call a new function
- `:` Body of the function
- `;` Return the value of the current position
- `&` Type check
- `#` Define list size
- `*` Jump to the cell number stored in the current cell
- `!` Define a macro (a function that uses the main context)

## Syntax
- Write a literal number to put a number in the current cell
- Write a literal string to fill the vector and auto increment the pointer

## Functions
Each function has its own vector and the pointer, the combination of the two is called context, the main function is the entry point.  
To define a function you use the `@`. For example
```
@return_10:10;  // a function that return the value 10
@main:@return_10++; // in cell 0 we now have 12
```
A function can also takes parameters.
```
@add_10(&num)
```

## Types
In BFE we have also type checking, the standard types are
- `&chr` for characters
- `&num` for numbers
- `&ptr` for generic pointers
- `&str` for null ending strings
- `&num#` pointer to num
- `&chr#10` string 10 character long

## Macros
A macro is like a function that use the context of the function that calls the macro. Example
```
!write_10_and_20:10>20;
@main:!write_10_and_20<<++; // the main context now is [12, 20]
```

# Examples
### Original Hello World
```
>++++++++[<+++++++++>-]<.>++++[<+++++++>-]<+.+++++++..+++.>>++++++[<+++++++>-]<+
+.------------.>++++++[<+++++++++>-]<+.<.+++.------.--------.>>>++++[<++++++++>-
]<+.
```
### Extended Hello World
```
@print_str(&chr#12):>.>.>.>.>.>.>.>.>.>.>.>.>.;  // take a 10 character long string and print it, the argument takes the first 12 cells
@main:@print_str("Hello World!");
```
### Original Sum
```
+++++++++++++++++++>++++++++++++++<[->>+<<]>[->+<]
```
### Extended Sum
```
@sum(&num,&num):[>>+<<-]>[->+<]>;
@main:@sum(19,14);
```
