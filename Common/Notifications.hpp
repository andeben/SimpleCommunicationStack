#ifndef NOTIFICATIONS_HPP
#define NOTIFICATIONS_HPP

#include <map>
#include <functional>

#include "NotificationSubscriberIf.hpp"

class Notifications {
public:
  Notifications();
  ~Notifications();
  void Subscribe(uint8_t aNotificationId, NotificationSubscriberIf* aSubscriber);
  void Notify(uint8_t aNotificationId);
private:
  std::map<uint8_t, NotificationSubscriberIf*> mSubscribers;

};

#endif //MESSAGE_ROUTER_HPP
