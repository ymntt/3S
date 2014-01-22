/* tinyHttpd.c
 * Tiny Hyper Text Transfer Protocol Daemon
 * daemon version */

#define BUFMAX 256
#define Err(x) { fprintf( stderr, "server- "); perror(x); exit(0); }

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char rmsg[BUFMAX], smsg[BUFMAX];
static int sofd, nsofd;
static struct sockaddr_in sv_addr, cl_addr;
static struct hostent * shost;
static char shostname[256];

void httppro();
struct info * get_com();

struct info {
  char com[8];
  char file[128];
  char prot[8];
};

int main(int argc, char * argv[]) {
  char * * arguments;
  int cadlen;
  int PORT_NO;

  if(argc == 2) PORT_NO = atoi(argv[1]);
  else Err("portnumber (over 5001, under 65535)is required");

  sofd = socket(AF_INET, SOCK_STREAM, 0);
  if( sofd < 0 ) Err("socket");

  if( gethostname( shostname, sizeof(shostname)) < 0 ) Err("gethostname");
  
  shost = (struct hostent *)gethostbyname(shostname);
  if(shost == NULL) Err("gethostbyname");

  bzero((char *) &sv_addr, sizeof(sv_addr));
  sv_addr.sin_family = AF_INET;
  sv_addr.sin_port = htons(PORT_NO);
  memcpy((char *)&sv_addr.sin_addr,
	 (char *) shost->h_addr,
	 shost->h_length);
  if( bind(sofd, (struct sockaddr *)&sv_addr, sizeof(sv_addr)) <0 ) Err("bind");

  if( listen( sofd, 5) == -1) Err("listen");

  while(1) {
    cadlen = sizeof(cl_addr);
    if( (nsofd = accept(sofd, (struct sockaddr *)&cl_addr, &cadlen)) < 0) Err("accept");

    signal(SIGCLD,SIG_IGN);

    if( fork() == 0 ) httppro();
    else close(nsofd);

  }
}

void httppro()
{
  int cc, cadlen, nbyte;
  FILE * fp;
  char * rmsg2;
  struct info * uri;

  rmsg2 = (char *) malloc(BUFMAX);

  close(sofd);

  if( recv( nsofd, rmsg, BUFMAX, 0) < 0 ) perror("recv1"); /* GET ... HTTP/1.0に対応 */
  if( recv( nsofd, rmsg2, BUFMAX, 0) < 0 ) perror("recv2"); /* 改行に対応 */

  uri = get_com(rmsg); /* 入力された行をURIへ変換する 下で定義している */

  fp = fopen(uri->file, "r");
  if(fp == NULL) {

    strcpy(smsg,"HTTP/1.0 200 OK\nMIME-Version:1.0\nServer: thttpd/1.0\nContent-Type: text/html\n\n<HTML><H1>File Does not Exist</H1></HTML>");
    nbyte=strlen(smsg);
    
    if( send(nsofd, smsg, nbyte, 0) < 0 ) perror("send");

  } else {

    strcpy(smsg,"HTTP/1.0 200 OK\nMIME-Version:1.0\nServer: thttpd/1.0\nContent-Type: text/html\n\n");
    nbyte=strlen(smsg);

    if( send(nsofd, smsg, nbyte, 0) < 0 ) perror("send");

    while( fgets(smsg, BUFMAX, fp) != NULL ) {
      nbyte = strlen(smsg);
      if( send(nsofd, smsg, nbyte, 0) < 0 ) perror("send");
    }
    fclose(fp);

  }
  if (shutdown(nsofd, 2) < 0) Err("shutdown");
  close(nsofd);
  exit(0);
}




struct info *get_com(char *str)
{
  struct info * uri;
  char *com,*file,*D=" ",*e_com="GET",*e_file="error.html",*c_file;
  uri=(struct info *) malloc(sizeof(struct info));

  /* デバッグ用にブラウザからの文字列をstderrへ出す */
  fprintf(stderr,"get_com() gets %s\n",str);

  /* 最初の文字列がGETであれば，GETで要求が来ている受理可能なパターン*/
  if (((com=strsep(&str,D))!=NULL) && ((strcmp(com,"GET"))==0)) {
    fprintf(stderr,"get_com() first:%s\n",com);
    strcpy(uri->com,com);
  } else {
    /* 最初の文字列がGET以外であれば，エラーにする．*/
    strcpy(uri->com,"GET");
    strcpy(uri->file,e_file);
    strcpy(uri->prot,"HTTP/1.0");
    return uri;
  }

  if ((file=strsep(&str,D))!=NULL) {
    fprintf(stderr,"success second:%s\n",file);
    /*ファイル名が取れたら，構造体にセットして返す．*/
    /* 先頭に/が付いているので，取り除く */
    c_file=(char *)malloc(sizeof(strlen(file)));
    file++; /* 一文字進めた（＝＝先頭の'/'を飛ばした) */
    strcpy(c_file,file);
    strcpy(uri->file,c_file);
    strcpy(uri->prot,"HTTP/1.0");
    return uri;
  } else {
    /* GETに続く文字列が取れないときにも，エラーにする．*/
    fprintf(stderr,"fail second:%s\n",file);
    strcpy(uri->com,"GET");
    strcpy(uri->file,e_file);
    strcpy(uri->prot,"HTTP/1.0");
    return uri;
  }
  /* ここまで来ることは無いはずだが，エラー避けに入れてある．*/
  strcpy(uri->com,"GET");
  strcpy(uri->file,e_file);
  strcpy(uri->prot,"HTTP/1.0");
  return uri;
}
