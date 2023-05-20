#ifndef __CONFIG_HPP__
#define __CONFIG_HPP__

#include <string>

// TODO config file argument로 받아와야 함 or default path
// TODO default error pages가 있어야 함
// TODO static website 가 되야 함
// TODO upload file 돼야 함
// TODO GET, POST, DELETE
// TODO multiple port에서 listen 가능해야 함

// TODO 각 server마다 port, host를 설정할 수 있어야 함
// TODO server name 설정
// TODO 첫 host:port가 default 임
// TODO default error page

// routes == location
	// TODO define list of accepted HTTP methods for the route
	// TODO HTTP redirection
	// TODO root directory and uri
	// TODO turn on off directory listing
	// TODO request가 directory인 경우 기본 응답 file 지정
	// TODO 특정 file extension에 따른 cgi
	// TODO upload file이 어디에 저장되어야 하는지
// cgi
	// TODO PATH_INFO로 full path 지정

class Config
{
private:
	const std::string file_path;


public:

};

#endif
