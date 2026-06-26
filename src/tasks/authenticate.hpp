#pragma once
#include "../includes/geode.hpp"
#include <Geode/Result.hpp>
#include <Geode/utils/web.hpp>
#include <optional>

using AuthenticateTask = Task<Result<std::string>, float>;

AuthenticateTask authenticateTask(const std::optional<std::string> token);
