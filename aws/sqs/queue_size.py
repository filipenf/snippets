#!/usr/bin/env python

import boto.sqs
import time
from datetime import datetime
from tabulate import tabulate

conn = boto.sqs.connect_to_region("us-east-1")

queue_list = conn.get_all_queues()

header = [ queue.name for queue in queue_list ]
header.insert(0, "Date")
print ";".join(header)

while True:
    values = [ str(queue.count()) for queue in queue_list ]
    values.insert(0, str(datetime.now()))
    print ";".join(values)
    time.sleep(10)


