/*
* Calculator_LCD_KEYS_Program.c
*
* Created: 9/14/2023 11:56:18 AM
*  Author: m2010
*/
#include "types.h"
#include "Stack_interface.h"

#include "Calculator_LCD_KEYS_interface.h"
#include "Interface_LCD.h"

void InfixToPostfix(u8 infix[] ,u8 postfix[]){
	u8 i , j ;
	u8 op , c ;
	Stack s;
	CreateStack(&s);
	for(i=0,j=0 ; (c=infix[i])!='\0';i++){
		if(IsDigit(c)){
			postfix[j++] = c;
		}
		else{
			if(!StackEmpty(&s)){
				StackTop(&op,&s);
				while(!StackEmpty(&s)&&President(op,c)){
					pop(&op,&s);
					postfix[j++] = op;
					if(!StackEmpty(&s)){
						StackTop(&op,&s);
						
					}
				}
			}
		}
		Push(c,&s);
	}
	while(!StackEmpty(&s)){
		pop(&op,&s);
		postfix[j++] = op;
	}
	postfix[j] = '\0';
}




u8 IsDigit(u8 c){
	return (c>='0' && c<='9');
}


u8 President(u8 op1 , u8 op2){
	if(op1 == '*' || op1 == '/'){
		return 1;
	}
	if(op1 == '+' || op1 == '-'){
		return (op2 != '*' && op2 != '/');
	}
	return 0;
}


u16 evaluatePostfix(u8 Express[]){
	u8 i;
	u8 c;
	u16 op1,op2,val;
	Stack s;
	CreateStack(&s);
	for(i=0;(c=Express[i])!='\0';i++){
		if (IsDigit(c)){
			Push((u16)(c-'0'),&s);
		}
		else{
			pop(&op2 , &s);
			pop(&op1 , &s);
			val=Oper(c,op1,op2);
			Push(val, &s);
		}
	}
	pop(&val,&s);
	return val;
	
}


u16 Oper(u8 c,u16 op1, u16 op2 ){
	u16 result;
	switch(c){
		case '+' :{  result=op1+op2; break;}
		case '-' :{  result=op1-op2; break;}
		case '*' :{  result=op1*op2; break;}
		case '/' :{  result=op1/op2; break;}
	}
	return result;
}



u8 arr[20];
u8 OP_arr[20];
static u8 ARR_Count = 0;

void ScanChar(u8 Value){
	if (Value == '=')
	{
		arr[ARR_Count] = '\0';
		Clac_Operation();
		
	}
	else{
		arr[ARR_Count] = Value;
		ARR_Count++;
		
	}

}


void Clac_Operation(){
	
	InfixToPostfix(arr,OP_arr);
	u32 ress=evaluatePostfix(OP_arr);
	LCD_voidWriteNumber(ress);
	
}












/*
static u8 i = 0 ;
u8 op ;
u8 GARR[20] ;
u8 NUM1[20] ;
u8 NUM2[20] ;
u8 NUMBER1  = 0;
u8 NUMBER2 = 0  ;








u32 add(u16 a , u16 b){
	return a+b;
}
u32 sub(u16 a , u16 b){
	return a-b;
}
u32 multuply(u16 a , u16 b){
	return a*b;
}
u32 division(u16 a , u16 b){
	return a/b;
}
u16 CalcOperation(u8 OP){

	switch (OP)
	{
		case '+':{
			return add(NUMBER1 , NUMBER2);
			break;
		}
		case '-':{
			return sub(NUMBER1 , NUMBER2);
			break;
		}
		case '/':{
			return division(NUMBER1 , NUMBER2);
			break;
		}
		case '*':{
			return multuply(NUMBER1 , NUMBER2);
			break;
		}
	}
}

void CharToNumber(){

	for(u8 NUM1_Iter=0;NUM1[NUM1_Iter]!='E';NUM1_Iter++){
		NUMBER1 = (NUM1[NUM1_Iter] - 48)*(10*NUM1_Iter);
	}
	for(u8 NUM2_Iter=0;NUM2[NUM2_Iter]!='E';NUM2_Iter++){
		NUMBER2 = (NUM2[NUM2_Iter] - 48)*(10*NUM2_Iter);
	}
	
}

void Save_to_ARR(u8 myChar){
	GARR[i] = myChar;
	i++;
}


void Save_to_Num_ARR(){
	int j;
	for (j = 0 ;GARR[j] != '=';j++){
		int l = 0;
		if (GARR[j] == '+' ||GARR[j] == '-' ||GARR[j] == '*' ||GARR[j] == '/' )
		{
			op = GARR[j];
			l = 1;
			NUM1[j] = 'E';
			continue;
		}
		switch (l)
		{
			case 0:{
				NUM1[j] = GARR[j];
				break;
			}
			case 1:{
				NUM2[j] = GARR[j];
				break;
			}
			
		}
		
		
	}
	NUM2[j] = 'E';
	
}







u8 KYP_Data ;
u8 Flag = 0;

void Execution(){
	
	KYP_Data = Keypad_U8GetKeyPressed();
	
	if (KYP_Data>='0' && KYP_Data<='9' )
	{
		if (Flag==0)
		{
			NUMBER1 = NUMBER1 * 10 + KYP_Data - '0';
		}
		else if (Flag==1){
			NUMBER2 = NUMBER2 * 10 + KYP_Data - '0';
		}
	}
	else if (KYP_Data>='*' && KYP_Data<='/')
	{
		op = KYP_Data;
		Flag=1;
	}
	

	if (KYP_Data!=255)
	{
		LCD_SendData(KYP_Data);
		if(KYP_Data == 'C'){
			op = 0;
			NUMBER1 = 0;
			NUMBER2 =0;
			LCD_voidClear();
		}
		else if(KYP_Data == '='){
			switch (op)
			{
				case '+':{
					LCD_voidWriteNumber(NUMBER1+NUMBER2);
					break;
				}
				case '-':{
					LCD_voidWriteNumber(NUMBER1-NUMBER2);
					break;
				}
				
				case '*':{
					LCD_voidWriteNumber(NUMBER1*NUMBER2);
					break;
				}


				case '/':{
					if (NUMBER2 == 0)
					{
						LCD_WriteString("NOT VALID");
					}
					LCD_voidWriteNumber(NUMBER1/NUMBER2);
					break;
				}				
			}
		}
		

		
	}

}
*/