/*
  Copyright (C) 2000-2013
	zhangyong.ni@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>

#include "wsutils.h"

#define BUF_LEN (512)

static 
int test_tcp_client(const char* ip, short port)
{
  char buf[BUF_LEN];
  SOCKET s;
  int i;
  int len;
  int result;

  sprintf(buf, "%s", "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");

  s = start_client_connection(ip, port);
  if (s == SOCKET_ERROR || s == INVALID_SOCKET) {
    printf("%d connecting failed\n", WSAGetLastError());
    return -1;
  } 

  for (i = 0; i < 32; ++i) {
    len = strlen(buf);
    result = send(s, buf, len,  0);

    fprintf(stdout, "%d -> Send result %d\n", i, result);

    if (result == -1) {
      fprintf(stdout, "%d -> Send message failed.\n", i);
      break;
    }

    recv(s, buf, len, 0);

    fprintf(stdout, "%s\n", buf);

    Sleep(5);

  }
  closesocket(s);

  return 0;
}


int main(int argc, char* argv[])
{	
	char ip[MAX_PATH + 1] = "192.168.1.108";
	short port = 8000;
	if (argc > 2) {
		_snprintf(ip, MAX_PATH, "%s", argv[1]);
		port = atoi(argv[2]);
	} else if (argc > 1) {
		_snprintf(ip, MAX_PATH, "%s", argv[1]);
	} else {
		printf("Usage: sendutils.exe IP PORT\n");
		return -1;
	}
	printf("User enter IP:%s, PORT:%d\n", ip, port);
	
	init_socket();
	
	test_tcp_client(ip, port);
	
    uninit_socket();	
	return 0;
}