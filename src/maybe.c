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

void freeJust(Maybe* a) {
    if (a->has_value) {
        free(a->value);
        free(a);
    }
}

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

void * justInt64(int64_t i) {
    int64_t * it = (int64_t *) malloc(sizeof(int64_t));
    *it = i;
    return just(it);
}