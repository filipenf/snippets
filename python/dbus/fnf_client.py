#!/bin/python

import dbus
bus = dbus . SessionBus ( )
helloservice = bus . get_object ( 'br.com.digitro.Test' , '/org/frankhale/helloservice' )
hello = helloservice . get_dbus_method ( 'hello' , 'org.frankhale.helloservice' )
print hello ( ) 
