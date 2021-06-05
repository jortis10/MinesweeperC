#ifndef CASE_HEADER
#define CASE_HEADER


typedef enum {CLOSE, OPEN, FLAG} State;
typedef enum {EMPTY, ONE, TOW, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, BOMB} Type;

typedef struct{

    State state;
    Type type;

}Case;




#endif // CASE_HEADER
