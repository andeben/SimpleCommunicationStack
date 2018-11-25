#include "Notifications.hpp"

#include <functional>

Notifications::Notifications()
{
}

Notifications::~Notifications()
{
}

void Notifications::Notify(uint8_t aNotificationId)
{
  auto it = mSubscribers.find(aNotificationId);
  while (it != mSubscribers.end())
  {
    it->second->NotificationReceived(aNotificationId);
  }
}

void Notifications::Subscribe(uint8_t aNotificationId, NotificationSubscriberIf* aSubscriber)
{
  mSubscribers.emplace(aNotificationId, aSubscriber);
}
