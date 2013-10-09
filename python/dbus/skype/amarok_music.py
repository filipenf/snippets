#!/bin/python

import dbus
import dbus.mainloop.glib
import gobject
import os.path

skypeInvoke = None

def trackChangeHandler(args):
    title = args['title']
    artist = args['artist']
    if artist and title:
        text = "%s: %s" % (artist, title)
    else:
        text = os.path.basename(args['location'])
    skypeInvoke("SET PROFILE RICH_MOOD_TEXT <SS type=\"music\">%s</SS> " % (text))

def main():
    global skypeInvoke
    dbus.mainloop.glib.DBusGMainLoop(set_as_default=True)
    bus = dbus . SessionBus ( )
    skypeService = bus.get_object('com.Skype.API', '/com/Skype')
    skypeInvoke = skypeService.get_dbus_method('Invoke', 'com.Skype.API')
    skypeInvoke('NAME Filipe')
    skypeInvoke('PROTOCOL 6')

    amarokService = bus.get_object('org.kde.amarok', '/Player')
    amarokService.connect_to_signal("TrackChange", trackChangeHandler)
    loop = gobject.MainLoop()
    loop.run()

if __name__ == '__main__':
    main()

