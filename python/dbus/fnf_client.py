#!/bin/python

import dbus
bus = dbus.SessionBus ( )
helloservice = bus.get_object ( 'br.com.filipenf.Test' , '/br/com/filipenf/Test' )
hello = helloservice.get_dbus_method ( 'hello' , 'br.com.filipenf.Test' )
print hello ( ) 
