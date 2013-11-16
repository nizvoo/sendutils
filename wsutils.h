/*
  Copyright (C) 2000-2013
  nizvoo (AT) gmail.com
*/

#ifndef __WS_UTILS_H__
#define __WS_UTILS_H__

#include <windows.h>
#include <winsock.h>

#ifdef __cplusplus
extern "C" {
#endif

BOOL init_socket();
BOOL uninit_socket();

SOCKET start_client_connection(const char* addr, short port);

SOCKET start_tcp_server(short port);
SOCKET start_udp_server(short port);

#ifdef __cplusplus
}
#endif

#endif
