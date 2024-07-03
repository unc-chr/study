#!/bin/bash

#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：sync.sh
#   Author：leekaihua
#   Date：20240701
#   Brife：
#
#================================================================


function delopy_libmytest {
    make libmytest
    sudo cp my_test.h /usr/local/include/lee/test/
    sudo cp libmytest.so /usr/local/mylib/
    sudo /sbin/ldconfig
}

function help {
    echo "attention: use depoly.sh like this"
    echo "sh/bash deploy.sh module";
}

module=$1
if [ -z "${module}" ];then
    help;
    exit;
fi
if [ "${module}" == "libmytest" ];then
    deploy_libmytest;
fi