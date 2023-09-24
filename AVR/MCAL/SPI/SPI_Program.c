/*
 * SPI_Program.c
 *
 * Created: 9/23/2023 11:56:32 AM
 *  Author: m2010
 */ 
#include <util/delay.h>

#include "bitMath.h"
#include "SPI_Interface.h"

void SPI_voidInit(void)
{


	/* Interrupt Enable */
#if SPI_INTERUPT == SPI_INT_DISABLE
	ClrBit(SPCR,SPIE);
#elif SPI_INTERUPT == SPI_INT_ENABLE
	SetBit(SPCR,SPIE);
#endif

	/*if( SPI_u8_INT_STATE == SPI_u8_INT_ENABLE )
	{
		SetBit(SPCR,SPCR_SPIE);
	}*/

	/* Master mode or slave Mode */

#if SPI_MODE == MASTER
	SetBit(SPCR,MSTR);
#if SPI_u8_CLK_RATE  == SPI_CLK_4
	ClrBit(SPCR,SPR1);
	ClrBit(SPCR,SPR0);
#elif SPI_u8_CLK_RATE  == SPI_CLK_16
	ClrBit(SPCR,SPR1);
	SetBit(SPCR,SPR0);
#elif SPI_u8_CLK_RATE  == SPI_CLK_64
	ClrBit(SPCR,SPR0);
	SetBit(SPCR,SPR1);
#elif SPI_u8_CLK_RATE  == SPI_CLK_128
	SetBit(SPCR,SPR1);
	SetBit(SPCR,SPR0);
#elif SPI_u8_CLK_RATE  == SPI_HCLK_2
	ClrBit(SPCR,SPR1);
	ClrBit(SPCR,SPR0);
	SetBit(SPSR,SPI2X);
#elif SPI_u8_CLK_RATE  == SPI_HCLK_8
	ClrBit(SPCR,SPR1);
	SetBit(SPCR,SPR0);
	SetBit(SPSR,SPI2X);
#elif SPI_u8_CLK_RATE  == SPI_HCLK_32
	SetBit(SPCR,SPR1);
	ClrBit(SPCR,SPR0);
	SetBit(SPSR,SPI2X);
#elif SPI_u8_CLK_RATE  == SPI_HCLK_64
	SetBit(SPCR,SPR1);
	SetBit(SPCR,SPR0);
	SetBit(SPSR,SPI2X);
#endif
#elif SPI_MODE == SLAVE
	ClrBit(SPCR,MSTR);
#endif

	/* Select Data order */
#if SPI_DATA_ORDER == MSB
	ClrBit(SPCR,DORD);
#elif SPI_DATA_ORDER == LSB
	SetBit(SPCR,DORD);

#endif

	/* Select the Clk Polarity */
#if SPI_CLK_POL == RAISING_EDGE
	ClrBit(SPCR,CPOL);
#elif SPI_CLK_POL == FALLING_EDGE
	SetBit(SPCR,CPOL);
#endif

	/* Select the Clk Phase */
#if SPI_CLK_PHASE == SAMPLE
	ClrBit(SPCR,CPHA);
#elif SPI_CLK_PHASE == SETUP
	SetBit(SPCR,CPHA);

#endif

	/* Enable SPI */
	SetBit(SPCR,SPE);

}

u8 SPI_u8SendRecieveByte(u8 Copy_u8Data, u8 *Copy_pu8RecData)
{
	u8 Local_u8ReturnState = 1;
	/* Check the pointer */
	if(Copy_pu8RecData == NULL)
	{
		Local_u8ReturnState = 0;
	}
	else
	{
		/* Write Data Byte */
		SPDR = Copy_u8Data;
		/* wait until transmission is completed */
		while(GetBit(SPSR,SPIF) == 0);
		/* Get the Data */
		*Copy_pu8RecData = SPDR;
	}

	return Local_u8ReturnState;
}
