#!/bin/sh
echo "Athena�N�����܂��I"
echo "(c) 2003 I-Athena Project."
echo "I gonna show debug infomations,"
echo " because this is not release."
echo ""
echo "checking..."

if [ ! -f ./data.grf ]; then
    echo "data.grf��������܂���i��"
    exit 1;
fi
echo "data.grf�������܂����I"
if [ ! -x ./login2 ]; then
    echo "login2 does not exist, or can't run."
    echo "Stoped, Check your compile."
    exit 1;
fi

if [ ! -x ./char2 ]; then
    echo "char2 does not exist, or can't run."
    echo "Stoped, Check your compile."
    exit 1;
fi

if [ ! -x ./map2 ]; then
    echo "map2 does not exist, or can't run."
    echo "Stoped, Check your compile."
    exit 1;
fi
echo "Done."
echo "Looks good. Good Luck!"
./login2&
./char2 ./char_athena.cnf&
./map2 ./map_athena.cnf&
echo ""
echo "�A�e�i�@�������܁`���I"
