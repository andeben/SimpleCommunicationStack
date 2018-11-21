#ifndef NOTIFICATIONS_IF_HPP
#define NOTIFICATIONS_IF_HPP

#include <map>
#include <functional>

#include "NotificationSubscriberIf.hpp"

class NotificationsIf {
public:
  virtual ~NotificationsIf() {};
  virtual void Subscribe(uint8_t aNotificationId, NotificationSubscriberIf* aSubscriber) = 0;
  virtual void Notify(uint8_t aNotificationId) = 0;

};

#endif //NOTIFICATIONS_IF_HPP
