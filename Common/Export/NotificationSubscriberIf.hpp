#ifndef NOTIFICATION_SUBSCRIBER_IF_HPP
#define NOTIFICATION_SUBSCRIBER_IF_HPP

#include <map>
#include <functional>

class NotificationSubscriberIf {
public:
  virtual ~NotificationSubscriberIf() {};
  virtual void NotificationReceived(uint8_t aNotificationId);

};

#endif //NOTIFICATION_SUBSCRIBER_IF_HPP
