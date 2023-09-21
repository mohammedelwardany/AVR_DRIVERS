/*
 * Stack_Program.c
 *
 * Created: 9/19/2023 1:09:37 AM
 *  Author: m2010
 */ 

#include "Stack_interface.h"


void CreateStack(Stack *ps){
	ps->top=0;
}


u8 StackFull(Stack *ps){
	return (ps->top>=MAXSTACK);
}





u8 Push(StackEntry e, Stack *ps){
	if (ps->top==MAXSTACK){
		///stack is full
		return 0;
	}
	else{
		ps->entry[ps->top++] = e;
		return 1;
	}
	
}


u8 pop(StackEntry *pe, Stack *ps){
	if (ps->top==0){
		///stack is empty
		return 0;
	}
	else{
		*pe=ps->entry[--ps->top] ;
		return 1;
	}
	
}
u8 StackEmpty(Stack *ps){
	return(!ps->top);
}


void StackTop(StackEntry *pe, Stack *ps){
	*pe=ps->entry[ps->top-1];
}

u8 StackSize(Stack *ps){
	return(ps->top);
}

void ClearStack(Stack *ps){
	ps->top=0;
}