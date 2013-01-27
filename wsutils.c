#include "wsutils.h"

BOOL init_socket()
{
  WSADATA rWSAData = {0};
  int nStatus = WSAStartup(MAKEWORD(2,2), &rWSAData);
  
  if (nStatus != 0)	{
    return FALSE;
  }
  
  return TRUE;
}

BOOL uninit_socket()
{
  WSACleanup();
  
  return TRUE;
}

SOCKET start_client_connection(const char* addr, short port)
{
  SOCKET      s;
  SOCKADDR_IN server_addr;

  memset(&server_addr, 0x00, sizeof(server_addr));

  server_addr.sin_family           = AF_INET;
  server_addr.sin_addr.S_un.S_addr = inet_addr(addr);
  server_addr.sin_port             = htons(port);

  s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  if (s != INVALID_SOCKET)	{
    int r = connect(s, (LPSOCKADDR)&server_addr, sizeof(server_addr));

    if (r == SOCKET_ERROR) {
      closesocket(s);
      s = SOCKET_ERROR;
    }
  }

  return s;
}
