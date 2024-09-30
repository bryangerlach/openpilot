<<<<<<< HEAD
#include <algorithm>
#include <cassert>
#include <csignal>
#include <iostream>
#include <map>
#include <string>

typedef void (*sighandler_t)(int sig);

#include "cereal/services.h"
#include "msgq/impl_msgq.h"
#include "msgq/impl_zmq.h"

std::atomic<bool> do_exit = false;
static void set_do_exit(int sig) {
  do_exit = true;
}

void sigpipe_handler(int sig) {
  assert(sig == SIGPIPE);
  std::cout << "SIGPIPE received" << std::endl;
}
=======
#include <cassert>

#include "cereal/messaging/msgq_to_zmq.h"
#include "cereal/services.h"
#include "common/util.h"

ExitHandler do_exit;
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

static std::vector<std::string> get_services(std::string whitelist_str, bool zmq_to_msgq) {
  std::vector<std::string> service_list;
  for (const auto& it : services) {
    std::string name = it.second.name;
    bool in_whitelist = whitelist_str.find(name) != std::string::npos;
    if (name == "plusFrame" || name == "uiLayoutState" || (zmq_to_msgq && !in_whitelist)) {
      continue;
    }
    service_list.push_back(name);
  }
  return service_list;
}

<<<<<<< HEAD
int main(int argc, char** argv) {
  signal(SIGPIPE, (sighandler_t)sigpipe_handler);
  signal(SIGINT, (sighandler_t)set_do_exit);
  signal(SIGTERM, (sighandler_t)set_do_exit);

  bool zmq_to_msgq = argc > 2;
  std::string ip = zmq_to_msgq ? argv[1] : "127.0.0.1";
  std::string whitelist_str = zmq_to_msgq ? std::string(argv[2]) : "";

  Poller *poller;
  Context *pub_context;
  Context *sub_context;
  if (zmq_to_msgq) {  // republishes zmq debugging messages as msgq
    poller = new ZMQPoller();
    pub_context = new MSGQContext();
    sub_context = new ZMQContext();
  } else {
    poller = new MSGQPoller();
    pub_context = new ZMQContext();
    sub_context = new MSGQContext();
  }

  std::map<SubSocket*, PubSocket*> sub2pub;
  for (auto endpoint : get_services(whitelist_str, zmq_to_msgq)) {
    PubSocket * pub_sock;
    SubSocket * sub_sock;
    if (zmq_to_msgq) {
      pub_sock = new MSGQPubSocket();
      sub_sock = new ZMQSubSocket();
    } else {
      pub_sock = new ZMQPubSocket();
      sub_sock = new MSGQSubSocket();
    }
    pub_sock->connect(pub_context, endpoint);
    sub_sock->connect(sub_context, endpoint, ip, false);
=======
void msgq_to_zmq(const std::vector<std::string> &endpoints, const std::string &ip) {
  MsgqToZmq bridge;
  bridge.run(endpoints, ip);
}

void zmq_to_msgq(const std::vector<std::string> &endpoints, const std::string &ip) {
  auto poller = std::make_unique<ZMQPoller>();
  auto pub_context = std::make_unique<MSGQContext>();
  auto sub_context = std::make_unique<ZMQContext>();
  std::map<SubSocket *, PubSocket *> sub2pub;

  for (auto endpoint : endpoints) {
    auto pub_sock = new MSGQPubSocket();
    auto sub_sock = new ZMQSubSocket();
    pub_sock->connect(pub_context.get(), endpoint);
    sub_sock->connect(sub_context.get(), endpoint, ip, false);
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

    poller->registerSocket(sub_sock);
    sub2pub[sub_sock] = pub_sock;
  }

  while (!do_exit) {
    for (auto sub_sock : poller->poll(100)) {
<<<<<<< HEAD
      Message * msg = sub_sock->receive();
      if (msg == NULL) continue;
      int ret;
      do {
        ret = sub2pub[sub_sock]->sendMessage(msg);
      } while (ret == -1 && errno == EINTR && !do_exit);
      assert(ret >= 0 || do_exit);
      delete msg;

      if (do_exit) break;
    }
  }
=======
      std::unique_ptr<Message> msg(sub_sock->receive(true));
      if (msg) {
        sub2pub[sub_sock]->sendMessage(msg.get());
      }
    }
  }

  // Clean up allocated sockets
  for (auto &[sub_sock, pub_sock] : sub2pub) {
    delete sub_sock;
    delete pub_sock;
  }
}

int main(int argc, char **argv) {
  bool is_zmq_to_msgq = argc > 2;
  std::string ip = is_zmq_to_msgq ? argv[1] : "127.0.0.1";
  std::string whitelist_str = is_zmq_to_msgq ? std::string(argv[2]) : "";
  std::vector<std::string> endpoints = get_services(whitelist_str, is_zmq_to_msgq);

  if (is_zmq_to_msgq) {
    zmq_to_msgq(endpoints, ip);
  } else {
    msgq_to_zmq(endpoints, ip);
  }
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  return 0;
}
