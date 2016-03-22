#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "dbg.h"

#define MAX_DATA 100

int read_string(char **out_string, int max_buffer) {
    *out_string = calloc(1, max_buffer + 1);
    check_mem(*out_string);

    char *result = fgets(*out_string, max_buffer, stdin);
    check(result != NULL, "Input error.");   

    // remove trailing new line
    int str_len = strlen(result);
    result[str_len - 1] = '\0';

    return 0;

error:
    if (*out_string) free(*out_string);
    *out_string = NULL;
    return -1;
}

int read_int(int *out_int) {
	char *input = NULL;
	int rc = read_string(&input, MAX_DATA);
	check(rc == 0, "Failed to read number.");

	*out_int = atoi(input);

	free(input);
	return 0;

error:
    if (input) free(input);
    return -1;
}

int read_scan(const char *fmt, ...) {
    int i = 0;
    int rc = 0;
    int *out_int = NULL;
    char *out_char = NULL;
    char **out_string = NULL;
    int max_buffer = 0;

    va_list argp;
    va_start(argp, fmt);

    for (i = 0; fmt[i] != '\0'; i++) {
    	if (fmt[i] == '%') {
    		i++;
    		switch(fmt[i]) {
    			case '\0':
	    			sentinel("Invalid format, you ended with %%");
	    			break;

    			case 'd':
	    			out_int = va_arg(argp, int *);
	    			rc = read_int(out_int);
	    			check(rc == 0, "Failed to read int.");
	    			break;

	    		case 'c':
	    			out_char = va_arg(argp, char *);
	    			*out_char = fgetc(stdin);
	    			break;

	    		case 's':
	    			max_buffer = va_arg(argp, int);
	    			out_string = va_arg(argp, char **);
	    			rc = read_string(out_string, max_buffer);
	    			check(rc == 0, "Failed to read string.");
	    			break;

	    		default:
		    		sentinel("Invalid format.");
		    }
		} else {
			fgetc(stdin);
		}

		check(!feof(stdin) && !ferror(stdin), "Input error.");
	}

	va_end(argp);
	return 0;

error:
	va_end(argp);
	return -1;
}

int _printf(const char* fmt, ...) {
	int i;
	int rc;
	int int_to_print;
	int char_to_print;
	char* str_to_print;
    va_list argp;
    va_start(argp, fmt);

    for (i = 0; fmt[i] != '\0'; i++) {
    	if (fmt[i] == '%') {
    		i++;
    		switch(fmt[i]) {
    			case '\0':
	    			sentinel("Invalid format, you ended with %%");
	    			break;

    			case 'd':
	    			int_to_print = va_arg(argp, int);
	    			char buffer[10] ;
	    			sprintf(buffer, "%d", int_to_print);
	    			rc = fputs(buffer, stdout);
	    			check(rc != EOF, "Failed to write int.");
	    			break;

	    		case 'c':
	    			char_to_print = va_arg(argp, int);
	    			rc = fputc(char_to_print, stdout);
	    			check(rc != EOF, "Failed to write int.");
	    			break;

	    		case 's':
	    			str_to_print = va_arg(argp, char *);
	    			rc = fputs(str_to_print, stdout);
	    			check(rc != EOF, "Failed to write int.");
	    			break;

	    		default:
		    		sentinel("Invalid format.");
		    }
		} else {
			fputc(fmt[i], stdout);
		}

	}

	va_end(argp);
	return 0;

error:
    return -1;
}

int main(int argc, char const *argv[]) {
	char *first_name = NULL;
	char initial = ' ';
	char *last_name = NULL;
	int age = 0;

	printf("What's your first name? ");
	int rc = read_scan("%s", MAX_DATA, &first_name);
	check(rc == 0, "Failed first name.");

	printf("What's your initial? ");
	rc = read_scan("%c\n", &initial);
	check(rc == 0, "Failed initial.");

	printf("What's your last name? ");
	rc = read_scan("%s", MAX_DATA, &last_name);
	check(rc == 0, "Failed last name.");

	printf("How old are you? ");
	rc = read_scan("%d", &age);

	_printf("---- RESULTS ----\n");
	_printf("First Name: %s\n", first_name);
	_printf("Initial: %c\n", initial);
	_printf("Last Name: %s\n", last_name);
	_printf("Age: %d\n", age);

	free(first_name);
	free(last_name);
	return 0;

error:
	return -1;
}
