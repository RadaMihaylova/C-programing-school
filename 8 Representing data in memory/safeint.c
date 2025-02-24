#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "safeint.h"

int Overflow(int a, int b, int result) {
    if (a > 0 && b > 0 && result < 0) return 1;  
    if (a < 0 && b < 0 && result > 0) return 1;  
    return 0;
}

SafeResult safeadd(int a, int b) {
    SafeResult result = {0, 0};
    int res = a + b;
    if (Overflow(a, b, res)) {
        result.errorflag = 1;
    } else {
        result.value = res;
    }
    return result;
}

SafeResult safesubtract(int a, int b) {
    SafeResult result = {0, 0};
    int res = a - b;
    if (Overflow(a, -b, res)) {
        result.errorflag = 1;
    } else {
        result.value = res;
    }
    return result;
}

SafeResult safemultiply(int a, int b) {
    SafeResult result = {0, 0};
    int res = a * b;
    if (Overflow(a, b, res)) {
        result.errorflag = 1;
    } else {
        result.value = res;
    }
    return result;
}

SafeResult safedivide(int a, int b) {
    SafeResult result = {0, 0};
    if (b == 0) {
        result.errorflag = 1; 
    } else {
        result.value = a / b;
    }
    return result;
}

SafeResult safestrtoint(const char *str) {
    SafeResult result = {0, 0};
    char *end;
    long long res = strtol(str, &end, 10);
    
    if (*end != '\0' || res < INT_MIN || res > INT_MAX) {
        result.errorflag = 1; 
    } else {
        result.value = (int)res;
    }
    
    return result;
}
