#ifndef NOTIFICATIONS_IF_HPP
#define NOTIFICATIONS_IF_HPP

#include <map>
#include <functional>

class NotificationsIf {
public:
  virtual ~NotificationsIf() {};
  virtual void NotificationReceived(uint8_t aNotificationId);

};

#endif //NOTIFICATIONS_IF_HPP
