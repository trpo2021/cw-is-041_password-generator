enum short_option {
    MOD = 'm',
    LENGTH = 'l',
    COUNT = 'c',
    SYMBOLS = 's',
    HELP = 'h'
};

typedef struct {
    int count;
    int length;

    bool flag_number;
    bool flag_capital_letter;
    bool flag_small_letter;
    bool flag_special_symbol;
} password_properties;
