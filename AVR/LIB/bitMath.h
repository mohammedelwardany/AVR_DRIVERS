/*
 * bitMath.h
 *
 * Created: 9/16/2023 1:55:53 PM
 *  Author: m2010
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define SetBit(R,N) ((R)|=(1<<N))
#define ClrBit(R,N) ((R)&=~(1<<N))
#define ToggleBit(R,N) ((R)^=(1<<N))
#define GetBit(R,N) ((R>>N)&1)

#define ISLOW(R,N) (!((R>>N)&1))



#endif /* BITMATH_H_ */