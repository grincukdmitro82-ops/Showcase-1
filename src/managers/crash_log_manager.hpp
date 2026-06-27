#pragma once
#include <string>

class CrashLogManager {
protected:
  CrashLogManager() = default;
  bool m_initialized = false;
  void reportLatestCrashLog();

public:
  bool init();
  static CrashLogManager &get() {
    static CrashLogManager instance;
    return instance;
  }
};
