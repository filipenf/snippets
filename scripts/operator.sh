#!/bin/bash

NUMERO=$1

curl -s -d "phone_name=umts_sholes&system_version=2.3.7&system_name=Android&uniqueID=6aae892b2eapp_version=2.0.5&phone_numbers=$NUMERO" "portabilidade.mobihouse.com/check" |awk -F ':' '{print $2}'|sed 's@"@@g;s@}@@g'

