#include <stdio.h>        // printf(), perror()
#include <sys/types.h>    // AF_INET, SOCK_STREAM
#include <sys/socket.h>   // socket(), connect()
#include <netinet/in.h>   // struct sockaddr_in
#include <arpa/inet.h>    // htons(), inet_addr()
#include <unistd.h>       // close()

//EXEMPLO DE USO ./portscan IP_DO_ALVO

int main(int argc, char *argv[])
{
        int meusocket;
        int conecta;

        int port;
        int inicio = 0;
        int final = 65535;
        char * destino;
        destino = argv[1];

        struct sockaddr_in alvo;

        for(port = inicio; port < final; port++){

                meusocket = socket(AF_INET, SOCK_STREAM, 0);
                alvo.sin_family = AF_INET;
                alvo.sin_port = htons(port);
                alvo.sin_addr.s_addr = inet_addr(destino);

                conecta = connect(meusocket, (struct sockaddr *)&alvo, sizeof alvo);

                if(conecta == 0) 
                {
                        printf("Porta %d - status [ABERTA] \n",port);
                        close(meusocket);
                        close(conecta);
                }else {
                        close(meusocket);
                        close(conecta);
                }
        }
}
