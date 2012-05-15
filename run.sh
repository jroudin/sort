#!/bin/bash

if [ $# -lt 1 ]
then
	echo "Usage: ./run.sh file";
	exit 1;
fi

cat $1 | sort > /tmp/offisort;
cat $1 | bin/sort > /tmp/mysort;
diff /tmp/offisort /tmp/mysort;
rm /tmp/offisort /tmp/mysort;
