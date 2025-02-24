#include "maths.h"

long factoriel(int a) {
    if (a < 0) return -1; 
    if (a == 0 || a == 1) return 1; 
    return a * factoriel(a - 1); 
}