#!/bin/bash
#test if server is allowing sslv3 connection

for host in "$@"; do
    echo | timeout 3 openssl s_client -connect $host >/dev/null 2>&1;
    if [[ $? != 0 ]]; then 
        echo "UNKNOWN: $host timeout or connection error"; 
    else
        echo | openssl s_client -connect $host:443 -ssl3 2>&1 | grep -qo "sslv3 alert handshake failure" && echo "OK: $host Not vulnerable" || echo "FAIL:  $host vulnerable; sslv3 connection accepted"; 
    fi
done
