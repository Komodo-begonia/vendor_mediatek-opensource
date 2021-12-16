#ifndef __LIBS_LOGWRAP_H
#define __LIBS_LOGWRAP_H

#include <stdbool.h>
#include <stdint.h>

__BEGIN_DECLS

/* Values for the log_target parameter android_fork_execvp_ext() */
#define LOG_NONE        0
#define LOG_ALOG        1
#define LOG_KLOG        2
#define LOG_FILE        4

// TODO: Remove unused_opts / unused_opts_len in a followup change.
int android_fork_execvp_ext(int argc, char* argv[], int *status, bool ignore_int_quit,
        int log_target, bool abbreviated, char *file_path, void* unused_opts,
        int unused_opts_len);

/* Similar to above, except abbreviated logging is not available, and if logwrap
 * is true, logging is to the Android system log, and if false, there is no
 * logging.
 */
static inline int android_fork_execvp(int argc, char* argv[], int *status,
                                     bool ignore_int_quit, bool logwrap)
{
    return android_fork_execvp_ext(argc, argv, status, ignore_int_quit,
                                   (logwrap ? LOG_ALOG : LOG_NONE), false, NULL,
                                   NULL, 0);
}

__END_DECLS

#endif /* __LIBS_LOGWRAP_H */
