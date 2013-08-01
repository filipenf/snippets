#!/bin/python

import dbus
import dbus.mainloop.glib
import gobject
import os.path
import subprocess

scrollState = False
callState = None
bus = None
callManager = None
objectManager = None

def isSFLRunning():
    global objectManager
    return objectManager.NameHasOwner("org.sflphone.SFLphone")

def checkConnection():
    global callManager
    if ( not isSFLRunning() ):
        print "checkConnection: not running"
        callManager = None
    else:
        print "checkConnection: running"
        callManager = bus.get_object('org.sflphone.SFLphone', '/org/sflphone/SFLphone/CallManager')
        callManager.connect_to_signal("incomingCall", incomingCall)
        callManager.connect_to_signal("callStateChanged", callStateChanged)
    return True

def switchScrollLock():
    global scrollState
    ringing = (callState == "RINGING" or callState == "INCOMING")
    if ( ringing and scrollState == False ):
        subprocess.call(["xset", "led", "3"])
    else:
        subprocess.call(["xset", "-led", "3"])
    scrollState = not scrollState
    return ringing

def incomingCall(accountID, callID, xfrom):
    global callState
    callState = "RINGING"
    gobject.timeout_add(200, switchScrollLock)

def callStateChanged(callId, state):
    global callState
    callState = state

def main():
    global objectManager
    global bus

    dbus.mainloop.glib.DBusGMainLoop(set_as_default=True)
    bus = dbus . SessionBus ( )
    objectManager = bus.get_object("org.freedesktop.DBus","/org/freedesktop/DBus/ObjectManager")

    checkConnection()

    gobject.timeout_add(5000, checkConnection)

    loop = gobject.MainLoop()
    loop.run()

if __name__ == '__main__':
    main()

