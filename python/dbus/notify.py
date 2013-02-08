#!/bin/python


import dbus

my_bus = dbus.SessionBus()
proxy = my_bus.get_object('org.freedesktop.Notifications', '/org/freedesktop/Notifications')
notifier = dbus.Interface(proxy, 'org.freedesktop.Notifications')
notifier.Notify('Digitro', 0, '', 'Harddisk em chamas', 'Parece que seu HD queimou', 'Test', {}, 5000)

