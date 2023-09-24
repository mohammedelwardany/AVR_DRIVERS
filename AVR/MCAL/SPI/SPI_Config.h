/*
 * SPI_Config.h
 *
 * Created: 9/23/2023 11:49:31 AM
 *  Author: m2010
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

 /* Select option from : MASTER
						SLAVE */

#define SPI_MODE		MASTER

/* Config for Interrupt enable or disable */
/* Select option from : SPI_INT_ENABLE
						SPI_INT_DISABLE */

#define SPI_INTERUPT   SPI_INT_DISABLE

/* Config for The Data order */
/* Select option from : MSB
                        LSB */

#define SPI_DATA_ORDER  MSB


/* Config For The Clk Polarity  */
/* Options : RAISING_EDGE
             FALLING_EDGE */

#define SPI_CLK_POL     RAISING_EDGE

/* Config for The CLK Phase */
/* Options : SAMPLE
			 SETUP   */

#define SPI_CLK_PHASE   SETUP

/* Config Master Clk */
/* Options : SPI_CLK_4
             SPI_CLK_16
             SPI_CLK_64
             SPI_CLK_128
             SPI_HCLK_2
             SPI_HCLK_8
             SPI_HCLK_32
             SPI_HCLK_64 */

#define SPI_u8_CLK_RATE    SPI_CLK_64
#define  NULL  '\0'




#endif /* SPI_CONFIG_H_ */