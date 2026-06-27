#pragma once
#include <filesystem>
#include <functional>
#include <optional>
#include <string>
#include <vector>

class APIManager {
protected:
  APIManager() = default;
  APIManager(const APIManager &) = delete;
  APIManager(APIManager &&) = delete;
  APIManager &operator=(const APIManager &) = delete;
  APIManager &operator=(APIManager &&) = delete;

  bool m_initialized = false;
  bool m_authenticated = false;
  std::filesystem::path m_uploadDir;
  std::string m_baseURL = "http://showcase.flafy.dev";

  void onSubmissionLeft(const int submissionsLeft);
  void setToken(const std::optional<std::string> &token);
  void authenticate();

public:
  bool init();
  void tryUpload();
  std::filesystem::path getUploadDir() const;
  std::string getBaseURL() const;
  std::string getEndpoint(const std::string &endpoint) const;
  bool isAuthenticated();
  std::string getToken();

  static APIManager &get() {
    static APIManager instance;
    return instance;
  }
};
EOFcd ~/showcase && cat > src/managers/api_manager.hpp << 'EOF'
#pragma once
#include <filesystem>
#include <functional>
#include <optional>
#include <string>
#include <vector>

class APIManager {
protected:
  APIManager() = default;
  APIManager(const APIManager &) = delete;
  APIManager(APIManager &&) = delete;
  APIManager &operator=(const APIManager &) = delete;
  APIManager &operator=(APIManager &&) = delete;

  bool m_initialized = false;
  bool m_authenticated = false;
  std::filesystem::path m_uploadDir;
  std::string m_baseURL = "http://showcase.flafy.dev";

  void onSubmissionLeft(const int submissionsLeft);
  void setToken(const std::optional<std::string> &token);
  void authenticate();

public:
  bool init();
  void tryUpload();
  std::filesystem::path getUploadDir() const;
  std::string getBaseURL() const;
  std::string getEndpoint(const std::string &endpoint) const;
  bool isAuthenticated();
  std::string getToken();

  static APIManager &get() {
    static APIManager instance;
    return instance;
  }
};
