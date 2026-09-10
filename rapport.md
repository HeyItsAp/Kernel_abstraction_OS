# Assignment 01: Process abstraction
Github link (Tba):

## 01 The process abstraction
A process is a step by step execution av a program with restricted rights controlled by the kernel.
The program usually rests "on top" of the kernel and is dependent on user-level priviliges. Kernel-level operations are step deeper.
Even so a process usually needs permissions from the kernel for most basic function. Such as accessing memory of any prcess, reading and writing to the disk and hardware settings.
That means it has to go from user-level to kernel-level for priviliged instructions. It goes up back again after said system call for a certain function, and also on interrupts/execeptions, implemented up-calls and on a new porcess.
  
### Code 

## 02 Porcess memory and segments
Sketch of addresses in memory. High addresses being on top and low addresses at the bottom 
| Physical Memory | Definition/What they do |
| -------- | ------- |
| Enviroment & Arguments | Contains argv and pointer. e.g., 0xFFFFFFFF |
| Stack: | Static Memory. Holds local variables during procedure calls |
| Heap: | Dynamic Memory. malloc saves data here|
| Data Segment :| Initialized Data. Globals and statics |
| Code Segment: | Machine instructions. Assemsbly even |

Local variables are usually stored in the stack in is declared in a block or function. 
	Can only be accessed within that function or block
Global variables are found outside of all functions and be stored dynamically through the heap or in the data segment or memory.
	Can be accessed at all times
Static is declared usually with the keyword static at front. Behaves much like a local but is stored in the data segment.

In the example below we have three variables; var1, var2, and *var3;
-	var 1 is a global variale, 
-	var2 and var3 are local variable that lives in the stack 
		but var3 being a pointer to a variable in the heap.

'''c
#include <stdio.h>
#include <stdlib.h>
int var1 = 0;
void main()
{
	int var2 = 1;
	int *var3 = (int *)malloc(sizeof(int)); // Note, since we are using malloc(), var3 will be a
	// pointer into the heap!
	// So the question is, where is the pointer stored?
	*var3 = 2;
	printf("Address: %x; Value: %d\n", &var1, var1);
	printf("Address: %x; Value: %d\n", &var2, var2);
	printf("Address: %x; Address: %x; Value: %d\n", &var3, var3, *var3);
'''

## 3 Program Code
Given the following code
'''c
#include <stdio.h>
#include <stdlib.h>
int var1 = 0;
void main()
{
	int var2 = 1;
	int *var3 = (int *)malloc(sizeof(int)); // Note, since we are using malloc(), var3 will be a
	// pointer into the heap!
	// So the question is, where is the pointer stored?
	*var3 = 2;
	printf("Address: %x; Value: %d\n", &var1, var1);
	printf("Address: %x; Value: %d\n", &var2, var2);
	printf("Address: %x; Address: %x; Value: %d\n", &var3, var3, *var3);
'''

The sizes of text, data and bss segments can be found using "size 'filename'". When compiling the code above (named mem) we get the following results:


