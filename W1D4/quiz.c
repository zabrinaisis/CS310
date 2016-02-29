// A "function header" actually means a function with parameters.
// It only makes sense to put a const parameter as a pointer in a function.
// Global variables are bad practice. Hard to track which function changes.
// Static in a function means only that function can change it.
// Static out of a function means that the variable is private.

enum months{JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
typedef enum months Months;
// OR
typedef enum {JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, 
    SEP, OCT, NOV, DEC} Months;

// User made types should have a leading capitalized letter.
// You don't have to use an intermediate variable if using second typedef.

