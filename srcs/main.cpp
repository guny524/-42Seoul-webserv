#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string>
#include <netdb.h>


#include <iostream>


int main(void)
{
	struct sockaddr *sa;
	char hbuf[NI_MAXHOST], sbuf[NI_MAXSERV];

	if (getnameinfo(sa, sa->sa_len, hbuf, sizeof(hbuf), sbuf, sizeof(sbuf), NI_NUMERICHOST | NI_NUMERICSERV))
		std::cout <<  "could not get numeric hostname" << std::endl;
	std::cout << "host=" << hbuf << ", serv=" << sbuf << std::endl;

	struct sockaddr *sa;
	char hbuf[NI_MAXHOST];

	if (getnameinfo(sa, sa->sa_len, hbuf, sizeof(hbuf), NULL, 0, NI_NAMEREQD))
		std::cout << "could not resolve hostname" << std::endl;
	std::cout << "host=" << hbuf << std::endl;

	// // 소켓 생성
	// struct protoent *a = getprotobyname("ip");
	// int server_socket = socket(PF_INET, SOCK_STREAM, a->p_proto);

	// // 소켓 설정
	// struct sockaddr_in server_addr;
	// memset(&server_addr, 0, sizeof(server_addr));
	// server_addr.sin_family = PF_INET;
	// server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	// server_addr.sin_port = htons(8080);

	// // 소켓 바인딩
	// bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));

	// // 연결 요청 대기
	// listen(server_socket, 5);

	// // TODO 하나의 select, poll만 써야함
	// // TODO poll은 read, write를 동시에 체크해야 함
	// // TODO read, write하고 errno 체크하면 안 됨
	// // TODO config file 읽기 전에는 poll() 사용할 필요 없음
	// while (true) {
	// 	// TODO request가 계속 hang 되면 안 됨
	// 	// 클라이언트 요청 수락
	// 	struct sockaddr_in client_addr;
	// 	socklen_t client_addr_size = sizeof(client_addr);
	// 	int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_size);

	// 	// TODO GET, POST, DELETE
	// 	// TODO uplload file 돼야 함
	// 	// TODO multiple port에서 listen 가능해야 함
	// 	// 클라이언트 요청 처리
	// 	char request[1024];
	// 	read(client_socket, request, sizeof(request)-1);
	// 	std::cout << "Client Request: " << request << std::endl;

	// 	// 응답 전송
	// 	char response[] = "HTTP/1.1 200 OK\n\nHello World!";
	// 	write(client_socket, response, sizeof(response));

	// 	// 소켓 닫기
	// 	close(client_socket);
	// }

	// // 소켓 닫기
	// close(server_socket);

	return 0;
}
