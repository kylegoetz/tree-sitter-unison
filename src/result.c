#include "scanner_types.h"
#include "misc.h"
#include <stdio.h>



/**
 * Constructors for the continue, failure and success results.
 */
static Result res_cont = {.sym = FAIL, .finished = false};
static Result res_finish(Sym t) { return (Result) {.sym = t, .finished = true}; }
static Result res_fail = {.sym = FAIL, .finished = true};
