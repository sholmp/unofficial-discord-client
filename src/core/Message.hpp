#pragma once

#include "Types.hpp"

#include <QDateTime>
#include <QJsonObject>

class Message
{
  public:
    void unmarshal(const QJsonObject &obj);

    enum Type {
        DEFAULT                                = 0,
        RECIPIENT_ADD                          = 1,
        RECIPIENT_REMOVE                       = 2,
        CALL                                   = 3,
        CHANNEL_NAME_CHANGE                    = 4,
        CHANNEL_ICON_CHANGE                    = 5,
        CHANNEL_PINNED_MESSAGE                 = 6,
        GUILD_MEMBER_JOIN                      = 7,
        USER_PREMIUM_GUILD_SUBSCRIPTION        = 8,
        USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_1 = 9,
        USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_2 = 10,
        USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_3 = 11,
        CHANNEL_FOLLOW_ADD                     = 12,
        GUILD_DISCOVERY_DISQUALIFIED           = 14,
        GUILD_DISCOVERY_REQUALIFIED            = 15,
        REPLY                                  = 19,
    };

    snowflake guildID() const;

    snowflake channelID() const;

    QDateTime timestamp() const;

    QString content() const;

    QString author() const;

  private:
    snowflake m_id;
    snowflake m_channelID;
    snowflake m_guildID;
    QString m_author;
    QString m_content;
    QDateTime m_timestamp;
    Type m_type;
};
