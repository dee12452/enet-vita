/**
 @file  vita.h
 @brief ENet Vita header (courtesy of https://github.com/xyzz/vita-enet)
*/
#ifndef __VITA_ENET_H__
#define __VITA_ENET_H__

#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#ifdef MSG_MAXIOVLEN
#define ENET_BUFFER_MAXIMUM 10
#endif

#ifndef MSG_TRUNC
#define MSG_TRUNC 0x20 /* Unix socket.h MSG_TRUNC */
#endif

typedef int ENetSocket;

#define ENET_SOCKET_NULL (-1)

#define ENET_HOST_TO_NET_16(value) (__builtin_bswap16 (value)) /**< macro that converts host to net byte-order of a 16-bit value */
#define ENET_HOST_TO_NET_32(value) (__builtin_bswap32 (value)) /**< macro that converts host to net byte-order of a 32-bit value */

#define ENET_NET_TO_HOST_16(value) (__builtin_bswap16 (value)) /**< macro that converts net to host byte-order of a 16-bit value */
#define ENET_NET_TO_HOST_32(value) (__builtin_bswap32 (value)) /**< macro that converts net to host byte-order of a 32-bit value */

typedef struct
{
    void * data;
    size_t dataLength;
} ENetBuffer;

#define ENET_CALLBACK

#define ENET_API extern

typedef fd_set ENetSocketSet;

#define ENET_SOCKETSET_EMPTY(sockset)          FD_ZERO (& (sockset))
#define ENET_SOCKETSET_ADD(sockset, socket)    FD_SET (socket, & (sockset))
#define ENET_SOCKETSET_REMOVE(sockset, socket) FD_CLR (socket, & (sockset))
#define ENET_SOCKETSET_CHECK(sockset, socket)  FD_ISSET (socket, & (sockset))

#endif