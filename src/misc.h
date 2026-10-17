#ifndef MISC_H
#define MISC_H



#define LOG_LEVEL ERROR

typedef enum {
  VERBOSE,
  INFO,
  WARN,
  ERROR,
  NONE,
} LogLevel;

#ifndef __wasm32__
#define LOG(level, format, ...) \
  do { \
    if ((level) >= LOG_LEVEL) { \
      fprintf(stderr, format, ##__VA_ARGS__); \
    } \
  } while(0)
#else
#define LOG(level, format, ...) \
  do {} while (0)
#endif


#define NUMERIC_CASES \
  case '0': \
  case '1': \
  case '2': \
  case '3': \
  case '4': \
  case '5': \
  case '6': \
  case '7': \
  case '8': \
  case '9'

#endif
