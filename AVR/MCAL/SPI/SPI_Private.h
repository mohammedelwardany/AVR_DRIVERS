/*
 * SPI_Private.h
 *
 * Created: 9/23/2023 11:41:10 AM
 *  Author: m2010
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_
#include "types.h"


#define SPCR   *((volatile u8*)0x2D)
/* SPCR Bits */
#define SPIE                   7
#define SPE                    6
#define DORD                   5
#define MSTR                   4
#define CPOL                   3
#define CPHA                   2
#define SPR1                   1
#define SPR0                   0


#define SPSR   *((volatile u8*)0x2E)
/* SPSR BITS */
#define SPIF                   7
#define WCOL                   6
#define SPI2X                  0


#define SPDR   *((volatile u8*)0x2F)

#define MSB                  7
#define LSB                  0





////////////////////////////other definations ////////////////////////////////////////////
/* Master or slave Mode */

#define MASTER               0
#define SLAVE                1

/* Macros For Interrupt Enable */

#define SPI_INT_ENABLE           0
#define SPI_INT_DISABLE          1

/* Config Macros For THe data order */
#define MSB                  0
#define LSB                  1

/* Config Macros for CLK Polarity */
#define RAISING_EDGE         0
#define FALLING_EDGE         1

/* Config Macros for CLK PHASE */
#define SAMPLE               0
#define SETUP                1


/* Config Macros for CLK in Master Mode */
#define SPI_CLK_4              0
#define SPI_CLK_16             1
#define SPI_CLK_64             2
#define SPI_CLK_128            3
#define SPI_HCLK_2			  4
#define SPI_HCLK_8			  5
#define SPI_HCLK_32			   6
#define SPI_HCLK_64			   7




#endif /* SPI_PRIVATE_H_ */