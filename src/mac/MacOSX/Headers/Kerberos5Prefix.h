#include <TargetConditionals.h>
#include <krb5/autoconf.h>

#define USE_CCAPI                    1
#define USE_LOGIN_LIBRARY            1
#define USE_BUNDLE_ERROR_STRINGS     1

#define KRB_PRIVATE                  1
#define KRB5_PRIVATE                 1
#define KRB524_PRIVATE               1

#define GETGROUPS_T                  gid_t
#define GETPEERNAME_ARG2_TYPE        struct sockaddr
#define GETPEERNAME_ARG3_TYPE        int
#define GETSOCKNAME_ARG2_TYPE        struct sockaddr
#define GETSOCKNAME_ARG3_TYPE        int
#define GETSOCKNAME_ARG3_TYPE        int
#define GETSOCKNAME_ARG3_TYPE        int
#define GET_TGT_VIA_PASSWD           1
#define GSSAPI                       1
#define GSSAPI_KRB5                  1
#define GSSAPI_V2                    1
#define HAVE_ACCESS                  1
#define HAVE_ARPA_INET_H             1
#define HAVE_ARPA_NAMESER_H          1
#define HAVE_BT_RSEQ                 1
#define HAVE_CGETENT                 1
#define HAVE_CHMOD                   1
#define HAVE_CLOSELOG                1
#define HAVE_CURSES_H                1
#define HAVE_DAEMON                  1
#define HAVE_FCHMOD                  1
#define HAVE_FCHOWN                  1
#define HAVE_FCNTL_H                 1
#define HAVE_FLOCK                   1
#define HAVE_FORK                    1
#define HAVE_GETADDRINFO             1
#define HAVE_GETCWD                  1
#define HAVE_GETDTABLESIZE           1
#define HAVE_GETENV                  1
#define HAVE_GETEUID                 1
#define HAVE_GETHOSTBYNAME2          1
#define HAVE_GETIFADDRS              1
#define HAVE_GETNAMEINFO             1
#define HAVE_GETOPT                  1
#define HAVE_GETUID                  1
#define HAVE_GETUSERSHELL            1
#define HAVE_HERROR                  1
#define HAVE_IFADDRS_H               1
#define HAVE_INET_ATON               1
#define HAVE_INET_NTOP               1
#define HAVE_INET_PTON               1
#define HAVE_INITGROUPS              1
#define HAVE_INTTYPES_H              1
#define HAVE_ISATTY                  1
#define HAVE_KILLPG                  1
#define HAVE_KRB_GET_ERR_TEXT        1
#define HAVE_KRB_SAVE_CREDENTIALS    1
#define HAVE_LIMITS_H                1
#define HAVE_LOGWTMP                 1
#define HAVE_LSTAT                   1
#define HAVE_MEMMOVE                 1
#define HAVE_MEMORY_H                1
#define HAVE_NETDB_H                 1
#define HAVE_NETINET_IN_H            1
#define HAVE_OPENLOG                 1
#define HAVE_OPENPTY                 1
#define HAVE_PATHS_H                 1
#define HAVE_PWD_H                   1
#define HAVE_REGCOMP                 1
#define HAVE_REGEXEC                 1
#define HAVE_REGEXP_H                1
#define HAVE_REGEX_H                 1
#define HAVE_REVOKE                  1
#define HAVE_RRESVPORT_AF            1
#define HAVE_SA_LEN                  1
#define HAVE_SETENV                  1
#define HAVE_SETEUID                 1
#define HAVE_SETLOGIN                1
#define HAVE_SETOWN                  1
#define HAVE_SETPGID                 1
#define HAVE_SETPRIORITY             1
#define HAVE_SETREUID                1
#define HAVE_SETSID                  1
#define HAVE_SETUPTERM               1
#define HAVE_SRAND                   1
#define HAVE_SRAND48                 1
#define HAVE_SRANDOM                 1
#define HAVE_SSCANF                  1
#define HAVE_STAT                    1
#define HAVE_STDARG_H                1
#define HAVE_STDINT_H                1
#define HAVE_STDLIB_H                1
#define HAVE_STRCASECMP              1
#define HAVE_STRCHR                  1
#define HAVE_STRDUP                  1
#define HAVE_STRERROR                1
#define HAVE_STRFTIME                1
#define HAVE_STRINGS_H               1
#define HAVE_STRING_H                1
#define HAVE_STRPTIME                1
#define HAVE_STRSTR                  1
#define HAVE_STRUCT_SOCKADDR_STORAGE 1
#define HAVE_STRUCT_UTMP_UT_HOST     1
#define HAVE_SYSLOG                  1
#define HAVE_SYSLOG_H                1
#define HAVE_SYS_ERRLIST             1
#define HAVE_SYS_FILIO_H             1
#define HAVE_SYS_IOCTL_COMPAT_H      1
#define HAVE_SYS_PARAM_H             1
#define HAVE_SYS_SELECT_H            1
#define HAVE_SYS_SOCKET_H            1
#define HAVE_SYS_SOCKIO_H            1
#define HAVE_SYS_STAT_H              1
#define HAVE_SYS_TIME_H              1
#define HAVE_SYS_TTY_H               1
#define HAVE_SYS_TYPES_H             1
#define HAVE_SYS_UIO_H               1
#define HAVE_SYS_UTSNAME_H           1
#define HAVE_SYS_WAIT_H              1
#define HAVE_TCGETPGRP               1
#define HAVE_TCSETPGRP               1
#define HAVE_TERM_H                  1
#define HAVE_TIMEZONE                1
#define HAVE_TIME_H                  1
#define HAVE_TTYENT_H                1
#define HAVE_TTYNAME                 1
#define HAVE_UMASK                   1
#define HAVE_UNISTD_H                1
#define HAVE_UNSETENV                1
#define HAVE_UTIL_H                  1
#define HAVE_UTIMES                  1
#define HAVE_UTMP_H                  1
#define HAVE_VFORK                   1
#define HAVE_VFPRINTF                1
#define HAVE_VSNPRINTF               1
#define HAVE_VSPRINTF                1
#define HAVE_WAITPID                 1
#define HAVE_WORKING_FORK            1
#define HAVE_WORKING_VFORK           1
#define HEIMDAL_FRIENDLY             1
#define KADM5                        1
#define KDB4_DISABLE                 1
#define KERBEROS                     1
#define KRB4                         1
#define KRB4_USE_KEYTAB              1
#define KRB5                         1
#define KRB524_PRIVATE               1
#define KRB5_DNS_LOOKUP              0
#define KRB5_DNS_LOOKUP_KDC          0
#define KRB5_KRB4_COMPAT             1
#define KRB5_PRIVATE                 1
#define krb5_sigtype                 void
#define KRB5_USE_INET6               1
#define LINEMODE                     1
#define NEED_DAEMON_PROTO            1
#define NEED_PARSETOS_PROTO          1
#define NEED_SOCKETS                 
#define NO_UT_EXIT                   1
#define NO_UT_PID                    1
#define NO_UT_TYPE                   1
#define NO_YYLINENO                  1
#define POSIX_SETJMP                 1
#define POSIX_SIGNALS                1
#define POSIX_SIGTYPE                1
#define POSIX_TERMIOS                1
#define RETSIGTYPE                   void
#define SETPGRP_TWOARG               1
#define SETRPCENT_TYPE               void
#define STDC_HEADERS                 1
#define SYS_ERRLIST_DECLARED         1
#define TERMCAP                      1
#define TIME_WITH_SYS_TIME           1
#define USE_AUTOCONF_H               1
#define USE_DIRENT_H                 1
#define USE_KADM5_API_VERSION        2
#define USE_MASTER                   1
#define USE_RCACHE                   1
#define USE_SIGPROCMASK              1
#define USE_TERMIO                   1
#define WAIT_USES_INT                1
#define YYTEXT_POINTER               1
