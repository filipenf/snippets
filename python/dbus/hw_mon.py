#!/bin/python

import dbus
import dbus.mainloop
from dbus.mainloop.glib import DBusGMainLoop
import gobject

class AsyncTest:

	def __init__(self):
		bus = dbus.SystemBus()
		obj = bus.get_object('org.freedesktop.Hal', '/org/freedesktop/Hal/Manager')
		hal = dbus.Interface(obj, 'org.freedesktop.Hal.Manager')
		hal.connect_to_signal('DeviceAdded', self.device_added)
		hal.connect_to_signal('DeviceRemoved', self.device_removed)
		hal.GetAllDevices(reply_handler=self.reply_handler, error_handler=self.error_handler)

	def reply_handler(self, devices):
		for device in devices:
			print device

	def error_handler(self, error):
		print 'Fatal error: '
		print error

	def device_removed(self, device):
		print ' device removed '
		print device

	def device_added(self, device):
		print ' device added '
		print device

if __name__ == '__main__':
	DBusGMainLoop(set_as_default=True)
	at = AsyncTest()
	mainloop = gobject.MainLoop()
	mainloop.run()	

