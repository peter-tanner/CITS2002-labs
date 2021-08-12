
struct numeral {
    char *numeral;
    int value;
    int count;
};

#define NUMERAL_AMOUNT 13

static const struct numeral NUMERALS[] = {
    {.count = 0, .numeral = "M",  .value = 1000},
    {.count = 0, .numeral = "CM", .value = 900},
    {.count = 0, .numeral = "D",  .value = 500},
    {.count = 0, .numeral = "CD", .value = 400},
    {.count = 0, .numeral = "C",  .value = 100},
    {.count = 0, .numeral = "XC", .value = 90},
    {.count = 0, .numeral = "L",  .value = 50},
    {.count = 0, .numeral = "XL", .value = 40},
    {.count = 0, .numeral = "X",  .value = 10},
    {.count = 0, .numeral = "IX", .value = 9},
    {.count = 0, .numeral = "V",  .value = 5},
    {.count = 0, .numeral = "IV", .value = 4},
    {.count = 0, .numeral = "I",  .value = 1}
};
