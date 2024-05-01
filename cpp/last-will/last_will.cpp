// Enter your code below the lines of the families' information

// Secret knowledge of the Zhang family:
namespace zhang {
    int bank_number_part(int secret_modifier) {
        int zhang_part{8'541};
        return (zhang_part*secret_modifier) % 10000;
    }
    namespace red {
        int code_fragment() {return 512;}
    }
    namespace blue {
        int code_fragment() {return 677;}
    }
}

// Secret knowledge of the Khan family:
namespace khan {
    int bank_number_part(int secret_modifier) {
        int khan_part{4'142};
        return (khan_part*secret_modifier) % 10000;
    }
    namespace red {
        int code_fragment() {return 148;}
    }
    namespace blue {
        int code_fragment() {return 875;}
    }
}

// Secret knowledge of the Garcia family:
namespace garcia {
    int bank_number_part(int secret_modifier) {
        int garcia_part{4'023};
        return (garcia_part*secret_modifier) % 10000;
    }
    namespace red {
        int code_fragment() {return 118;}
    }
    namespace blue {
        int code_fragment() {return 923;}
    }
}

// Enter your code below
namespace estate_executor {
    int assemble_account_number(int secret_modifier) {
        const int zhang_account_number = zhang::bank_number_part(secret_modifier);
        const int khan_account_number = khan::bank_number_part(secret_modifier);
        const int garcia_account_number = garcia::bank_number_part(secret_modifier);

        return zhang_account_number + khan_account_number + garcia_account_number;
    }

    int assemble_code() {
        const int khan_red = khan::red::code_fragment();
        const int zhang_red = zhang::red::code_fragment();
        const int garcia_red = garcia::red::code_fragment();

        const int khan_blue = khan::blue::code_fragment();
        const int zhang_blue = zhang::blue::code_fragment();
        const int garcia_blue = garcia::blue::code_fragment();

        const int red_code = khan_red + zhang_red + garcia_red;
        const int blue_code = khan_blue + zhang_blue + garcia_blue;

        return red_code * blue_code;
    }
}