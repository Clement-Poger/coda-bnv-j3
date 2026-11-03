#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

typedef struct {
    const char *text;
    int error;
    int divide_by_zero;
} Parser;

static void skip_spaces(Parser *parser) {
    while (isspace((unsigned char)*parser->text)) {
        parser->text++;
    }
}

static int parse_expression(Parser *parser);

static int checked_value(Parser *parser, long long value) {
    if (value < INT_MIN || value > INT_MAX) {
        parser->error = 1;
        return 0;
    }
    return (int)value;
}

static int parse_factor(Parser *parser) {
    skip_spaces(parser);

    if (*parser->text == '+' || *parser->text == '-') {
        char sign = *parser->text++;
        int value = parse_factor(parser);
        return sign == '-' ? checked_value(parser, -(long long)value) : value;
    }

    if (*parser->text == '(') {
        parser->text++;
        int value = parse_expression(parser);
        skip_spaces(parser);
        if (*parser->text != ')') {
            parser->error = 1;
        } else {
            parser->text++;
        }
        return value;
    }

    errno = 0;
    char *end;
    long value = strtol(parser->text, &end, 10);
    if (end == parser->text || errno == ERANGE || value < INT_MIN || value > INT_MAX) {
        parser->error = 1;
        return 0;
    }
    parser->text = end;
    return (int)value;
}

static int parse_term(Parser *parser) {
    int value = parse_factor(parser);
    while (!parser->error) {
        skip_spaces(parser);
        char op = *parser->text;
        if (op != '*' && op != '/') {
            break;
        }
        parser->text++;
        int right = parse_factor(parser);
        if (op == '*') {
            value = checked_value(parser, (long long)value * right);
        } else if (right == 0) {
            parser->divide_by_zero = 1;
            parser->error = 1;
        } else {
            value = checked_value(parser, value / right);
        }
    }
    return value;
}

static int parse_expression(Parser *parser) {
    int value = parse_term(parser);
    while (!parser->error) {
        skip_spaces(parser);
        char op = *parser->text;
        if (op != '+' && op != '-') {
            break;
        }
        parser->text++;
        int right = parse_term(parser);
        value = checked_value(parser, op == '+'
            ? (long long)value + right
            : (long long)value - right);
    }
    return value;
}

int main(void) {
    char input[256];
    printf("Enter a basic equation: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 1;
    }

    Parser parser = {input, 0, 0};
    int result = parse_expression(&parser);
    skip_spaces(&parser);
    if (*parser.text != '\0') {
        parser.error = 1;
    }

    if (parser.divide_by_zero) {
        printf("Can't divide by 0.\n");
        return 1;
    }
    if (parser.error) {
        printf("Invalid equation.\n");
        return 1;
    }

    printf("Result: %d\n", result);
    return 0;
}
