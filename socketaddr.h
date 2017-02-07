
/* Socket address */
struct sockaddr_in {
  sa_family_t sin_family; /* address family: AF_INET (tipicamente)*/
  u_int16_t sin_port; /* port in network byte order */
  struct in_addr sin_addr; /* internet adress */
} sockaddr_in;

struct in_addr {
  u_int32_t s_addr; /* 32 bit address in network byte order */
};
