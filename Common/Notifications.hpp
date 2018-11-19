#ifndef NOTIFICATIONS_HPP
#define NOTIFICATIONS_HPP

#include <map>
#include <functional>

#include "NotificationsIf.hpp"


class Notifications {
public:
  Notifications();
  ~Notifications();
  void Subscribe(uint8_t aNotificationId, NotificationsIf* aSubscriber);
  void Notify(uint8_t aNotificationId);
private:
  std::map<uint8_t, NotificationsIf*> mSubscribers;

};

#endif //MESSAGE_ROUTER_HPP
