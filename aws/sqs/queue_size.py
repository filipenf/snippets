#!/usr/bin/env python

import boto.sqs
import time

conn = boto.sqs.connect_to_region("us-east-1")

queue_list = conn.get_all_queues()

while True:
    for queue in queue_list:
        print "%30s => %d" % (queue.name, queue.count())
    time.sleep(10)


