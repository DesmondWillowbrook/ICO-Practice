#!/bin/bash
g++ secret-cow-code.cpp --define DEBUG; cat cowcode.in; ./a.out; cat cowcode.out
