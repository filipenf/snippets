#!/bin/python

import dbus
bus = dbus . SessionBus ( )
skypeService = bus.get_object('com.Skype.API', '/com/Skype')
#hello = helloservice . get_dbus_method ( 'hello' , 'org.frankhale.helloservice' )

invoke = skypeService.get_dbus_method('Invoke', 'com.Skype.API')

print invoke('NAME Filipe')
print invoke('PROTOCOL 6')
print invoke('SEARCH MISSEDMESSAGES')

