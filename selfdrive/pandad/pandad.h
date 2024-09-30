#pragma once

#include <string>
#include <vector>

<<<<<<< HEAD
#include "selfdrive/pandad/panda.h"

bool safety_setter_thread(std::vector<Panda *> pandas);
void pandad_main_thread(std::vector<std::string> serials);
=======
#include "common/params.h"
#include "selfdrive/pandad/panda.h"

void pandad_main_thread(std::vector<std::string> serials);

class PandaSafety {
public:
  PandaSafety(const std::vector<Panda *> &pandas) : pandas_(pandas) {}
  void configureSafetyMode();

private:
  void updateMultiplexingMode();
  std::string fetchCarParams();
  void setSafetyMode(const std::string &params_string);

  bool initialized_ = false;
  bool log_once_ = false;
  bool safety_configured_ = false;
  bool prev_obd_multiplexing_ = false;
  std::vector<Panda *> pandas_;
  Params params_;
};
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
