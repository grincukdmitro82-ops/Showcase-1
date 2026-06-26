#include "authenticate.hpp"
#include "../managers/api_manager.hpp"

AuthenticateTask authenticateTask(const std::optional<std::string> token) {
  if (GJAccountManager::sharedState()->m_accountID == 0) {
    co_return Err("No GD account logged in.");
  }

  if (token.has_value() && !token->empty()) {
    web::WebRequest req = web::WebRequest();
    req.bodyString(token.value());
    req.timeout(std::chrono::seconds(5));

    auto response =
        co_await req.get(APIManager::get().getEndpoint("v3/checkToken"));
    int responseCode = response.code();
    if (responseCode == 200) {
      co_return Ok(token.value());
    } else if (responseCode != 401) {
      co_return Err("Unexpected response code from server.");
    }
  }

  // No valid token — return empty to signal unauthenticated state
  co_return Err("No valid token available. Please authenticate via the game.");
}
