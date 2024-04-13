/**
 * I really hate having functions that can fail in C, so this is my
 * fix.
 */

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    bool has_value;
    void * value;
} Maybe;

void * just(void * a) {
    Maybe * result = (Maybe *)malloc(sizeof(Maybe));
    result->has_value = true;
    result->value = a;
    return result;
}

Maybe nothing = { false, 0 };

bool isJust(Maybe* a) {
    return a->has_value;
}

void * justDouble(double d) {
    double * it = (double *) malloc(sizeof(double));
    *it = d;
    return just(it);
}

void * justLong(long l) {
    long * it = (long *) malloc(sizeof(long));
    *it = l;
    return just(it);
}

void * justInt64(int8_t i) {
    int8_t * it = (int8_t *) malloc(sizeof(int8_t));
    *it = i;
    return just(it);
}