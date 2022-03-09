/* 
 * <Becca Evans rae7867>
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
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

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
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
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
	int a, b;
	a = (~x & ~y); /*Find bit location in both integers where bit not set to 1.*/
	b = x & y; /*Find bits in both integers where both are set to 1. */
	return (~a) & (~b);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
	int b;
	unsigned a = 0;
	a = (~a >> 1); /*Makes every bit except for most significant bit 1*/
	b = a; 
	b = ~b; /*Makes every bit except for most significant bit 0*/
  	return b;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 2
 */
int isTmax(int x) {
	int plus1 = x+1; 
  	x = ~(x + plus1); /*Would equal 0 if x is max value*/
  	plus1= !plus1; 
  	return !(x + plus1);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
	int check;
   	int odd = (0xAA << 8) | 0xAA; /*0xAA -> 10101010*/
   	odd = odd | (odd << 16); /*int with all odd bits set to 1*/
   	odd = ~odd; /*inverts value, so all even bits to 1.*/
  	check = odd | x; 
  	check = ~check; /*if every bit is 0, it returns 1*/
   	return !check;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  	return (~x + 1);
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
	int max = 1 << 31; /*10000000....*/
   	int upper = ~(max | 0x39); 
   	int lower = ~0x30;
	upper = max & (upper+x); /*returns 0 if x<=0x39*/
   	lower = max & (lower+x+1); /*returns 0 if x>=0x30*/
   	return !(upper | lower); 
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	int a = !(!x); /*If x>0, assigns a as 1, and if x=0, assigns a as 0*/
	a = ~a + 1;
	y &= a;
	z = z & ~a;
	return y | z;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	int signBitX, signBitY, sign, answer;
	signBitX = x >> 31; /*Gets sign bit of x and 0 if positive and 1 if negative*/
	signBitY = y >> 31; /*Gets sign bit of y and 0 if positive and 1 if negative*/
	sign = !(signBitX ^ signBitY);
	answer = sign & (((x + ~y) >> 31) & 1); 
  	return answer | ((!signBitY) & signBitX);
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
	int inverse = ~x;
	x = inverse & ~(inverse+1);
	x = x >> 31;
	return x & 1;
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
	int s, totalBits, zero, one, two, four, eight, sixteen;
    s = x >> 31; /*Takes the sign bit*/
    
    x = (s & ~x) | (~s & x); /*Inverts the integer to its positive value if sign bit is negative*/
    
    sixteen = !(!(x >> 16)); /*0 if less than 16 bits needed but 16 if needed*/
    sixteen = sixteen << 4;
    x = x >> sixteen; 
    
    eight = !(!(x >> 8)); /*0 if less than 8 bits needed but 8 if needed*/
    eight = eight << 3;
    x = x >> eight;
    
    four = !(!(x >> 4)); /*0 if less than 4 bits needed but 4 if needed*/
    four = four << 2;
    x = x >> four;
    
    two = !(!(x >> 2)); /*0 if less than 2 bits needed but 2 if needed*/
    two = two << 1;
    x = x >> two;
    
    one = !!(x >> 1); /*0 if less than 1 bits needed but 1 if needed*/
    x = x >> one;
    
    zero = x; /*Leftover bit*/
    
	totalBits = sixteen + eight + four + two + one + zero + 1;
    return totalBits;
}
//float
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
	// Gets exponent value 
	int exponent = (uf >> 23) & 0xFF;
	
  	// Checks for denormalized cases by checking if exp equals 0
  	if(!exponent){
    	exponent = 0xFF; //setting all bits in exp to 1.
    	
    	uf = (uf & 0x80000000) | (uf << 1); //sets uf to argument.
  	}
  	// Checks for overflow by checking if the exp represents the largest normative value.
  	if(!(exponent ^ 0xFE)){
    	exponent = 0xFF;
    	// sets value to infinity
    	uf = (uf & 0x80000000) | (exponent << 23);
  	}
  	// Computes the product if exp does not equal 0xFF.
  	if(exponent ^ 0xFF){
    	uf = uf + (1 << 23); //multiply by 2.
  	}
	return uf;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
	int fraction;
 	int exponent = 158; //2^(7-1)-1 + 23 (M bits) + 8 (exp bits)
    int mostSB = 1 << 31; //100000...
    int sign = x & mostSB; //finds sign bit
    
    //minimum case
    if (x == mostSB) {
        return mostSB | (158 << 23);
    }
    //if x is zero
    if (!x){
        return 0;
    }
    //inverts negative integer to positive
    if (sign) {
    	x = ~x + 1; 
    }
    //build fraction
    while (!(x & mostSB)) {
        x = x << 1;
        exponent--;
    }
    fraction = (x & ~mostSB) >> 8;
    
    if ((x & 0x80) && ((x & 0x7F) > 0 || fraction & 1))
        fraction++;
    return sign + (exponent << 23) + fraction;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
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
int float_f2i(unsigned uf) {
	unsigned signBit = uf >> 31; //sign bit --> first bit
	unsigned exponent = (uf >> 23) & 0xFF; //8 bits
	unsigned fraction =(uf & 0x7FFFFF); //fraction --> 23 bits
	unsigned bias = 0x7F; //127
	unsigned solut = fraction;
  	// checks for denormalized cases: NaN and Infinity
  	if (exponent == 0xFF) 
    	return 0x80000000u;
  	// checks if exponent less than Bias cases
  	if (exponent < bias)
    	return 0;
  	exponent -= bias;
  	//overflow case
  	if (exponent >= 31){
    	return 0x80000000u;
    }
  	//shift bits to obtain integer results
  	if (exponent > 22) {
    	solut = fraction << (exponent - 23);
    }
  	else {
    	solut = fraction >> (23 - exponent);
	}
  	// add 1 << exp for normalized case
  	solut = solut + (1 << exponent);
  	// turns solut into a negative value if the sign bit is 1
  	if (signBit){
    	solut = -solut;
    }
  	return solut;
}
