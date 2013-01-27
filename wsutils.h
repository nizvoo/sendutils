#ifndef __WS_UTILS_H__
#define __WS_UTILS_H__

#include <Windows.h>
#include <winsock.h>

BOOL init_socket();
BOOL uninit_socket();

SOCKET start_client_connection(const char* addr, short port);

#endif