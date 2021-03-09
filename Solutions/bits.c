/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
      /* some knowledge in digital design */
      return ~(x & y) & ~(~x & ~y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    /* just 0x80000000 */
    return 1 << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    /* the property that Tmax has is 
       Tmax + 1 == ~Tmax */
	/* however, -1 also has this property, so we sieve -1 */
	int IsNotNegOne = !!(~x);
    int A = x + 1;
    int B = ~x;
    return !(A ^ B) & IsNotNegOne;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
	/* temp = 0xaaaaaaaa, if all odd bits in x are set to 1 
	   then ~x & temp will be 0 */
	int exam,temp;
	exam = 0xaa;
	temp = exam << 24 | exam << 16 | exam << 8 | exam;
	return !(~x & temp);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    /* -x == ~x + 1 */
    return ~x + 1;
  return 2;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
	/* if x is AsciiDight, then  
	 * x >= 0x30 ,so SignLeft  = x - 0x30, then its sign bit will be 0 
	 * x <= 0x39 ,so SignRight = x - 0x40, then its sign bit will be 1 
	 */
	int SignLeft = (x + ~0x30 + 1) >> 31;
	int SignRight = (x + ~0x39) >> 31;
	return !SignLeft & SignRight;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	/*
	 * if x == 0 then IsZero = -1 (which means in binary it is 111...111)
	 * otherwise      IsZero =  0
	 */
	int IsZero = !!x + ~1 + 1;
	
	/* if x == 0 then we choose z, IsZero  = -1 , ~IsZero  =  0
	 * otherwise      we choose y, IsZero  =  0 , ~IsZero  = -1
	 */
	return (~IsZero & y) | (IsZero & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	/* we should not overflow. When x < 0 and y > 0 or x > 0 and y < 0
       we create a variable called IsSame */
	
	int SignX = x >> 0x1f;
	int SignY = y >> 0x1f;
	int IsSameSign = !(SignX ^ SignY);
   	int x_sub_y = x + ~y;	/* x <= y, but we want <, so we change to get x - y < 1 */
    	return (!IsSameSign & SignX) | ( IsSameSign & x_sub_y >> 0x1f);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
	/* if x == 0, then (x | ~x + 1)'s sign bit will be 0 
	   otherwise, it will be 1 */

	int IsZero = ((x | (~x + 1)) >> 31) + 1;
	return IsZero;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
	/* if x = 0 or x = -1, return -1
	 * otherwise 	       return  0
	 */
	int IsZero =  ((!x) << 31) >> 31;
	int IsNegOne = ((!(x ^ (~0))) << 31) >> 31;
	/* if x < 0 then op_number = ~x
	 * otherwise     op_number =  x
	 */
	int op_number = x ^ (x >> 31);
	/* we shift the op_number by 16,8,4,2,1 bit(s) to sum the return value */
	int shift_16,shift_8,shift_4,shift_2,shift_1;
	/*
	 * when op_number shift right by 16 bits, if it isn't 0 then shift_16 = 16
	 * otherwise						     shift_16 =  0
	 */
	shift_16 = (!!(op_number >> 16)) << 4;
	op_number = op_number >> shift_16;
	shift_8 = (!!(op_number >> 8)) << 3;
	op_number = op_number >> shift_8;
	shift_4 = (!!(op_number >> 4)) << 2;
	op_number = op_number >> shift_4;
	shift_2 = (!!(op_number >> 2)) << 1;
	op_number = op_number >> shift_2;
	shift_1 = (!!(op_number >> 1));
	
	int sum_shift = shift_16 + shift_8 + shift_4 + shift_2 + shift_1 + 2;
	return (IsZero & 1) | (IsNegOne & 1) | (~IsZero & ~ IsNegOne & sum_shift);
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {

	int Sign = 0x80000000 & uf;
	int Exp  = 0x7f800000 & uf;
	int Frac = 0x007fffff & uf;

	/* if Exp = 0*/
	if(!Exp)
	{
		Frac = Frac << 1;
	}
	/* if Exp != 0xff*/
	else if(Exp ^ 0x7f800000)
	//else if((Exp >> 23 & 0xff) ^ 0xff)
	{
		/* inc Exp, if Exp = 0xff,then Frac = 0 */
		Exp = Exp + 0x00800000;
		if(!(Exp ^ 0x7f800000))
			Frac = 0;
	}
	/* if uf is NaN or inf, we do nothing, just return*/
	return Sign | Exp | Frac;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
	/* if uf < 0 then Sign = 0
	 * othrwise       Sign = 1
	 */
	int Sign = !(uf >> 31);
	int Exp  = (uf >> 23) & 0xff;
	int Frac = uf & 0x007fffff;
	/* if it's 0.???? then return 0*/
	if(Exp < 127)
		return 0;
	/* if it's bigger than TMax or smaller than TMin, return 0x80000000*/
	else if(Exp >=158)
		return 0x80000000;
	else
	{
		/* because Frac have 23 bits, we shift left by 6 bits to the correct position.
		 * we do Frac | 0x40000000 to set the 30th bits to 1, because float is represent by 1.????? 
		 * !!! DO NOT FORGET THE ONE !!!
		 */
		Frac = (Frac << 6) | 0x40000000;
		Frac = Frac >> (30 + 127 - Exp);	// just to get the correct original number
		/* if it's negetive then we do ~Frac + 1 to get 1??????*/
		if(!Sign)
			return ~Frac + 1;
		return Frac;
	}
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
	int exp = x + 127;
  	if(exp < -22) 
		return 0;
  	if(exp >= 255) 
		return (0xff << 23);
	if(exp <= 0)
		return 1 << (22 + exp);
  	return (exp << 23);
}
