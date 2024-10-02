#ifndef STD_types
#define STD_types

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long int u64;

//signed --> 2'compelement
typedef  char s8;
typedef  short int s16;
typedef  int s32;
typedef  long int s64;

typedef float f32;
typedef double f64;

enum STD_LevelTypes
{
	STD_Low=0,
	STD_High
};
typedef enum STD_LevelTypes STD_LevelTypes;


#endif
