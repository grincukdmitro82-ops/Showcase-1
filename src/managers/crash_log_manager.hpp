#pragma once
#include <Geode/Geode.hpp>
#include "../tasks/report_crash_log.hpp"

using namespace geode::prelude;

class CrashLogManager {
protected:
  CrashLogManager() = default;
  bool m_initialized = false;
  EventListener<ReportCrashLogTask> m_reportCrashLogListener;
  void reportLatestCrashLog();

public:
  bool init();
  static CrashLogManager &get() {
    static CrashLogManager instance;
    return instance;
  }
};
