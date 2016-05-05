#include <stdio.h>
#include <dlfcn.h>
#include "../src/dbg.h"

#define LIB_FILE "build/libex29.so"

typedef int (*lib_function)(const char *data, int len);

int main(int argc, char const *argv[]) {
	int rc = 0;

	void *lib = dlopen(LIB_FILE, RTLD_NOW);
	check(lib != NULL, "Failed to open the library %s: %s.", LIB_FILE, dlerror());

	rc = exec(lib, "uppercase");
	check(rc == 0, "Failed to execute uppercase");

	rc = dlclose(lib);
	check(rc == 0, "Failed to close %s", LIB_FILE);

	return 0;

error:
	return 1;
}

int exec(void* lib, char* func_to_run, char* data) {
	int len = strlen(data);
	int rc = 0;

	lib_function func = dlsym(lib, func_to_run);
	check(func != NULL, "Did not fund %s function in the library %s: %s", func_to_run, LIB_FILE, dlerror());

	rc = func(data, len);
	check(rc == 0, "Function %s return %d for data: %s.", func_to_run, rc, data);

	return rc;

error:
	return 1;
}