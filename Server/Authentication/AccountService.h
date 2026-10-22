#pragma once

#include <string>
#include <optional>
#include <cstdint>

namespace Aethernal::Server
{
    struct AccountRecord
    {
        std::string AccountId;
        std::string CreatedAtUtc;
        bool IsActive = true;
    };

    class AccountService
    {
    public:
        virtual ~AccountService() = default;
        virtual std::optional<AccountRecord> FindAccountById(const std::string& accountId) = 0;
        virtual bool CreateAccount(const AccountRecord& account) = 0;
        virtual bool DisableAccount(const std::string& accountId) = 0;
    };
}
