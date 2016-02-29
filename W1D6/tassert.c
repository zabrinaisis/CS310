#ifndef NDEBUG ?                                            \
#define assert (exp) {                                      \
    if ( !(exp) ) {                                         \
        fprint(stderr,                                      \
                "Assertion %s failed: file %s,line %d\n",   \
                #exp, __FILE__, __LINE__);                  \
        abort();                                            \
    }                                                       \
}                                                           \
:                                                           \
#define assert(ignore)

