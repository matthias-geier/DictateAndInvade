

#ifndef LOGGING_H
#define	LOGGING_H

#define LOGGING_FLAG 1

#include <stdio.h>
#include <stdarg.h>


/**
 * logging for va_lists
 * 
 * @param fmt:                  string with place holders
 * @param argp:                 argument list
 */
void core_vlog(const char *fmt, va_list argp);



/**
 * logging for variable parameters
 * 
 * @param fmt:                  string with place holders
 * @param ...:                  arguments
 */
void core_log(const char *fmt, ...);


#endif	/* LOGGING_H */

