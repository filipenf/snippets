#!/bin/python

import dbus
import dbus.mainloop.glib
import gobject
import os.path
import subprocess

scrollState = False
callState = None

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
    dbus.mainloop.glib.DBusGMainLoop(set_as_default=True)
    bus = dbus . SessionBus ( )
    callManager = bus.get_object('org.sflphone.SFLphone', '/org/sflphone/SFLphone/CallManager')

    callManager.connect_to_signal("incomingCall", incomingCall)
    callManager.connect_to_signal("callStateChanged", callStateChanged)
    loop = gobject.MainLoop()
    loop.run()

if __name__ == '__main__':
    main()

