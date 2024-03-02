
#include "s21_string.h"

size_t s21_strlen(const char *str) {
  size_t i = 0;
  for (; *(str + i) != '\0'; i++) {
  }
  return i;
}

void *s21_memchr(const void *str, int c, size_t n) {
  void *res = NULL;
  int i = 0;
  if (str != NULL) {
    while (--n && *(char *)(str + i) != c && *(char *)(str + i) != '\0') {
      i++;
    }
    if (*(char *)(str + i) == c) res = (void *)(str + i);
  }
  return res;
}

int s21_memcmp(const void *str1, const void *str2, size_t n) {
  int result = 0;

  for (size_t i = 0; i < n; i++) {
    int symbol1 = *((char *)str1 + i);
    int symbol2 = *((char *)str2 + i);

    symbol1 = (symbol1 == '\0') ? -1 : symbol1;
    symbol2 = (symbol2 == '\0') ? -1 : symbol2;

    if (symbol1 != symbol2) {
      result = symbol1 > symbol2 ? 1 : -1;
      break;
    }
  }

  return result;
}

void *s21_memcpy(void *dest, const void *src, size_t n) {
  char *goal = (char *)dest;
  const char *source = (const char *)src;
  while (n--) {
    *(goal++) = *(source++);
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *dest = (char *)str;
  while (n--) {
    *(dest++) = c;
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, size_t n) {
  char *ptr = dest + strlen(dest);
  //        printf("%c\n", *ptr);

  while (*src != '\0' && n--) {
    *ptr++ = *src++;
  }

  *ptr = '\0';

  return dest;
}

size_t s21_strcspn(const char *str1, const char *str2) {
  size_t i = 0;
  size_t found_match = 0;

  for (; i < s21_strlen(str1); i++) {
    for (size_t j = 0; j < s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        found_match++;
        break;
      }
    }
    if (found_match) {
      break;
    }
  }
  return i;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = NULL;
  int i = 0;
  int j;
  while (res == NULL && *(str1 + i)) {
    j = 0;
    while (*(str2 + j) != '\0' && *(str2 + j) != *(str1 + i)) {
      j++;
    }
    if (*(str1 + i) == *(str2 + j)) res = (char *)(str1 + i);
    i++;
  }
  return res;
}

char *s21_strchr(const char *str, int c) {
  char *ptr = NULL;
  size_t i = 0;
  size_t size = s21_strlen(str);

  if (c == '\0') {
    ptr = (char *)str + size;
  } else {
    for (; i < size; i++) {
      if (str[i] == c) {
        ptr = (char *)str + i;
        break;
      }
    }
  }

  return ptr;
}

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  int result = 0;

  for (size_t i = 0; i < n; i++) {
    if (*(char *)(str1 + i) - *(char *)(str2 + i) != 0) {
      result = (*(char *)(str1 + i) > *(char *)(str2 + i)) ? 1 : -1;
      break;
    }
  }

  return result;
}

char *s21_strncpy(char *dest, const char *src, size_t n) {
  char *res = dest;
  while (n--) {
    *dest++ = *src;
    if (*src) src++;
  }
  return res;
}

char *s21_strrchr(const char *str, int c) {
  char *ptr = NULL;
  size_t size = s21_strlen(str);

  if (c == '\0') {
    ptr = (char *)str + size;
  } else {
    for (size_t i = 0; i < size; i++) {
      if (*(char *)(str + i) == c) {
        ptr = (char *)(str + i);
      }
    }
  }
  return ptr;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *ptr = NULL;

  size_t size1 = strlen(haystack);
  size_t size2 = strlen(needle);
  for (size_t i = 0; i < size1; i++) {
    if (!s21_strncmp((char *)haystack + i, (char *)needle, size2)) {
      ptr = (char *)haystack + i;
      break;
    }
  }

  return ptr;
}

char *s21_strtok(char *src, const char *delim) {
  char *res = NULL;
  static char *current = NULL;
  if (src != NULL && *src) {
    res = src;
    if ((current = s21_strpbrk(src, delim))) *(current++) = '\0';
  } else if (src == NULL && current) {
    res = current;
    for (; s21_strpbrk(res, delim) == res; res++)
      ;
    if ((current = s21_strpbrk(res, delim))) {
      *(current++) = '\0';
    } else if (!*res) {
      res = NULL;
    }
  }
  return res;
}

char *s21_strerror(int errnum) {
#ifdef __APPLE__
#define SIZE_ARR_ERR 106
#define U_ERR "Unknown error:"
  static const char *errors_array[] = {
      "Undefined error: 0",
      "Operation not permitted",
      "No such file or directory",
      "No such process",
      "Interrupted system call",
      "Input/output error",
      "Device not configured",
      "Argument list too long",
      "Exec format error",
      "Bad file descriptor",
      "No child processes",
      "Resource deadlock avoided",
      "Cannot allocate memory",
      "Permission denied",
      "Bad address",
      "Block device required",
      "Resource busy",
      "File exists",
      "Cross-device link",
      "Operation not supported by device",
      "Not a directory",
      "Is a directory",
      "Invalid argument",
      "Too many open files in system",
      "Too many open files",
      "Inappropriate ioctl for device",
      "Text file busy",
      "File too large",
      "No space left on device",
      "Illegal seek",
      "Read-only file system",
      "Too many links",
      "Broken pipe",
      "Numerical argument out of domain",
      "Result too large",
      "Resource temporarily unavailable",
      "Operation now in progress",
      "Operation already in progress",
      "Socket operation on non-socket",
      "Destination address required",
      "Message too long",
      "Protocol wrong type for socket",
      "Protocol not available",
      "Protocol not supported",
      "Socket type not supported",
      "Operation not supported",
      "Protocol family not supported",
      "Address family not supported by protocol family",
      "Address already in use",
      "Can't assign requested address",
      "Network is down",
      "Network is unreachable",
      "Network dropped connection on reset",
      "Software caused connection abort",
      "Connection reset by peer",
      "No buffer space available",
      "Socket is already connected",
      "Socket is not connected",
      "Can't send after socket shutdown",
      "Too many references: can't splice",
      "Operation timed out",
      "Connection refused",
      "Too many levels of symbolic links",
      "File name too long",
      "Host is down",
      "No route to host",
      "Directory not empty",
      "Too many processes",
      "Too many users",
      "Disc quota exceeded",
      "Stale NFS file handle",
      "Too many levels of remote in path",
      "RPC struct is bad",
      "RPC version wrong",
      "RPC prog. not avail",
      "Program version wrong",
      "Bad procedure for program",
      "No locks available",
      "Function not implemented",
      "Inappropriate file type or format",
      "Authentication error",
      "Need authenticator",
      "Device power is off",
      "Device error",
      "Value too large to be stored in data type",
      "Bad executable (or shared library)",
      "Bad CPU type in executable",
      "Shared library version mismatch",
      "Malformed Mach-o file",
      "Operation canceled",
      "Identifier removed",
      "No message of desired type",
      "Illegal byte sequence",
      "Attribute not found",
      "Bad message",
      "EMULTIHOP (Reserved)",
      "No message available on STREAM",
      "ENOLINK (Reserved)",
      "No STREAM resources",
      "Not a STREAM",
      "Protocol error",
      "STREAM ioctl timeout",
      "Operation not supported on socket",
      "Policy not found",
      "State not recoverable",
      "Previous owner died",
      "Interface output queue is full"};
#elif __linux__
#define SIZE_ARR_ERR 133
#define U_ERR "Unknown error"
  static const char *errors_array[] = {
      "Success",
      "Operation not permitted",
      "No such file or directory",
      "No such process",
      "Interrupted system call",
      "Input/output error",
      "No such device or address",
      "Argument list too long",
      "Exec format error",
      "Bad file descriptor",
      "No child processes",
      "Resource temporarily unavailable",
      "Cannot allocate memory",
      "Permission denied",
      "Bad address",
      "Block device required",
      "Device or resource busy",
      "File exists",
      "Invalid cross-device link",
      "No such device",
      "Not a directory",
      "Is a directory",
      "Invalid argument",
      "Too many open files in system",
      "Too many open files",
      "Inappropriate ioctl for device",
      "Text file busy",
      "File too large",
      "No space left on device",
      "Illegal seek",
      "Read-only file system",
      "Too many links",
      "Broken pipe",
      "Numerical argument out of domain",
      "Numerical result out of range",
      "Resource deadlock avoided",
      "File name too long",
      "No locks available",
      "Function not implemented",
      "Directory not empty",
      "Too many levels of symbolic links",
      "Unknown error 41",
      "No message of desired type",
      "Identifier removed",
      "Channel number out of range",
      "Level 2 not synchronized",
      "Level 3 halted",
      "Level 3 reset",
      "Link number out of range",
      "Protocol driver not attached",
      "No CSI structure available",
      "Level 2 halted",
      "Invalid exchange",
      "Invalid request descriptor",
      "Exchange full",
      "No anode",
      "Invalid request code",
      "Invalid slot",
      "Unknown error 58",
      "Bad font file format",
      "Device not a stream",
      "No data available",
      "Timer expired",
      "Out of streams resources",
      "Machine is not on the network",
      "Package not installed",
      "Object is remote",
      "Link has been severed",
      "Advertise error",
      "Srmount error",
      "Communication error on send",
      "Protocol error",
      "Multihop attempted",
      "RFS specific error",
      "Bad message",
      "Value too large for defined data type",
      "Name not unique on network",
      "File descriptor in bad state",
      "Remote address changed",
      "Can not access a needed shared library",
      "Accessing a corrupted shared library",
      ".lib section in a.out corrupted",
      "Attempting to link in too many shared libraries",
      "Cannot exec a shared library directly",
      "Invalid or incomplete multibyte or wide character",
      "Interrupted system call should be restarted",
      "Streams pipe error",
      "Too many users",
      "Socket operation on non-socket",
      "Destination address required",
      "Message too long",
      "Protocol wrong type for socket",
      "Protocol not available",
      "Protocol not supported",
      "Socket type not supported",
      "Operation not supported",
      "Protocol family not supported",
      "Address family not supported by protocol",
      "Address already in use",
      "Cannot assign requested address",
      "Network is down",
      "Network is unreachable",
      "Network dropped connection on reset",
      "Software caused connection abort",
      "Connection reset by peer",
      "No buffer space available",
      "Transport endpoint is already connected",
      "Transport endpoint is not connected",
      "Cannot send after transport endpoint shutdown",
      "Too many references: cannot splice",
      "Connection timed out",
      "Connection refused",
      "Host is down",
      "No route to host",
      "Operation already in progress",
      "Operation now in progress",
      "Stale file handle",
      "Structure needs cleaning",
      "Not a XENIX named type file",
      "No XENIX semaphores available",
      "Is a named type file",
      "Remote I/O error",
      "Disk quota exceeded",
      "No medium found",
      "Wrong medium type",
      "Operation canceled",
      "Required key not available",
      "Key has expired",
      "Key has been revoked",
      "Key was rejected by service",
      "Owner died",
      "State not recoverable",
      "Operation not possible due to RF-kill",
      "Memory page has hardware error"};
#endif
  static char rtn[61] = "";
  if (errnum < 0 || errnum > SIZE_ARR_ERR) {
    sprintf(rtn, "%s %d", U_ERR, errnum);  // поменять на s21_sprintf
  } else {
    for (int i = 0; i < 60; i++) {
      rtn[i] = '0';
    }
    rtn[60] = '\0';
    s21_strncpy(rtn, errors_array[errnum], 60);
  }
  return rtn;
}

size_t s21_strspn(const char *str1,
                  const char *str2) {  // вынести в отдельные файлы
  int stop_flag = 1;
  int count_n = 0;

  if (str2 != 0) {
    for (int i = 0; str1[i] != '\0'; i++) {
      for (int j = 0; str2[j] != '\0'; j++) {
        if (str1[i] == str2[j]) {
          stop_flag = 0;
          count_n++;
          break;
        }
      }
      if (stop_flag) {
        break;
      }
      stop_flag = 1;
    }
  }
  return count_n;
}

char *s21_strcpy(char *dest, const char *src) {
  for (size_t i = 0; i < s21_strlen(src) + 1; i++) {
    dest[i] = src[i];
  }

  //  dest[s21_strlen(src)] = '\0';

  return dest;
}
