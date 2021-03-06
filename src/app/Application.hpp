#pragma once

#include "core/User.hpp"
#include "gui/GuildsModel.hpp"
#include "handlers/Authenticator.hpp"
#include "handlers/Requester.hpp"

#include <memory>

class QQmlContext;

class Application : public QObject
{
    // clang-format off
    Q_OBJECT
    Q_PROPERTY(bool guildModelVisible READ guildModelVisible NOTIFY guildsModelChanged)
    Q_PROPERTY(GuildsModel *guildsModel READ guildsModel NOTIFY guildsModelChanged)
    // clang-format on

  public:
    explicit Application(QQmlContext *ctx, QObject *parent = nullptr);

    bool guildModelVisible() const;
    GuildsModel *guildsModel() const;

    void loadSettings();

  signals:
    void loginSuccess();
    void guildsModelChanged();

  private slots:
    void handleLoginSuccess(const QString &token, const QJsonDocument &meInfo);
    void handleGuildsFinished(const QByteArray &data);

  private:
    bool m_guildModelVisible{ false };
    User m_user;

    Authenticator m_auth;
    Requester m_req;

    std::unique_ptr<GuildsModel> m_guildsModel;
};
