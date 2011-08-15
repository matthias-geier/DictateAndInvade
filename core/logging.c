

#include <logging.h>

void core_vlog(const char *fmt, va_list argp) {
    vprintf(fmt, argp);
    printf("\n");
}

void core_log(const char *fmt, ...) {
    va_list argp;
    va_start(argp, fmt);
    core_vlog(fmt, argp);
    va_end(argp);
}
