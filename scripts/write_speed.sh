#!/bin/bash
#use this script to check the disk writing speed

dir=$1

CMD_DU=""

du=`du -bs $dir | cut -f1`

while [ true ]; do
    date=`date`
    ndu=`du -bs $dir | cut -f1`
    rate=`expr $ndu - $du`    
    du=$ndu
    echo $date $rate
    sleep 1
done

