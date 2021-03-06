#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <zmq.h>

int main(void) {

  void *context = zmq_ctx_new();
  void *publisher = zmq_socket(context, ZMQ_PUB);
  zmq_bind(publisher, "tcp://*:5555");
  char buffer[30] = {};

  while (1) {
    sprintf_s(buffer, "%d %0.4f ", 10001, 3.21);
    zmq_send(publisher, buffer, 30, 0);
    std::cout << "Pubishing...\n" << buffer << std::endl;
  }
  zmq_close(publisher);
  zmq_ctx_destroy(context);

  return 0;
}
