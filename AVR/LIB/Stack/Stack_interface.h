/*
 * Stack_interface.h
 *
 * Created: 9/19/2023 1:09:05 AM
 *  Author: m2010
 */ 


#ifndef STACK_INTERFACE_H_
#define STACK_INTERFACE_H_

#include "types.h"


#define MAXSTACK 50
typedef u8 StackEntry;
typedef struct stack{
	u8 top;
	StackEntry entry[MAXSTACK] ;
}Stack;


void CreateStack(Stack *ps);
u8 StackFull(Stack *ps);
u8 Push(StackEntry e, Stack *ps);
u8 pop(StackEntry *pe, Stack *ps);
u8 StackEmpty(Stack *ps);
void StackTop(StackEntry *pe, Stack *ps);
u8 StackSize(Stack *ps);
void ClearStack(Stack *ps);


#endif /* STACK_INTERFACE_H_ */