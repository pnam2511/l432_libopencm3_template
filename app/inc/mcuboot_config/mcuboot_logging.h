#ifndef __MCUBOOT_LOGGING_H__
#define __MCUBOOT_LOGGING_H__

// #include <syscfg/syscfg.h>
#include <stdio.h>

#define MCUBOOT_LOG_LEVEL_OFF      1
#define MCUBOOT_LOG_LEVEL_ERROR    2
#define MCUBOOT_LOG_LEVEL_WARNING  3
#define MCUBOOT_LOG_LEVEL_INFO     4
#define MCUBOOT_LOG_LEVEL_DEBUG    5

#ifndef MCUBOOT_LOG_LEVEL
 #define MCUBOOT_LOG_LEVEL MCUBOOT_LOG_LEVEL_OFF
#endif


#if !((MCUBOOT_LOG_LEVEL >= MCUBOOT_LOG_LEVEL_OFF) && \
      (MCUBOOT_LOG_LEVEL <= MCUBOOT_LOG_LEVEL_DEBUG))
#error "Invalid MCUBOOT_LOG_LEVEL config."
#endif

#if MCUBOOT_LOG_LEVEL >= MCUBOOT_LOG_LEVEL_ERROR
#define MCUBOOT_LOG_ERR(_fmt, ...)                                      \
    do {                                                                \
        printf("[ERR] " _fmt "\n", ##__VA_ARGS__);                      \
    } while (0)
#else
#define MCUBOOT_LOG_ERR(...) IGNORE(__VA_ARGS__)
#endif

#if MCUBOOT_LOG_LEVEL >= MCUBOOT_LOG_LEVEL_WARNING
#define MCUBOOT_LOG_WRN(_fmt, ...)                                      \
    do {                                                                \
        printf("[WRN] " _fmt "\n", ##__VA_ARGS__);                      \
    } while (0)
#else
#define MCUBOOT_LOG_WRN(...) IGNORE(__VA_ARGS__)
#endif

#if MCUBOOT_LOG_LEVEL >= MCUBOOT_LOG_LEVEL_INFO
#define MCUBOOT_LOG_INF(_fmt, ...)                                      \
    do {                                                                \
        printf("[INF] " _fmt "\n", ##__VA_ARGS__);                      \
    } while (0)
#else
#define MCUBOOT_LOG_INF(...) IGNORE(__VA_ARGS__)
#endif

#if MCUBOOT_LOG_LEVEL >= MCUBOOT_LOG_LEVEL_DEBUG
#define MCUBOOT_LOG_DBG(_fmt, ...)                                      \
    do {                                                                \
        printf("[DBG] " _fmt "\n", ##__VA_ARGS__);                      \
    } while (0)
#else
#define MCUBOOT_LOG_DBG(...) IGNORE(__VA_ARGS__)
#endif

#define MCUBOOT_LOG_SIM(...) IGNORE(__VA_ARGS__)

#endif
