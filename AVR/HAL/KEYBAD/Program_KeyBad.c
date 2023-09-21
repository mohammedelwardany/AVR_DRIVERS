/*
 * Program_KeyBad.c
 *
 * Created: 9/9/2023 12:54:53 PM
 *  Author: m2010
 */


#include "Interface_KeyBad.h"

u8 ROW_PIN [4]={ROW_PIN0,ROW_PIN1,ROW_PIN2,ROW_PIN3};
u8 COL_PIN [4]={COL_PIN0,COL_PIN1,COL_PIN2,COL_PIN3};

const u8 KPD_u8SwitchVal[4][4]=
{
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'C','0','=','+'}
};
/*KPD INIT*/
void Keypad_VidInit(void)
{

	/* Set Row Pins as an Input */
	for (u8 i=0;i<4;i++)
	{
		Dio_SetPinMode(ROW_PIN[i], InPut_PullUp);
	}
	/* Set Column Pins as an Output */
	for (u8 i=0;i<4;i++)
	{
		Dio_SetPinMode(COL_PIN[i],OutPut_High);
	}
	
}
/*KPD Get pressed*/
u8 Keypad_U8GetKeyPressed(void)
{
	u8 LOC_U8RowCount;
	u8 LOC_U8ColCount;
	/*Initialize the switch status to NOT PRESSED*/
	u8 LOC_U8ReturnValue=255;
	u8 LOC_U8PinState;
	/*Looping on columns of the keypad*/
	for(LOC_U8ColCount=0;LOC_U8ColCount<4;LOC_U8ColCount++)
	{
		/*Active the Column */
		DIO_WritePinVal(COL_PIN[LOC_U8ColCount],LOW);
		/*Loop to read the all row pins*/
		for(LOC_U8RowCount=0;LOC_U8RowCount<4;LOC_U8RowCount++)
		{
			/*check the status of the switch*/
			DIO_ReadPinVal(ROW_PIN[LOC_U8RowCount],&LOC_U8PinState);
			if(LOC_U8PinState==0)
			{
				/*Get the Value of the current pressed switch*/
				LOC_U8ReturnValue=KPD_u8SwitchVal[LOC_U8ColCount][LOC_U8RowCount];
				/*wait until the switch is released(Single Press)*/
				while(LOC_U8PinState==0)
				{
					DIO_ReadPinVal(ROW_PIN[LOC_U8RowCount],&LOC_U8PinState);
				}
				/*Delay To avoid Bouncing*/
				_delay_ms(1);
			}
			else
			{
				/*Do Nothing*/
			}
		}
		/*Deactivate the Column*/
		DIO_WritePinVal(COL_PIN[LOC_U8ColCount],HIGH);
	}
	return LOC_U8ReturnValue;
}






//  #include "types.h"
//  #include "Configure_KeyBad.h"
// #include "Interface_KeyBad.h"
// 
//  #include "Dio_Int.h"
//  #include"util/delay.h"
// 
//  void KEYPAD_uint8Init(void)
//  {
// 	 //Set rows as input
// 	 Dio_SetPinMode(KEYPAD_COLUMN_1 , InPut_PullUp);
// 	 Dio_SetPinMode(KEYPAD_COLUMN_2 , InPut_PullUp);
// 	 Dio_SetPinMode(KEYPAD_COLUMN_3 , InPut_PullUp);
// 	 Dio_SetPinMode(KEYPAD_COLUMN_4 , InPut_PullUp);
// 
// 	 //Set Columns as output
// 	 //Deactivate for all columns by setting it to High
// 	 Dio_SetPinMode(KEYPAD_ROW_1 , OutPut_High);
// 	 Dio_SetPinMode(KEYPAD_ROW_2 , OutPut_High);
// 	 Dio_SetPinMode(KEYPAD_ROW_3 , OutPut_High);
// 	 Dio_SetPinMode(KEYPAD_ROW_4 , OutPut_High);
//  }
// 
//  u8 KEYPAD_uint8GetPressedKey(void)
//  {
// 	 
// 	 
// 	 
// 	 
// 	 
// 	 
// 	 
// 	 
// 	 u8 Local_uint8PressedSwitch = 'N';
// 	 u8 Local_uint8CurrentCol;
// 	 u8 Local_uint8CurrentRow;
// 	 u8 Local_uint8CurrentColStatus;
// 
// 	 for (Local_uint8CurrentRow = 0;
// 	 Local_uint8CurrentRow < KEYPAD_ROWS_NO ;
// 	 Local_uint8CurrentRow++)
// 	 {
// 		 /*activate the current column*/
// 		 DIO_WritePinVal(ROW_ARR[Local_uint8CurrentRow],LOW);
// 				 _delay_ms(35);
// 
// 		 for (Local_uint8CurrentCol = 0 ;
// 		 Local_uint8CurrentCol < KEYPAD_COLUMNS_NO ;
// 		 Local_uint8CurrentCol++)
// 		 {
// 			 /*Get Row Value*/
// 			 DIO_ReadPinVal(COL_ARR[Local_uint8CurrentCol] , &Local_uint8CurrentColStatus);
// 			 /*If Switch is pressed */
// 			 if (Local_uint8CurrentColStatus == LOW) //34an e7na pull up
// 			 {
// 				 _delay_ms(35);
// 				 /*Wait For Debouncing*/
// 				 /*If Switch is pressed */
// 
// 				 DIO_ReadPinVal(COL_ARR[Local_uint8CurrentCol] , &Local_uint8CurrentColStatus);
// 
// 				 if (Local_uint8CurrentColStatus == LOW) //34an e7na pull up
// 				 {
// 					 Local_uint8PressedSwitch = KYP_ARR[Local_uint8CurrentRow][Local_uint8CurrentCol];
// 				 }
// 				 /* the switch which is in this row and that column is pressed*/
// 				 
// 			 }
// 
// 		 }
// 		 /*Deactivate the column*/
// 		 DIO_WritePinVal(ROW_ARR[Local_uint8CurrentRow],HIGH);
// 		// _delay_ms(25);
// 
// 	 }
// 
// 	 return Local_uint8PressedSwitch ;
//  }



// 
// 
// 
// 
// u8 arr_row_pin[N_Row]={KEYPAD_ROW_1,KEYPAD_ROW_2,KEYPAD_ROW_3,KEYPAD_ROW_4};
// 
// 
// 
// u8 arr_col_pin[N_Col]={KEYPAD_COLUMN_1,KEYPAD_COLUMN_2,KEYPAD_COLUMN_3,KEYPAD_COLUMN_4};
// 
// u8 arrKeypad[N_Row][N_Col]={{'7','8','9','/'},
// {'4','5','6','*'},
// {'1','2','3','-'},
// {'c','0','=','+'}};
// 
// void KeypadInit(){
// 	for(int i =0; i < 4;i++){
// 		Dio_SetPinMode(arr_row_pin[i],OutPut_High);
// 		Dio_SetPinMode(arr_col_pin[i],InPut_PullUp);
// 		
// 	}
// 	
// }
// 
// u8 KeyPadGetKey(){
// 	
// 	u8 k=NO_KEY;
// 	u8 READVALUE;
// 	for(int row = 0 ; row < N_Row; row++){
// 		DIO_WritePinVal(arr_row_pin[row],LOW);
// 		for(int col = 0 ; col < N_Col ; col++){
// 			DIO_ReadPinVal(arr_col_pin[col],&READVALUE);
// 			if(READVALUE==LOW){
// 				k=arrKeypad[row][col];
// 			}
// 			//_delay_ms(35);
// 			while(k==NO_KEY);
// 			
// 		}
// 		DIO_WritePinVal(arr_row_pin[row],HIGH);
// 
// 	}
// 	return k;
// }
// 
