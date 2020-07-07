/**
 * DESCRIPTION
 *   This file has been added to be able to utilize a combination of new and old features
 *   while retaining compatibility of the software for all currently used versions.
 */
#ifndef COMPATIBILITY_H
#define COMPATIBILITY_H

// Since Qt 5.13
#ifndef Q_DISABLE_MOVE
#   if __cplusplus >= 201402L
#       define Q_DISABLE_MOVE(Class) \
            Class(Class&&); \
            Class& operator=(Class&&)
#   else
#       define Q_DISABLE_MOVE(Class)
#   endif
#endif

// Since Qt 5.13
#ifndef Q_DISABLE_COPY_MOVE
#    define Q_DISABLE_COPY_MOVE(Class) \
        Q_DISABLE_COPY(Class); \
        Q_DISABLE_MOVE(Class)
#endif

#endif // COMPATIBILITY_H
