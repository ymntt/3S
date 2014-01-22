/* -*- Coding: utf-8-unix -*-
 * udp-broadcat-utf-8-receive.c
 *
 *
 * http://www.geekpage.jp/programming/linux-network/udp.php
 * modifiy for UTF-8
 */
#include <stdio.h>
#include <string.h> /* add this */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void)
{
 int sock;
 struct sockaddr_in addr;

 char buf[2048];

 sock = socket(AF_INET, SOCK_DGRAM, 0);

 addr.sin_family = AF_INET;
 addr.sin_port = htons(12345);
 addr.sin_addr.s_addr = INADDR_ANY;

 bind(sock, (struct sockaddr *)&addr, sizeof(addr));

 while (1) {
   memset(buf, 0, sizeof(buf));
   recv(sock, buf, sizeof(buf), 0);
   printf("%s\n", buf);
 }

 close(sock);
 return 0;
}
